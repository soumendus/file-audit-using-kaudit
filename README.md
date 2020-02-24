## FMAS: FILE MONITORING AND AUDITING SOFTWARE


# PROBLEM
Create file monitoring software that will log file access to configured directories on the system.

# Requirements
    • Software must be easily installed and configured
    • Software must monitor configured directories for file access 
        ◦ Auditing must run from OS startup to shutdown
        ◦ Audit must be written to text file on local system
        ◦ Text file must contain 
            ▪ Timestamp
            ▪ User
            ▪ Process ID
            ▪ Access Type
            
  # Solution
  There can be many ways to solve this problem. I developed in two methods. Here I am also sharing more methods to solve this problem.
  
  1) I have developed this Software (FMAS) using C++ language and this application leverages the Linux Kernel Audit daemon. This FMAS software registers rules with the Linux Kernel for directory monitoring. These directory will be specified by user with full path, in the file /etc/auditdir.conf. Whenever any activity happens within the directory, by some user who logged into the system either remotely or locally, events are sent by the Linux kernel which are caught by the event class of FMAS.
  and invokes the handler to log to the syslog :- /var/log/syslog. Kernel <--> Userspace communication happens via NETLINK. 
  We can view the LOG by doing a "vi" to the /var/log/syslog or via using the command tail -f /var/log/syslog. FMAS Logs a information like Timestamp, Date, User, Process ID, Access type (Creation, deletion etc) . It also shows the name of the process which the user was executing and also the current working directory from where the command was invoked to access the directory or the regular file.
  
  PPT With the Main Idea and Design
  
  https://github.com/soumendus/file-audit-using-kaudit/blob/master/FAMS_Design%20.pptx
  
  Associated Code
  
  Main Class
  
  https://github.com/soumendus/file-audit-using-kaudit/blob/master/auditmain_class.cpp
  
  Event Class
  
  https://github.com/soumendus/file-audit-using-kaudit/blob/master/event_class.h
  
  https://github.com/soumendus/file-audit-using-kaudit/blob/master/event_class.cpp
  
  Daemon Class
  
  https://github.com/soumendus/file-audit-using-kaudit/blob/master/daemon_class.h
  
  https://github.com/soumendus/file-audit-using-kaudit/blob/master/daemon_class.cpp
  
  
  
  2) I have also developed this using a naive approach where my software recursively keeps checking the directory for access to files. The frequency of scanning the directory can be configured. This method even though works cannot be considered as a great method.
  
  3) Using Linux inotify - monitoring filesystem events we can write a application which can collect events from the Linux Kernel and Log to the file. This nethod is analogous to the first method i.e using the Linux kaudit daemon.
  
  4) We can write a comprehensive script leveraging auditd daemon and adding rules.
  
  5)  I think we can write our own custom kaudit like daemon in the Linux Kernel and add a user space component like FMAS to leverage the custom daemon. Basically we don't want to be at the mercy of the existing kaudit kernel component and we can write out owncustom lightweight daemon.
  
  # HOW TO INSTALL THE FMAS SOFTWARE
  
  https://github.com/soumendus/file-audit-using-kaudit/blob/master/FAMS-1-1.x86_64.rpm
  
  $ rpm -ivh FAMS-1-1.x86_64.rpm --nodeps 
  
   # HOW TO CONFIGURE THE FMAS SOFTWARE
   
   Add all your Directories that you want to monitor in the file /etc/auditdir.conf 
   
   Example: The following shows three directories added
   
   /root/coding
   
   /home/scala
   
   /etc
   
   # HOW TO RUN THE FMAS DAEMON
   
   $ auditdir
   
   # HOW TO SEE LOGGED DATA
   
   $ tail -f /var/log/syslog in ubuntu
   
   $ tail -f /var/log/messages in REDHAT or CentOS
   
   # TBD
   
   - More Testing by writing a Test Driver
   
   - More comprehensive Exception Handling
   
   - Bit of code re-factoring
   
   - Add a bit more Documentation in the code.
   
   - Encapsulate the NETLINK routines into a class netlink_class.
   
   - Encapsulate the syslog routines into logger_class.
