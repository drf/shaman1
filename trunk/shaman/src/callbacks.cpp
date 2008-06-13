/***************************************************************************
 *   Copyright (C) 2008 by Dario Freddi                                    *
 *   drf54321@yahoo.it                                                     *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.          *
 ***************************************************************************/
#include "callbacks.h"

#include <iostream>
#include <string>
#include <unistd.h>
#include <QMessageBox>
#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>
#include <QDebug>

#include "alpm.h"

#define UPDATE_SPEED_SEC 0.2f

CallBacks CbackReference;
QMutex mutex;
QWaitCondition wCond;

CallBacks::CallBacks()
{
	answer = -1;
	onDl = 1;
}

CallBacks::~CallBacks()
{

}

float CallBacks::get_update_timediff(int first_call)
{
	float retval = 0.0;
	static struct timeval last_time = {0, 0};

	/* on first call, simply set the last time and return */
	if(first_call) {
		gettimeofday(&last_time, NULL);
	} else {
		struct timeval this_time;
		float diff_sec, diff_usec;

		gettimeofday(&this_time, NULL);
		diff_sec = this_time.tv_sec - last_time.tv_sec;
		diff_usec = this_time.tv_usec - last_time.tv_usec;

		retval = diff_sec + (diff_usec / 1000000.0);

		/* return 0 and do not update last_time if interval was too short */
		if(retval < UPDATE_SPEED_SEC) {
			retval = 0.0;
		} else {
			last_time = this_time;
			/* printf("\nupdate retval: %f\n", retval); DEBUG*/
		}
	}

	return(retval);
}

void CallBacks::cb_trans_evt(pmtransevt_t event, void *data1, void *data2)
{
	emit streamTransEvent(event, data1, data2);
	qDebug() << "Alpm Thread Waiting.";
	wCond.wait(&mutex);
	qDebug() << "Alpm Thread awake.";
}

void CallBacks::cb_trans_conv(pmtransconv_t event, void *data1, void *data2,
		void *data3, int *response)
{
	/* This can become a HUGE problem. libalpm implementation
	 * here sucks (really?) as it doesn't consider anything
	 * but pacman. Obviously we can't freeze our process in this
	 * function, alternatives could be moving the function to
	 * a different thread and lock it, or implement a QTimer here.
	 * But what makes everything impossible here? Simple: we don't
	 * have a caller, so both the solution are useless! The only thing
	 * we can actually do is having **ALWAYS** the handler on
	 * a separate thread and really block the process here until somebody gets
	 * an answer. libalpm sucks. Really.
	 */
	
	qDebug() << "Alpm is asking a question.";
	
	QMutexLocker lock(&mutex);
	QString message;
	
	switch(event) 
	{
	case PM_TRANS_CONV_INSTALL_IGNOREPKG:
		if(data2) 
			/* TODO we take this route based on data2 being not null? WTF (you suck)*/
			message = QString(tr("%1 requires installing %2 from IgnorePkg/IgnoreGroup.\n Install anyway?")).arg(alpm_pkg_get_name((pmpkg_t *)data1)).
					arg(alpm_pkg_get_name((pmpkg_t *)data2));
		else
			message = QString(tr("%1 is in IgnorePkg/IgnoreGroup.\n Install anyway?")).arg(alpm_pkg_get_name((pmpkg_t *)data1));

		break;
	case PM_TRANS_CONV_REMOVE_HOLDPKG:
		message = QString(tr("%1 is designated as a HoldPkg.\n Remove anyway?")).arg(alpm_pkg_get_name((pmpkg_t *)data1));
		break;
	case PM_TRANS_CONV_REPLACE_PKG:
		message = QString(tr("Replace %1 with %2/%3?")).arg(alpm_pkg_get_name((pmpkg_t *)data1)).
				arg((char *)data3).arg(alpm_pkg_get_name((pmpkg_t *)data2));
		break;
	case PM_TRANS_CONV_CONFLICT_PKG:
		message = QString(tr("%1 conflicts with %2.\nRemove %3?")).arg((char *)data1).
				arg((char *)data2).arg((char *)data2);
		break;
	case PM_TRANS_CONV_LOCAL_NEWER:
		message = QString(tr("%1-%2: local version is newer.\nUpgrade anyway?")).arg(alpm_pkg_get_name((pmpkg_t *)data1)).
				arg(alpm_pkg_get_version((pmpkg_t *)data1));
		break;
	case PM_TRANS_CONV_CORRUPTED_PKG:
		message = QString(tr("File %1 is corrupted.\nDo you want to delete it?")).arg((char *)data1);
		break;
	}
	
	emit questionStreamed(message);
	
	qDebug() << "Question Streamed, Alpm Thread waiting.";
	
	wCond.wait(&mutex);
	
	qDebug() << "Alpm Thread awake, committing answer.";
	
	*response = answer;
	
	return;

}

