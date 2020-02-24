CC=g++
#CFLAGS=-std=c++11 -Wall -pedantic -g -pthread
CFLAGS=-std=c++11 -Wall -g -pthread -llibev
SOURCES=logger_class.cpp daemon_class.cpp audit_class.cpp ev.cpp event_class.cpp auditmain_class.cpp
DEPS=system_headers.h logger_class.h daemon_class.h audit_class.h event_class.h libaudit.h errormsg.h config.h private.h gen_tables.h i386_tables.h x86_64_tables.h optab.h optabs.h ia64_tables.h actiontabs.h errtabs.h fieldtabs.h ppc_tables.h machinetabs.h ftypetabs.h flagtabs.h s390_table.h s390_tables.h ev_vars.h ev_wrap.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=auditdir

all: $(EXECUTABLE)
	@echo Make has finished.

$(EXECUTABLE): $(OBJECTS)
	$(CC)  $(OBJECTS) -o $@  -L. libaudit.so.1.0.0

.cpp.o:
	$(CC) $(CFLAGS) -c $*.cpp

clean: 
	$(RM) *.o *~ $(EXECUTABLE)
