// SPDX-License-Identifier: GPL-2.0
/*
 * netlink_class.h: File Monitoring and Auditing System netlink class header file.
 *
 * Written by Soumendu Sekhar Satapathy, 23rd Feb 2020
 * satapathy.soumendu@gmail.com
 * 
 *
 */

#include "system_headers.h"

#include <iostream>

using namespace std;

class netlink_class
{
	private:
		int fd;
		int no_dirs_configured;
		vector<struct audit_rule_data*> rule;
   		static netlink_class *instance;

		// Declare the Constructor in the private
		netlink_class(void);

	public:
		static netlink_class *get_instance() {
			if (!instance)
				instance = new netlink_class;

			return instance;
		}

		void open_link(void);
		int get_fd(void);
		void add_directory_for_mon(vector<string>& dirs);
		void delete_all_rules();
		void close_link(void);
};
