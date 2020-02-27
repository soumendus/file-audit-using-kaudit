## FMAS: FILE MONITORING AND AUDITING SOFTWARE

# AUTHOR

Soumendu Sekhar Satapathy

Email: satapathy.soumendu@gmail.com

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
  
  1) I have developed this Software (FMAS) using C++ language and this application leverages the Linux Kernel Audit daemon. The FMAS application uses the libaudit library. This FMAS software registers rules with the Linux Kernel for directory monitoring. These directory will be specified by user with full path, in the file /etc/auditdir.conf. Whenever any activity happens within the directory, by some user who logged into the system either remotely or locally, events are sent by the Linux kernel which are caught by the event class of FMAS.
  and invokes the handler to log to the syslog :- /var/log/syslog. Kernel <--> Userspace communication happens via NETLINK. 
  We can view the LOG by doing a "vi" to the /var/log/syslog or via using the command tail -f /var/log/syslog. Logging is also done to a TEXT file /var/log/auditdir.log. FMAS Logs information like Timestamp, Date, User, Process ID, Access type (Creation, deletion etc) . It also shows the name of the process which the user was executing and also the current working directory from where the command was invoked to access the directory or the regular file.
  
    PPT With the Main Idea and Design
  
    https://github.com/soumendus/file-audit-using-kaudit/blob/master/FMAS_Design.jpg
  
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
  
  3) Using Linux inotify - monitoring filesystem events we can write a application which can collect events from the Linux Kernel and Log to the file. This nethod is analogous to the first method i.e using the Linux kauditd daemon.
  
  4) We can write a comprehensive script leveraging auditd daemon and adding rules.
  
  5)  I think we can write our own custom kauditd like daemon in the Linux Kernel and add a user space component like FMAS to leverage the custom daemon. Basically we don't want to be at the mercy of the existing kaudit kernel component and we can write out own custom lightweight daemon.
  
  # PREREQUISITE
  
     - The Linux Kerne should have the kauditd kernel daemon running. 
    
    $ ps -aef|grep kauditd
    
    root        84     2  0 Feb26 ?        00:00:00 [kauditd]
    
    To verify do the following.
    
    grep CONFIG_AUDIT /boot/config-`uname -r`
    
    CONFIG_AUDIT=y
    CONFIG_AUDITSYSCALL=y
    CONFIG_AUDIT_ARCH=y

    If you don't see the above config set, then you need to set it in the .config and build your kernel.
    
    - libaudit library should be present in the system.
    
    - Before you run the FMAS daemon, ensure that you turn off any other audit daemon that is running as follows
    
       $ service audit stop
       
  
  # HOW TO INSTALL THE FMAS SOFTWARE
  
  https://github.com/soumendus/file-audit-using-kaudit/blob/master/FAMS-1-1.x86_64.rpm
  
  $ rpm -ivh FAMS-1-1.x86_64.rpm --nodeps 
  
   # HOW TO CONFIGURE THE FMAS SOFTWARE
   
   Add all your Directories that you want to monitor in the file /etc/auditdir.conf. No trailing space or empty lines in between.
   My parser development is TBD which will take care of this trailing and leading spaces and empty lines in between the paths.
   
   Example: The following shows three directories added
   
   /root/coding
   
   /home/scala
   
   /etc
   
    TBD: Planning to change the CONF file(/etc/auditdir.conf) as follows so that the user can specify the Directories and also the LOG file in the same CONF file and this
     will be backed up by a written parser which will properly parse this file before extracting the directories and the LOG file.
   
    TBD: Contents of the /etc/auditdir.conf file
    AUDITDIR_DIRS=/etc /root/coding /tmp

    AUDITDIR_LOGFILE=/var/log/mylog.txt

   
   # HOW TO RUN THE FMAS DAEMON
   
    $ auditdir
   
    TBD: Either we do it as above or we can also register our daemon with the systemd and use the systemctl to start and stop and check the status.
   
    Contents of /etc/systemd/system/fmas.service
    [Unit]
    Description=FMAS: File Monitoring and Auditing System
    After=<>

    [Service]
    Type=simple
    Restart=always
    ExecStart=/usr/bin/auditdir

    [Install]
    WantedBy=multi-user.target
    
    systemctl enable fmas.service
    
    systemctl start fmas.service
   
   # HOW TO SEE LOGGED DATA
   
   Logging is done to a log file /var/log/auditdir.log.
   
   $ cat /var/log/auditdir.log
   
   Logging is also done via syslog.
   
   $ tail -f /var/log/syslog in ubuntu
   
   $ tail -f /var/log/messages in REDHAT or CentOS
   
   
   # HOW TO ANALYZE LOGGED DATA
   
    FMAS::Type=SYSCALL Message=audit(1582555204.917:21875): arch=c000003e syscall=263 success=yes exit=0 a0=ffffff9c a1=55bdba8cd490 a2=0 a3=55bdba8cc010 items=2 ppid=2076 pid=8688 auid=1000 uid=0 gid=0 euid=0 suid=0 fsuid=0 egid=0 
    sgid=0 fsgid=0 tty=pts0 ses=3 comm="rm" exe="/bin/rm" key=(null) Date=Mon Feb 24 09:40:04 2020
    
    FMAS::Type=CWD Message=audit(1582555204.917:21875): cwd="/tmp" Date=Mon Feb 24 09:40:04 2020
    
    FMAS::Type=PATH Message=audit(1582555204.917:21875): item=0 name="/tmp" inode=15466497 dev=08:02 mode=041777 
    ouid=0 ogid=0 rdev=00:00 nametype=PARENT cap_fp=0 cap_fi=0 cap_fe=0 cap_fver=0 cap_frootid=0 Date=Mon Feb 24 09:40:04 2020
    
    FMAS::Type=PATH Message=audit(1582555204.917:21875): item=1 name="FMAS.txt" inode=15466516 dev=08:02 mode=0100644 
    ouid=0 ogid=0 rdev=00:00 nametype=DELETE cap_fp=0 cap_fi=0 cap_fe=0 cap_fver=0 cap_frootid=0 Date=Mon Feb 24 09:40:04 2020

    In the above output I am trying to DELETE a file called FAMS.txt inside the /tmp directory.
    
    TBD: Format the above output and log as below, for a non-unix user. A BASH script can be written to do that
    or a few lines of C++ code can be added to the FMAS application to format the above output as follows.
    
    Name of the Directory Accessed: - /etc
    Name of the file Accessed in the Directory: /etc/passwd
    Type of Access: READ
    Date of Access: Tue Feb 23 09:26:21 EST 2020
    Process ID of the Process which Accessed the file: 12345
    Process Name of the process which accessed the file: /bin/cat
    User ID who accessed the file: 1001
    User name who accessed the file: soumendu
    
    


   # TBD
   
   - To convert numerical User ID to human readable format.
   
   - To do a bit of parsing for reading data from /etc/auditdir.conf file.
   
   - More Testing and validation by writing a Test Driver
   
   - More comprehensive Exception Handling
   
   - Bit of code re-factoring
   
   - Add a bit more Documentation in the code.
   
   - Encapsulate the NETLINK routines into a class netlink_class.
   
   - Encapsulate the syslog routines into logger_class.
         
   - Provision for User being able to configure more rules.
   
  
