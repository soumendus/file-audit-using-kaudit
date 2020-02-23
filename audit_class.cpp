// SPDX-License-Identifier: GPL-2.0
/*
 * auditd_class.cpp: File Monitoring and Auditing System audit class
 *
 * Written by Soumendu Sekhar Satapathy, 23rd Feb 2020
 * satapathy.soumendu@gmail.com
 * 
 *
 */

#include "audit_class.h"
#include "logger_class.h"

audit_class::audit_class(string& path)
{
	cout<<"constructor of audit_class"<<endl;
	abs_dir_path = path;
}

audit_class::audit_class(vector<string>& fpaths)
{
	cout<<"constructor of audit_class"<<endl;
	for(int i = 0; i < fpaths.size(); i++)
	{
		file_paths.push_back(fpaths[i]);
	}
}

string audit_class::get_main_dir_path()
{
	return abs_dir_path;
}

void audit_class::create_in_mem_ds()
{
	for(int i = 0; i < file_paths.size(); i++)
	{
		log_dir_access(abs_dir_path,false);
	}
}

void audit_class::for_all_dir_paths()
{
	for(int i = 0; i < file_paths.size(); i++)
	{
		log_dir_access(file_paths[i],true);
	}
}

void audit_class::collect_files()
{
	for(int i = 0; i < file_paths.size(); i++) {
		recur_all_files_in_dir(file_paths[i]);
	}
}

vector<string> audit_class::get_all_files_in_all_dir()
{
	return all_files_in_all_dirs; 

}

void audit_class::recur_all_files_in_dir(string path)
{
	DIR *dp;
	struct dirent *dirp;
	struct stat statbuf;

	if((dp  = opendir(path.c_str())) == NULL) {
		if(stat(path.c_str(),&statbuf) < 0)
			return; // TODO: Throw Exception

		return;
	}

	while ((dirp = readdir(dp)) != NULL ) {
		if(strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
			continue;

		string fullpath;
                fullpath = fullpath + path;
                fullpath = fullpath + "/";
                fullpath = fullpath + dirp->d_name;

		all_files_in_all_dirs.push_back(fullpath);

                recur_all_files_in_dir(fullpath);
         }
         closedir(dp);
}

void audit_class::log_dir_access(string path, bool mode)
{
	DIR *dp;
	struct dirent *dirp;
	struct stat statbuf;

	if((dp  = opendir(path.c_str())) == NULL) {
		if(mode)
			write_to_text_file(path);
		else {
			if(stat(path.c_str(),&statbuf) < 0)
				return; // TODO: Throw Exception

			h_file[path] = statbuf.st_atime;
		}

		return;
	}

	while ((dirp = readdir(dp)) != NULL ) {
		if(strcmp(dirp->d_name, ".") == 0 || strcmp(dirp->d_name, "..") == 0)
			continue;

		string fullpath;
                fullpath = fullpath + path;
                fullpath = fullpath + "/";
                fullpath = fullpath + dirp->d_name;

                log_dir_access(fullpath,true);
         }
         closedir(dp);
}

void audit_class::write_to_text_file(string path)
{
	struct stat statbuf;
	ofstream fout;

	if(stat(path.c_str(),&statbuf) < 0)
		return;

	logger_class lobj(path);

	// Timestamp/File Permission change time/WRITE or READ/User ID/Group ID
	if (S_ISDIR(statbuf.st_mode) == 0) {
		if(h_file.find(path) == h_file.end())
		{
                	lobj.log_to_file(statbuf,path);
                	h_file[path] = statbuf.st_atime;
                }
                else
                {
                	if(h_file[path] != statbuf.st_atime) {

                        	lobj.log_to_file(statbuf,path);
                                h_file[path] = statbuf.st_atime;
                        }
                                
		}
 	}       

}
