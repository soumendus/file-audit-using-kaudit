// SPDX-License-Identifier: GPL-2.0
/*
 * event_class.cpp: File Monitoring and Auditing System Event class source file
 *
 * Written by Soumendu Sekhar Satapathy, 23rd Feb 2020
 * satapathy.soumendu@gmail.com
 * 
 *
 */

#include "event_class.h"

event_class::event_class(int fd, void (*audit_handler)(struct ev_loop *loop, struct ev_io *io, int revents))
{
	struct ev_io m;

	struct ev_loop *l = ev_default_loop(EVFLAG_NOENV);

	this->mon = m;
	this->loop = l;
	this->fd = fd;
	this->audit_handler = audit_handler;
}

void event_class::event_init()
{
	ev_io_init(&mon, audit_handler, fd, EV_READ);
}

void event_class::event_start()
{
	ev_io_start(loop, &mon);
}

void event_class::event_loop()
{
	ev_loop(loop, 0);
}

