#include <iostream>
#include <string>
#include <sys/time.h>
#include <unistd.h>
#include <QtGui>

#include "alpm.h"
#include "callbacks.h"

#define UPDATE_SPEED_SEC 0.2f

CallBacks CbackReference;

CallBacks::CallBacks()
{
	answer = -1;
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
}

void CallBacks::cb_trans_conv(pmtransconv_t event, void *data1, void *data2,
                   void *data3, int *response)
{
	emit streamTransQuestion(event, data1, data2, data3);
	
	while(answer == -1)
		sleep(0.3);
	
	*response = answer;
	answer = -1;
}

void CallBacks::cb_trans_progress(pmtransprog_t event, const char *pkgname, int percent,
                   int howmany, int remain)
{
	float timediff;
	
	if(percent == 0) 
		timediff = get_update_timediff(1);
	else
		timediff = get_update_timediff(0);
	
	if(percent > 0 && percent < 100 && !timediff)
		return;
	
	emit streamTransProgress(event, pkgname, percent, howmany, remain);
}

void CallBacks::cb_dl_progress(const char *filename, int file_xfered, int file_total,
		int list_xfered, int list_total)
{
	emit streamTransDlProg(filename, file_xfered, file_total, list_xfered, list_total);
}

void CallBacks::cb_log(pmloglevel_t level, char *fmt, va_list args)
{
	
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
	CbackReference.cb_trans_conv(event,data1,data2,data3,response);
}

void cb_trans_evt(pmtransevt_t event, void *data1, void *data2)
{
	CbackReference.cb_trans_evt(event,data1,data2);
}
