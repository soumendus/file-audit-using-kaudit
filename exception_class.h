#include "system_headers.h"

class exception_class : public std::exception
{
    std::string _msg;

public:
    exception_class(const std::string& msg);

    virtual const char* what(void);
};

