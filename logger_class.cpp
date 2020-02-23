// SPDX-License-Identifier: GPL-2.0
/*
 * logger_class.cpp: File Monitoring and Auditing System Logger class
 *
 * Written by Soumendu Sekhar Satapathy, 23rd Feb 2020
 * satapathy.soumendu@gmail.com
 * 
 *
 */

#include "logger_class.h"

logger_class::logger_class(string& path) 
{
	fout.open("/var/log/auditdir.log",ios::out|ios::app);
	if(!fout){
		cout<<"Unable to open the auditdir.log file for writing"<<endl;
		return;
	}

	this->path = path;
 }

void logger_class::log_to_file(struct stat statbuf, string& path) 
{
	fout <<"----------------------------------------------------------------------------------" << endl;
	fout <<"Information for: "<< path <<endl;
	fout <<"----------------------------------------------------------------------------------" << endl;
	fout <<"Last time the file was accessed" << " " << statbuf.st_atime << endl;
	fout <<"Last time the file permission was changed" << " " << statbuf.st_ctime << endl;

	if(statbuf.st_atime == statbuf.st_mtime){
		fout <<"Last time the file was accessed for WRITE" << " " << statbuf.st_mtime << endl;
	}
	else {
		fout <<"Last time the file was accessed for READ" << " " << statbuf.st_mtime << endl;
	}

	fout <<"User ID" << " " << statbuf.st_uid << endl;
	fout <<"Group ID" << " " << statbuf.st_gid << endl;
	fout <<"-----------------------------------------------------------------------------------" << endl;
}
