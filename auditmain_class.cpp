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


/* Global vars */
static int fd = -1;
static int list_requested = 0;
static int add = AUDIT_FILTER_UNSET, del = AUDIT_FILTER_UNSET, action = -1;
static int exclude = 0;
static int multiple = 0;
static struct audit_rule_data *rule_new = NULL;
#if 0
static struct auditd_reply_list *rep = NULL;
#endif

ofstream fout;

void get_dir(ifstream& f, vector<string>& dirs)
{
	string next;

	while(getline(f,next)){
		dirs.push_back(next);
	}
}

void audit_handler(struct ev_loop *loop, struct ev_io *io, int revents)
{
    struct audit_reply reply;

    time_t timetoday;

    cout<<"monitoring directories"<<endl;
    audit_get_reply(fd, &reply, GET_REPLY_NONBLOCKING, 0);

    if (reply.type != AUDIT_EOE &&
        reply.type != AUDIT_PROCTITLE)
    {
        char *buf = new char[MAX_AUDIT_MESSAGE_LENGTH];
        time(&timetoday);

        snprintf(buf,
                 MAX_AUDIT_MESSAGE_LENGTH,
                 "Type=%s Message=%.*s Date=%s",
                 audit_msg_type_to_name(reply.type),
                 reply.len,
                 reply.message, 
		 asctime(localtime(&timetoday)));

        printf("EVENT: %s\n", buf);
    	fout << buf;

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

	fin.open("/etc/auditdir.conf", ios::in);

	if(!fin){
		cout<<"Unable to read the auditdir.conf file"<<endl;
		return -1;
	}

    	fout.open("/var/log/auditdir.log", ios::out | ios::app);

     	if(!fout) {
		cout<<"Unable to open file for logging file audit data"<<endl;
		return -1;
	}

	get_dir(fin, dirs);

	audit_class aobj(dirs);

	aobj.collect_files();
        all_files = aobj.get_all_files_in_all_dir();

#if 0
	// Create an object of the Daemon class.
	daemon_class dobj;

	// Create Daemon
	dobj.create_daemon();

	string msg("Directory Monitoring Daemon Started.");

	// Print Message
	dobj.print_message(msg);
#endif

	fd = audit_open();
	audit_set_enabled(fd, 1);

	struct audit_rule_data *rule[dirs.size()]; 
	for(int i = 0; i < dirs.size(); i++) {
		cout<<"Adding directory"<<" "<< dirs[i] <<" "<<"for monitoring"<<endl;
		rule[i] = new audit_rule_data();
		if(audit_add_watch_dir(AUDIT_DIR, &rule[i], dirs[i].c_str()) < 0) {
			cout<<"Unable to add directory"<<" "<< dirs[i] <<" " <<"for monitoring"<<endl;
		}
		audit_add_rule_data(fd, rule[i], AUDIT_FILTER_EXIT, AUDIT_ALWAYS);

	}

	struct ev_io mon;

    	audit_set_pid(fd, getpid(), WAIT_YES);

    	struct ev_loop *loop = ev_default_loop(EVFLAG_NOENV);

	ev_io_init(&mon, audit_handler, fd, EV_READ);
	ev_io_start(loop, &mon);

	cout<<"Before call to event loop"<<endl;

	rep = (struct audit_reply*)malloc(sizeof(struct audit_reply));

	ev_loop(loop, 0);

	// Remove all the rules.
	for(int i = 0; i < dirs.size(); i++) {
		audit_delete_rule_data(fd, rule[i], AUDIT_FILTER_EXIT, AUDIT_ALWAYS);
	}

	audit_close(fd);

	string mterm("Directory Monitoring Daemon Terminated");

#if 0
	dobj.print_message(mterm);
#endif


	closelog();

	return EXIT_SUCCESS;
}
