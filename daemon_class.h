#include "system_headers.h"

class daemon_class
{
public:
        daemon_class(void);

        static void create_daemon(void);
	void print_message(string& msg);
};

