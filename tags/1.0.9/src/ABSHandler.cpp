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

#include "ABSHandler.h"

#include <QDir>
#include <QDebug>
#include <QSettings>
#include <dirent.h>
#include <errno.h>

ABSHandler::ABSHandler()
{
}

ABSHandler::~ABSHandler()
{
}

QString ABSHandler::getABSPath(const QString &package)
{
	QDir absDir("/var/abs");
	absDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);

	int found = 0;
	QString absSource;

	QFileInfoList list = absDir.entryInfoList();

	for (int i = 0; i < list.size(); ++i)
	{
		QDir subAbsDir(list.at(i).absoluteFilePath());
		subAbsDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
		QFileInfoList subList = subAbsDir.entryInfoList();

		for (int j = 0; j < subList.size(); ++j)
		{
			qDebug() << subList.at(j).absoluteFilePath();
			if(!subList.at(j).baseName().compare(package))
			{
				found = 1;
				absSource = subList.at(j).absoluteFilePath();
				break;
			}
		}

		if(found == 1)
			break;
	}

	if(!found)
		return QString();

	qDebug() << "ABS Dir is " << absSource;

	return absSource;
}

bool ABSHandler::cleanBuildingEnvironment(const QString &package)
{
	QSettings *settings = new QSettings();

	QString path(settings->value("absbuilding/buildpath").toString());

	settings->deleteLater();

	if(!path.endsWith(QChar('/')))
		path.append(QChar('/'));

	path.append(package);

	rmrf(path.toAscii().data());

	return true;
}

bool ABSHandler::setUpBuildingEnvironment(const QString &package)
{
	QSettings *settings = new QSettings();

	QString path(settings->value("absbuilding/buildpath").toString());

	settings->deleteLater();

	if(!path.endsWith(QChar('/')))
		path.append(QChar('/'));

	path.append(package);

	QDir pathDir(path);
	if(pathDir.exists())
		cleanBuildingEnvironment(package);

	if(!pathDir.mkpath(path))
		return false;

	QString abspath(getABSPath(package));

	if(abspath.isEmpty())
	{
		qDebug() << "Couldn't find a matching ABS Dir!!";
		return false;
	}

	QDir absPDir(abspath);
	absPDir.setFilter(QDir::Files | QDir::Hidden | QDir::NoDotAndDotDot | QDir::NoSymLinks);

	QFileInfoList Plist = absPDir.entryInfoList();

	for (int i = 0; i < Plist.size(); ++i)
	{
		QString dest(path);
		if(!dest.endsWith(QChar('/')))
			dest.append(QChar('/'));
		dest.append(Plist.at(i).fileName());

		qDebug() << "Copying " << Plist.at(i).absoluteFilePath() << " to " << dest;

		if(!QFile::copy(Plist.at(i).absoluteFilePath(), dest))
		{
			return false;
		}
	}

	return true;
}

bool ABSHandler::cleanAllBuildingEnvironments()
{
	QSettings *settings = new QSettings();

	int ret;

	ret = rmrf(settings->value("absbuilding/buildpath").toString().toAscii().data());

	settings->deleteLater();

	if(ret == 0)
		return true;
	else
		return false;
}

QStringList ABSHandler::getMakeDepends(const QString &package)
{
	QStringList retList;

	retList.clear();

	QDir absDir("/var/abs");
	absDir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);

	QString absSource(ABSHandler::getABSPath(package));

	if(absSource.isEmpty())
		return retList;

	if(!absSource.endsWith(QChar('/')))
		absSource.append(QChar('/'));

	absSource.append("PKGBUILD");

	QFile fp(absSource);

	if(!fp.open(QIODevice::ReadOnly | QIODevice::Text))
		return retList;

	QTextStream in(&fp);

	while(!in.atEnd())
	{
		QString line = in.readLine();

		if(!line.startsWith("makedepends"))
			continue;

		QString testline(line);
		testline.remove(' ');

		while(true)
		{
			if(line.contains('('))
				line = line.split('(').at(1);

			foreach(const QString &rdep, line.split(QChar('\''), QString::SkipEmptyParts))
			{
				QString dep(rdep);

			    if(!dep.contains(')') && !dep.contains(' '))
				{
					if(dep.contains('>'))
						dep.truncate(dep.indexOf('>'));

					if(dep.contains('<'))
						dep.truncate(dep.indexOf('<'));

					if(dep.contains('='))
						dep.truncate(dep.indexOf('='));

					qDebug() << "Adding" << dep;

					retList.append(dep);
				}
			}

			if(testline.endsWith(')'))
				break;

			line = in.readLine();

			testline = line;
			testline.remove(' ');
		}

		break;
	}

	fp.close();

	return retList;
}

int ABSHandler::rmrf(const char *path)
{
	int errflag = 0;
	struct dirent *dp;
	DIR *dirp;

	if(!unlink(path))
		return(0);
	else
	{
		if(errno == ENOENT)
			return(0);
		else if(errno == EPERM) { }
		/* fallthrough */
		else if(errno == EISDIR) { }
		/* fallthrough */
		else if(errno == ENOTDIR)
			return(1);
		else
			/* not a directory */
			return(1);

		if((dirp = opendir(path)) == (DIR *)-1)
			return(1);
		for(dp = readdir(dirp); dp != NULL; dp = readdir(dirp))
		{
			if(dp->d_ino)
			{
				char name[4096];
				sprintf(name, "%s/%s", path, dp->d_name);
				if(strcmp(dp->d_name, "..") && strcmp(dp->d_name, "."))
					errflag += rmrf(name);
			}
		}

		closedir(dirp);
		if(rmdir(path))
			errflag++;

		return(errflag);
	}
}
