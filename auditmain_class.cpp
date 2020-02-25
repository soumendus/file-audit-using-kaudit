// SPDX-License-Identifier: GPL-2.0
/*
 * auditdir.cpp: File Monitoring and Auditing System main source file
 *
 * Written by Soumendu Sekhar Satapathy, 23rd Feb 2020
 * satapathy.soumendu@gmail.com
 * 
 *
 */

#define MONITOR_INTERVAL 1

#include "system_headers.h"
#include "audit_class.h"
#include "logger_class.h"
#include "daemon_class.h"
#include "event_class.h"


/* Global vars */
static int fd = -1;

ofstream fout;

// Audit function handler declaration 
typedef void (*f_audit_handler)(struct ev_loop *loop, struct ev_io *io, int revents);

// Read all the directory with full paths from the file to the vector 
// of strings-> dirs.
void get_dir(ifstream& f, vector<string>& dirs)
{
	string next;

	//TODO: Invoke Parser class for Parsing and validation

	while(getline(f,next)){
		dirs.push_back(next);
	}
}

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

    cout<<"monitoring directories"<<endl;
    audit_get_reply(fd, &reply, GET_REPLY_NONBLOCKING, 0);

#if 0
    if (reply.type != AUDIT_EOE &&
        reply.type != AUDIT_PROCTITLE)
#endif
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

	string mstr = convert_to_string_obj(buf,strlen(buf));
	fout << mstr;

	//TODO: Invoke Parser class for Parsing the Message string
	//TODO: Invoke Logger class for loggin into a file.
#if 0
	syslog (LOG_NOTICE, "%s", buf);
#endif

    }
}

int main()
{
	ifstream fin;
	vector<string> dirs;
	vector<string> all_files;
	vector<audit_class> a_objs;
	struct audit_reply *rep;
	int rc = 0;
	f_audit_handler f_ah = audit_handler;

	fin.open("/etc/auditdir.conf", ios::in);

	if(!fin){
		cout<<"Unable to read the auditdir.conf file"<<endl;
		return EXIT_FAILURE;
	}

    	fout.open("/var/log/auditdir.log", ios::out | ios::app);

     	if(!fout) {
		cout<<"Unable to open file for logging file audit data"<<endl;
		return EXIT_FAILURE;
	}

	//TODO: Invoke Parser class for Parsing the Message string
	get_dir(fin, dirs);

#if 0
	//TODO: Comprehensive Exception Handling
	try {
		// Create an object of the Daemon class.
		daemon_class dobj;

		// Create Daemon
		dobj.create_daemon();

		string msg("File Auding and Monitoring Daemon Started.");

		// Print Message
		dobj.print_message(msg);
	}
	catch(std::exception& e) {
		syslog (LOG_ERR, "%s", e.what());
		return EXIT_FAILURE;
    	}
#endif

	fd = audit_open();

	if(fd < 0){
		return EXIT_FAILURE;
	}

	// Enable the Auditing
	audit_set_enabled(fd, 1);

	// Declare a list of rule pointers
	struct audit_rule_data *rule[dirs.size()]; 

	// Add the Directory for Monitoring
	for(int i = 0; i < dirs.size(); i++) {
		rule[i] = new audit_rule_data();
		if(audit_add_watch_dir(AUDIT_DIR, &rule[i], dirs[i].c_str()) < 0) {
			syslog (LOG_ERR, "%s", dirs[i].c_str());
		}

		// Add the desired rule
		audit_add_rule_data(fd, rule[i], AUDIT_FILTER_EXIT, AUDIT_ALWAYS);

	}

    	audit_set_pid(fd, getpid(), WAIT_YES);

	//TODO: Comprehensive Exception Handling
	try {

		// Create an object of the Event class
		event_class ev_obj(fd,f_ah);

		// Initialize event
		ev_obj.event_init();

		// Start Event
		ev_obj.event_start();

		// Wait for Events
		ev_obj.event_loop();
	}
	catch(std::exception& e) {
		syslog (LOG_ERR, "%s", e.what());
		return EXIT_FAILURE;
    	}

	// Remove all the rules.
	for(int i = 0; i < dirs.size(); i++) {
		audit_delete_rule_data(fd, rule[i], AUDIT_FILTER_EXIT, AUDIT_ALWAYS);
	}

	for(int i = 0; i < dirs.size(); i++) {
		delete rule[i];
	}

	// Close the Auditing system
	audit_close(fd);

#if 0
	string mterm("File Auditing and Monitoring Daemon Terminated");

	dobj.print_message(mterm);
#endif

	closelog();

	return EXIT_SUCCESS;
}
