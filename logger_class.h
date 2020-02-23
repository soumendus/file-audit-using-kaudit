// SPDX-License-Identifier: GPL-2.0
/*
 * logger_class.h: File Monitoring and Auditing System logger class header file.
 *
 * Written by Soumendu Sekhar Satapathy, 23rd Feb 2020
 * satapathy.soumendu@gmail.com
 * 
 *
 */

#include "system_headers.h"

class logger_class
{
        private:
                ofstream fout;
                struct stat statbuf;
                string path;

        public:
                logger_class(string& path);

                void log_to_file(struct stat statbuf, string& path);
};
