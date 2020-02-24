## FILE MONITORING AND AUDITING SOFTWARE


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
  There can be many ways to solve this problem. I developed in two methods. I am also sharing other methods to solve this problem.
  
  1) I have developed this in C++ language leveraging the Linux Kernel Audit daemon. My software registers rules with the Linux Kernel for directory monitoring. These directory will be specified by user with full path, in the file /etc/auditdir.conf. Wheneven any activity happens within the directory by some user who logged into the system either remotely or locally, events are sent by the Linux kernel which are caught by the event class which I have written
  and invokes the handler to log to the syslog :- /var/log/syslog. We can view there by doing a "vi" in the /var/log/syslog or
  using the command tail -f /var/log/syslog. This Logs a plethora of information like Timestamp, Date, User, Process ID, Access type (Creation, deletion etc). It also shows the name of the process which the user was executing and from the current working directory.
  
  2) I have also developed this using a naive approach where my software recursively keeps checking the directory for access to files. The frequency of scanning the directory can be configured. This method even though works cannot be considered as a great method.
  
  3) Using Linux inotify we can write a application whcih can collect events fom the Linux Kernel and Log to the file. This nethod is analogous to the first method i.e using the Linux kaudit daemon.
  
