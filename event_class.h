// SPDX-License-Identifier: GPL-2.0
/*
 * event_class.h: File Monitoring and Auditing System event class header file.
 *
 * Written by Soumendu Sekhar Satapathy, 23rd Feb 2020
 * satapathy.soumendu@gmail.com
 * 
 *
 */

#include "system_headers.h"

class event_class
{
	private:
		struct ev_io mon;
		struct ev_loop *loop;
		int fd;
		void (*audit_handler)(struct ev_loop *loop, struct ev_io *io, int revents);

	public:
		event_class(int fd, void (*audit_handler)(struct ev_loop *loop, struct ev_io *io, int revents));

		void event_init(void);
		void event_start();
		void event_loop();

};
