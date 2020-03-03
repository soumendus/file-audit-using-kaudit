## FMAS: FILE MONITORING AND AUDITING SOFTWARE

# AUTHOR

Soumendu Sekhar Satapathy

Email: satapathy.soumendu@gmail.com

# PROBLEM
File monitoring software that will log file access to configured directories on the system.

            
# SOLUTION
  There can be many ways to solve this problem. I developed in two methods. Here I am also sharing more methods to solve this problem.
  
  1) I have developed this Software (FMAS) using C++ language and this application leverages the Linux Kernel Audit daemon. The FMAS application uses the libaudit library. This FMAS software registers rules with the Linux Kernel for directory monitoring. These directory will be specified by user with full path, in the file /etc/auditdir.conf. Whenever any activity happens within the directory, by some user who logged into the system either remotely or locally, events are sent by the Linux kernel which are caught by the event class of FMAS.
  and invokes the handler to log to the syslog :- /var/log/syslog. Kernel <--> Userspace communication happens via NETLINK. 
  We can view the LOG by doing a "vi" to the /var/log/syslog or via using the command tail -f /var/log/syslog. Logging is also done to a TEXT file /var/log/auditdir.log. FMAS Logs information like Timestamp, Date, User, Process ID, Access type (Creation, deletion etc) . It also shows the name of the process which the user was executing and also the current working directory from where the command was invoked to access the directory or the regular file.
  
    PPT With the Main Idea and Design
  
    https://github.com/soumendus/file-audit-using-kaudit/blob/master/FMAS_Design.jpg
  
    Associated Code
  
    auditmain Source File
  
    https://github.com/soumendus/file-audit-using-kaudit/blob/master/auditmain_class.cpp
  
    Event Class
  
    https://github.com/soumendus/file-audit-using-kaudit/blob/master/event_class.h
  
    https://github.com/soumendus/file-audit-using-kaudit/blob/master/event_class.cpp
    
    
    Netlink Class
  
    https://github.com/soumendus/file-audit-using-kaudit/blob/master/netlink_class.h
    
    https://github.com/soumendus/file-audit-using-kaudit/blob/master/netlink_class.cpp
        
    
    Daemon Class
  
    https://github.com/soumendus/file-audit-using-kaudit/blob/master/daemon_class.h
  
    https://github.com/soumendus/file-audit-using-kaudit/blob/master/daemon_class.cpp
    
    
    Exception Class
  
    https://github.com/soumendus/file-audit-using-kaudit/blob/master/exception_class.h
    
    https://github.com/soumendus/file-audit-using-kaudit/blob/master/exception_class.cpp
    
  
  
  2) I have also developed this using a naive approach where my software recursively keeps checking the directory for access to files. The frequency of scanning the directory can be configured. This method even though works cannot be considered as a great method.
  
  3) Using Linux inotify - monitoring filesystem events we can write a application which can collect events from the Linux Kernel and Log to the file. This nethod is analogous to the first method i.e using the Linux kauditd daemon.
  
  4) We can write a comprehensive script leveraging auditd daemon and adding rules.
  
  5)  I think we can write our own custom kauditd like daemon in the Linux Kernel and add a user space component like FMAS to leverage the custom daemon. Basically we don't want to be at the mercy of the existing kaudit kernel component and we can write out own custom lightweight daemon.
  
  # PREREQUISITE
  
    (1) The Linux Kernel should have the kauditd kernel daemon running. 
    
    $ ps -aef|grep kauditd
    
    root        84     2  0 Feb26 ?        00:00:00 [kauditd]
    
    To verify do the following.
    
    grep CONFIG_AUDIT /boot/config-`uname -r`
    
    CONFIG_AUDIT=y
    CONFIG_AUDITSYSCALL=y
    CONFIG_AUDIT_ARCH=y

    If you don't see the above config set, then you need to set it in the .config and build your kernel.
    
    (2) libaudit library should be present in the system.
    
    (3) Before you run the FMAS daemon, ensure that you turn off any other audit daemon that is running as follows
    
       $ service auditd stop
       
    (4)  Booting with "audit=1" on the kernel command-line will make sure auditing is enabled on all auditible processes.

    Set audit=1 in the Kernel Boot parameters.  :

    Open the file /etc/default/grub
    
    Append "audit=1" to the space-separated list of options specified in the GRUB_CMDLINE_LINUX_DEFAULT variable.
    
    Save the file
    
    Update the GRUB2 boot loader configuration in /boot/grub2/grub.cfg by executing

    # grub2-mkconfig -o /boot/grub2/grub.cfg

    Reboot the system
    
    Verify that the setting is present in the /proc/cmdline file
       
  
  # HOW TO INSTALL THE FMAS SOFTWARE
  
  https://github.com/soumendus/file-audit-using-kaudit/blob/master/FAMS-1-1.x86_64.rpm
  
  $ rpm -ivh FAMS-1-1.x86_64.rpm --nodeps 
  
   # HOW TO CONFIGURE THE FMAS SOFTWARE
   
    Add all your Directories that you want to monitor in the file /etc/auditdir.conf. No trailing space or empty lines in between. The application has a parser in place to parse the file.
 
   
    Example: The following shows three directories added
   
    /tmp
    /home/soumendu
    /etc
    /root
   
    TBD: To provide the user with an option to set their own text file for logging.  
   
   

   
   # HOW TO RUN THE FMAS DAEMON
   
    $ auditdir
   
    Either we do it as above or as below.
          
    $ service fmas start
    
    $ service fmas status
    
    
    fmas.service - File Monitoring and Auditing Service
    Loaded: loaded (/lib/systemd/system/fmas.service; enabled; vendor preset: enabled)
    Active: active (running) since Sat 2020-02-29 16:44:32 EST; 2s ago
    Process: 5673 ExecStart=/usr/bin/auditdir (code=exited, status=0/SUCCESS)
    Main PID: 5309 (code=exited, status=0/SUCCESS)
    Tasks: 1 (limit: 4915)
    CGroup: /system.slice/fmas.service
           └─5675 /usr/bin/auditdir

    Feb 29 16:44:32 soumendus-Inspiron-3670 systemd[1]: Starting File Monitoring and Auditing Service...
    Feb 29 16:44:32 soumendus-Inspiron-3670 systemd[1]: Started File Monitoring and Auditing Service.

   
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
    
    Name of the Directory Accessed: - /tmp
    Name of the file Accessed in the Directory: FMAS.txt
    Type of Access: DELETE the File FMAS.txt
    Date of Access: Mon Feb 24 09:40:04 2020
    Process ID of the Process which Accessed the file: 8688
    Process Name of the process which accessed the file: /bin/rm
    User ID who accessed the file: 0 
    User name who accessed the file: root ( 0 User ID is root as per /etc/passwd )
    
    

 
  
