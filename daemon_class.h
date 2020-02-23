// SPDX-License-Identifier: GPL-2.0
/*
 * daemon_class.h: File Monitoring and Auditing System daemon class header file.
 *
 * Written by Soumendu Sekhar Satapathy, 23rd Feb 2020
 * satapathy.soumendu@gmail.com
 * 
 *
 */

#include "system_headers.h"

class daemon_class
{
public:
        daemon_class(void);

        static void create_daemon(void);
	void print_message(string& msg);
};