void CallBacks::cb_trans_progress(pmtransprog_t event, const char *pkgname, int percent,
		int howmany, int remain)
{
	float timediff = 0.0;

	if(percent == 0) 
	{
		gettimeofday(&initial_time, NULL);
		timediff = get_update_timediff(1);
	}
	else
	{
		timediff = get_update_timediff(0);

		if(timediff < UPDATE_SPEED_SEC) 
			return;
	}

	if(percent > 0 && percent < 100 && !timediff)
		return;

	emit streamTransProgress(event, (char *)pkgname, percent, howmany, remain);
}

void CallBacks::cb_dl_progress(const char *filename, int file_xfered, int file_total,
		int list_xfered, int list_total)
{
	float timediff = 0.0;
	float rate_f = 0.0, eta_s_f = 0.0;
	float rate_l = 0.0, eta_s_l = 0.0;

	if(onDl == 0)
	{
		xfered_total = 0;
		rate_total = 0.0;
		onDl = 1;
	}

	if(file_xfered == 0)
	{
		gettimeofday(&initial_time, NULL);
		timediff = get_update_timediff(1);
		xfered_last = 0;
		rate_last = 0.0;
	}
	else
	{
		timediff = get_update_timediff(0);

		if(timediff < UPDATE_SPEED_SEC) 
		{
			/* return if the calling interval was too short */
			return;
		}
		rate_f = (file_xfered - xfered_last) / (timediff * 1024.0);
		/* average rate to reduce jumpiness */
		rate_f = (rate_f + 2*rate_last) / 3;
		eta_s_f = (file_total - file_xfered) / (rate_f * 1024.0);

		rate_l = (list_xfered - xfered_total) / (timediff * 1024.0);
		/* average rate to reduce jumpiness */
		rate_l = (rate_l + 2*rate_total) / 3;
		eta_s_l = (list_total - list_xfered) / (rate_l * 1024.0);

		rate_last = rate_f;
		xfered_last = file_xfered;
		rate_total = rate_l;
		xfered_total = list_xfered;
	}
	
	int fx = file_xfered * 100;
	int lx = list_xfered * 100;
	
	int filePercent = fx / file_total;
	int listPercent = lx / list_total;
	
	emit streamTransDlProg((char *)filename, file_xfered, file_total, (int)rate_f,
			list_xfered, list_total, (int)rate_l);
	emit streamTransDlProg(QString((char *)filename), filePercent, 
			rate_f, listPercent, rate_l);
}

void CallBacks::cb_log(pmloglevel_t level, char *fmt, va_list args)
{
	if(!strlen(fmt)) {
		return;
	}

	char *string = NULL;
	if(pm_vasprintf(&string, level, fmt, args) == -1)
		return;
	
	if(string != NULL) 
	{
		QString msg(string);
		emit logMsgStreamed(msg);
	}
}

/* Now the real suckness is coming... */

void cb_dl_progress(const char *filename, int file_xfered, int file_total,
		int list_xfered, int list_total)
{
	CbackReference.cb_dl_progress(filename, file_xfered, file_total,
			list_xfered, list_total);
}

void cb_trans_progress(pmtransprog_t event, const char *pkgname, int percent,
		int howmany, int remain)
{
	CbackReference.cb_trans_progress(event,pkgname,percent,howmany,remain);
}

void cb_trans_conv(pmtransconv_t event, void *data1, void *data2,
		void *data3, int *response)
{
	qDebug() << "Question Event Triggered";
	CbackReference.cb_trans_conv(event,data1,data2,data3,response);
}

void cb_trans_evt(pmtransevt_t event, void *data1, void *data2)
{
	QMutexLocker lock(&mutex);
	qDebug() << "Received Event Callback";
	CbackReference.cb_trans_evt(event,data1,data2);
}

void cb_log(pmloglevel_t level, char *fmt, va_list args)
{
	CbackReference.cb_log(level, fmt, args);
}

int pm_vasprintf(char **string, pmloglevel_t level, const char *format, va_list args)
{
	int ret = 0;
	char *msg = NULL;

	/* if current logmask does not overlap with level, do not print msg */

	/* print the message using va_arg list */
	ret = vasprintf(&msg, format, args);

	/* print a prefix to the message */
	switch(level) 
	{
		case PM_LOG_DEBUG:
			return -1;
			break;
		case PM_LOG_ERROR:
			asprintf(string, "error: %s", msg);
			break;
		case PM_LOG_WARNING:
			asprintf(string, "warning: %s", msg);
			break;
		case PM_LOG_FUNCTION:
			return -1;
			break;
		default:
			break;
	}
	
	free(msg);

	return(ret);
}
