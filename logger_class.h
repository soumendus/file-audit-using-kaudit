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
