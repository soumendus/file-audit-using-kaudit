#include "exception_class.h"

exception_class::exception_class(const std::string& msg) : _msg(msg)
{
}

const char* exception_class::what()
{
	return _msg.c_str();
}

