// SPDX-License-Identifier: GPL-2.0
/*
 * daemon_class.cpp: File Monitoring and Auditing System Daemoin class to
 * create a daemon.
 *
 * Written by Soumendu Sekhar Satapathy, 23rd Feb 2020
 * satapathy.soumendu@gmail.com
 * 
 *
 */

#include "daemon_class.h"
#include "exception_class.h"


daemon_class::daemon_class()
{
}

void daemon_class::create_daemon()
{
	pid_t pid;

	/* Fork off the parent process */
	pid = fork();

	if (pid < 0)
		throw exception_class("process id less than zero");

	/* Success: Let the parent terminate */
	if (pid > 0)
		exit(EXIT_SUCCESS);

	/* On success: The child process becomes session leader */
	if (setsid() < 0)
		throw exception_class("setsid less than zero");

	/* Catch, ignore and handle signals */
	//TODO: Implement a working signal handler */
	signal(SIGCHLD, SIG_IGN);
	signal(SIGHUP, SIG_IGN);

	/* Fork off for the second time*/
	pid = fork();

	if (pid < 0)
		throw exception_class("After second time process id less than zero");

	/* Success: Let the parent terminate */
	if (pid > 0)
		exit(EXIT_SUCCESS);

	/* Set new file permissions */
	umask(0);

	/* Change the working directory to the root directory */
	/* or another appropriated directory */
	chdir("/");

	/* Close all open file descriptors */
	int d;
	for (d = sysconf(_SC_OPEN_MAX); d >= 0; d--)
	{
		close (d);
	}

	/* Open the log file */
	openlog ("firstdaemon", LOG_PID, LOG_DAEMON);
}

void daemon_class::print_message(string& msg)
{
	syslog (LOG_NOTICE, "%s", msg.c_str());
}

