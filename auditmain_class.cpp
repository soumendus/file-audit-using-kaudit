// SPDX-License-Identifier: GPL-2.0
/*
 * auditmain_class.cpp: File Monitoring and Auditing System main source file
 *
 * Written by Soumendu Sekhar Satapathy, 23rd Feb 2020
 * satapathy.soumendu@gmail.com
 * 
 *
 */

#include "system_headers.h"
#include "audit_class.h"
#include "logger_class.h"
#include "daemon_class.h"
#include "event_class.h"
#include "exception_class.h"
#include "netlink_class.h"


// Initialize the instance variable of the Singleton netlink_link class 
netlink_class *netlink_class::instance = 0;

// Create a object of netlink_class Class.
netlink_class *pnet_obj = pnet_obj->get_instance();
 
// Create a object to write to the /var/log/auditdir.log TEXT file
ofstream fout;

// Audit function handler declaration 
typedef void (*f_audit_handler)(struct ev_loop *loop, struct ev_io *io, int revents);

// Read all the directory with full paths from the file to the vector 
// of strings-> dirs.
void get_dir(ifstream& f, vector<string>& dirs)
{
	string next;

	// Do some parsing of the /etc/auditdir.conf file.
	while(getline(f,next)){
		if(next == "")
			throw exception_class("Remove Invalid new Line in conf file");
		if(next[0] != '/')
			throw exception_class("Remove Invalid directory name in conf file");

		int spaces = std::count_if(next.begin(), next.end(),
                           [](unsigned char c){ return std::isspace(c); });
		if(spaces)
			throw exception_class("Remove Invalid space in directory name in conf file");

		dirs.push_back(next);
	}
}

// Convert char* to C++ string obj.
string convert_to_string_obj(char* a, int size)
{
	int i;
	string s = "";

	for (i = 0; i < size; i++) {
		s = s + a[i];
	}

	return s;
}

// This is the audit handler which handles events sent from Kernel
void audit_handler(struct ev_loop *loop, struct ev_io *io, int revents)
{
	struct audit_reply reply;

	time_t timetoday;
	string print_str;

	audit_get_reply(pnet_obj->get_fd(), &reply, GET_REPLY_NONBLOCKING, 0);

	if (reply.type == AUDIT_SYSCALL ||
		reply.type == AUDIT_PATH || reply.type == AUDIT_CWD)
	{
		char *buf = new char[MAX_AUDIT_MESSAGE_LENGTH];
		time(&timetoday);

		snprintf(buf,
			MAX_AUDIT_MESSAGE_LENGTH,
			"FMAS::Type=%s Message=%.*s Date=%s",
			audit_msg_type_to_name(reply.type),
			reply.len,
			reply.message, 
			asctime(localtime(&timetoday)));
	
		//Convert char* to string object
		string mstr = convert_to_string_obj(buf,strlen(buf));

		// Write string to the file (/var/log/auditdir.log)
		fout << mstr;

		// Also Log to syslog
		syslog (LOG_NOTICE, "%s", buf);

	}
}

int main()
{
	ifstream fin;
	vector<string> dirs;
	f_audit_handler f_ah = audit_handler;

	try {
		// Create an object of the Daemon class.
		daemon_class dobj;

		// Create Daemon
		dobj.create_daemon();

		// Print Message
		string msg("File Auditing and Monitoring Daemon Started.");

		fin.open("/etc/auditdir.conf", ios::in);
    		fout.open("/var/log/auditdir.log", ios::out | ios::app);

		// Get all the directories configured in /etc/auditdir.conf to Monitor
		get_dir(fin, dirs);

		// Open Link
		pnet_obj->open_link();

		// Add Directory for monitoring.
		pnet_obj->add_directory_for_mon(dirs);

		// Create an object of the Event class
		event_class ev_obj(pnet_obj->get_fd(),f_ah);

		// Initialize event
		ev_obj.event_init();

		// Start Event
		ev_obj.event_start();

		// Wait for Events
		ev_obj.event_loop();

	}
	catch (std::ifstream::failure& e) {
		string msg(e.what());
		syslog (LOG_ERR, "%s", "Exception opening /etc/auditdir.conf");

		return EXIT_FAILURE;
  	}
	catch (std::ofstream::failure& e) {
		string msg(e.what());
		syslog (LOG_ERR, "%s", msg.c_str());

		// Close the CONF file
		fin.close();

		return EXIT_FAILURE;
  	}
	catch (exception_class& e) {
		string msg(e.what());
		syslog (LOG_ERR, "%s", msg.c_str());

		// Close the CONF file
		fin.close();

		// Close the LOG file
		fout.close();

		// Delete all rules and free memory.
		pnet_obj->delete_all_rules();

		return EXIT_FAILURE;
  	}
	catch (...) {
		string msg("Exception");
		syslog (LOG_ERR, "%s", msg.c_str());

		return EXIT_FAILURE;
  	}

	// Close the CONF file
	fin.close();

	// Close the LOG file
	fout.close();

	// Delete all rules and free memory.
	pnet_obj->delete_all_rules();

	return EXIT_SUCCESS;
}
