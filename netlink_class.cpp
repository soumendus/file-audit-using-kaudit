// SPDX-License-Identifier: GPL-2.0
/*
 * netlink_class.cpp: File Monitoring and Auditing System netlink class source file
 *
 * Written by Soumendu Sekhar Satapathy, 23rd Feb 2020
 * satapathy.soumendu@gmail.com
 * 
 *
 */

#include "netlink_class.h"
#include "exception_class.h"

netlink_class::netlink_class()
{

}

void netlink_class::open_link()
{

	this->fd = audit_open();
	cout<<"Open link"<<endl;
	cout<<fd<<endl;

        if(this->fd < 0){
                throw exception_class("Failure in audit_open()");
        }

	audit_set_enabled(this->fd, 1);
}

int netlink_class::get_fd()
{
	return this->fd;
}

void netlink_class::add_directory_for_mon(vector<string>& dirs)
{
	this->no_dirs_configured = dirs.size();
	rule.resize(this->no_dirs_configured);

        // Add the Directory for Monitoring
        for(int i = 0; i < dirs.size(); i++) {
                rule[i] = new audit_rule_data();
                if(audit_add_watch_dir(AUDIT_DIR, &rule[i], dirs[i].c_str()) < 0) {
			throw exception_class("audit_add_watch_dir() failed");
                        syslog (LOG_ERR, "%s", dirs[i].c_str());
                }
		cout<<dirs[i]<<endl;

                // Add the desired rule
                audit_add_rule_data(this->fd, rule[i], AUDIT_FILTER_EXIT, AUDIT_ALWAYS);
        }

        audit_set_pid(this->fd, getpid(), WAIT_YES);

}

// Remove all the rules.
void netlink_class::delete_all_rules()
{
        for(int i = 0; i < this->no_dirs_configured; i++) {
                audit_delete_rule_data(this->fd, rule[i], AUDIT_FILTER_EXIT, AUDIT_ALWAYS);
        }

        for(int i = 0; i < this->no_dirs_configured; i++) {
                delete rule[i];
        }
}

void netlink_class::close_link()
{
	audit_close(this->fd);
}
