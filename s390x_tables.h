/* This is a generated file, see Makefile.am for its inputs. */
static const char s390x_syscall_strings[] = "_sysctl\0access\0acct\0add_key\0adjtimex\0afs_syscall\0alarm\0bdflush\0brk\0capget\0"
	"capset\0chdir\0chmod\0chown\0chroot\0clock_adjtime\0clock_getres\0clock_gettime\0clock_nanosleep\0clock_settime\0"
	"clone\0close\0creat\0create_module\0delete_module\0dup\0dup2\0dup3\0epoll_create\0epoll_create1\0"
	"epoll_ctl\0epoll_pwait\0epoll_wait\0eventfd\0eventfd2\0execve\0exit\0exit_group\0faccessat\0fadvise64\0"
	"fallocate\0fanotify_init\0fanotify_mark\0fchdir\0fchmod\0fchmodat\0fchown\0fchownat\0fcntl\0fdatasync\0"
	"fgetxattr\0flistxattr\0flock\0fork\0fremovexattr\0fsetxattr\0fstat\0fstatfs\0fstatfs64\0fsync\0"
	"ftruncate\0futex\0futimesat\0get_kernel_syms\0get_robust_list\0getcpu\0getcwd\0getdents\0getegid\0geteuid\0"
	"getgid\0getgroups\0getitimer\0getpgid\0getpgrp\0getpid\0getpmsg\0getppid\0getpriority\0getresgid\0"
	"getresuid\0getrlimit\0getrusage\0getsid\0gettid\0gettimeofday\0getuid\0getxattr\0idle\0init_module\0"
	"inotify_add_watch\0inotify_init\0inotify_init1\0inotify_rm_watch\0io_cancel\0io_destroy\0io_getevents\0io_setup\0io_submit\0ioctl\0"
	"ioprio_get\0ioprio_set\0ipc\0kexec_load\0keyctl\0kill\0lchown\0lgetxattr\0link\0linkat\0"
	"listxattr\0llistxattr\0lremovexattr\0lseek\0lsetxattr\0lstat\0madvise\0mincore\0mkdir\0mkdirat\0"
	"mknod\0mknodat\0mlock\0mlockall\0mmap\0mount\0mprotect\0mq_getsetattr\0mq_notify\0mq_open\0"
	"mq_timedreceive\0mq_timedsend\0mq_unlink\0mremap\0msync\0munlock\0munlockall\0munmap\0name_to_handle_at\0nanosleep\0"
	"newfstatat\0nfsservctl\0nice\0open\0open_by_handle_at\0openat\0pause\0perf_event_open\0personality\0pipe\0"
	"pipe2\0pivot_root\0poll\0ppoll\0prctl\0pread\0preadv\0prlimit64\0pselect6\0ptrace\0"
	"putpmsg\0pwrite\0pwritev\0query_module\0quotactl\0read\0readahead\0readdir\0readlink\0readlinkat\0"
	"readv\0reboot\0remap_file_pages\0removexattr\0rename\0renameat\0request_key\0rmdir\0rt_sigaction\0rt_sigpending\0"
	"rt_sigprocmask\0rt_sigqueueinfo\0rt_sigreturn\0rt_sigsuspend\0rt_sigtimedwait\0rt_tgsigqueueinfo\0sched_get_priority_max\0sched_get_priority_min\0sched_getaffinity\0sched_getparam\0"
	"sched_getscheduler\0sched_rr_get_interval\0sched_setaffinity\0sched_setparam\0sched_setscheduler\0sched_yield\0select\0sendfile\0set_robust_list\0set_tid_address\0"
	"setdomainname\0setfsgid\0setfsuid\0setgid\0setgroups\0sethostname\0setitimer\0setns\0setpgid\0setpriority\0"
	"setregid\0setresgid\0setresuid\0setreuid\0setrlimit\0setsid\0settimeofday\0setuid\0setxattr\0sigaction\0"
	"sigaltstack\0signal\0signalfd\0signalfd4\0sigpending\0sigprocmask\0sigreturn\0sigsuspend\0socketcall\0splice\0"
	"stat\0statfs\0statfs64\0swapoff\0swapon\0symlink\0symlinkat\0sync\0sync_file_range\0syncfs\0"
	"sysfs\0sysinfo\0syslog\0tee\0tgkill\0timer_create\0timer_delete\0timer_getoverrun\0timer_gettime\0timer_settime\0"
	"timerfd\0timerfd_create\0timerfd_gettime\0timerfd_settime\0times\0tkill\0truncate\0umask\0umount\0umount2\0"
	"uname\0unlink\0unlinkat\0unshare\0uselib\0ustat\0utime\0utimensat\0utimes\0vfork\0"
	"vhangup\0vmsplice\0wait4\0waitid\0write\0writev";
static const unsigned s390x_syscall_s2i_s[] = {
	0,8,15,20,28,37,49,55,63,67,
	74,81,87,93,99,106,120,133,147,163,
	177,183,189,195,209,223,227,232,237,250,
	264,274,286,297,305,314,321,326,337,347,
	357,367,381,395,402,409,418,425,434,440,
	450,460,471,477,482,495,505,511,519,529,
	535,545,551,561,577,593,600,607,616,624,
	632,639,649,659,667,675,682,690,698,710,
	720,730,740,750,757,764,777,784,793,798,
	810,828,841,855,872,882,893,906,915,925,
	931,942,953,957,968,975,980,987,997,1002,
	1009,1019,1030,1043,1049,1059,1065,1073,1081,1087,
	1095,1101,1109,1115,1124,1129,1135,1144,1158,1168,
	1176,1192,1205,1215,1222,1228,1236,1247,1254,1272,
	1282,1293,1304,1309,1314,1332,1339,1345,1361,1373,
	1378,1384,1395,1400,1406,1412,1418,1425,1435,1444,
	1451,1459,1466,1474,1487,1496,1501,1511,1519,1528,
	1539,1545,1552,1569,1581,1588,1597,1609,1615,1628,
	1642,1657,1673,1686,1700,1716,1734,1757,1780,1798,
	1813,1832,1854,1872,1887,1906,1918,1925,1934,1950,
	1966,1980,1989,1998,2005,2015,2027,2037,2043,2051,
	2063,2072,2082,2092,2101,2111,2118,2131,2138,2147,
	2157,2169,2176,2185,2195,2206,2218,2228,2239,2250,
	2257,2262,2269,2278,2286,2293,2301,2311,2316,2332,
	2339,2345,2353,2360,2364,2371,2384,2397,2414,2428,
	2442,2450,2465,2481,2497,2503,2509,2518,2524,2531,
	2539,2545,2552,2561,2569,2576,2582,2588,2598,2605,
	2611,2619,2628,2634,2641,2647,
};
static const int s390x_syscall_s2i_i[] = {
	149,33,51,278,124,137,27,134,45,184,
	185,12,15,212,61,337,261,260,262,259,
	120,6,8,127,129,41,63,326,249,327,
	250,312,251,318,323,11,1,248,300,253,
	314,332,333,133,94,299,207,291,55,148,
	229,232,143,2,235,226,108,100,266,118,
	93,238,292,130,305,311,183,141,202,201,
	200,205,105,132,65,20,188,64,96,211,
	209,191,77,147,236,78,199,227,112,128,
	285,284,324,286,247,244,245,243,246,54,
	283,282,117,277,280,37,198,228,9,296,
	230,231,234,19,225,107,219,218,39,289,
	14,290,150,152,90,21,125,276,275,271,
	274,273,272,163,144,151,153,91,335,162,
	293,169,34,5,336,288,29,331,136,42,
	325,217,168,302,172,180,328,334,301,26,
	189,181,329,167,131,3,222,89,85,298,
	145,88,267,233,38,295,279,40,174,176,
	175,178,173,179,177,330,159,160,240,155,
	157,161,239,154,156,158,142,187,304,252,
	121,216,215,214,206,74,104,339,57,97,
	204,210,208,203,75,66,79,213,224,67,
	186,48,316,322,73,126,119,72,102,306,
	106,99,265,115,87,83,297,36,307,338,
	135,116,103,308,241,254,258,257,256,255,
	317,319,321,320,43,237,92,60,22,52,
	122,10,294,303,86,62,30,315,313,190,
	111,309,114,281,4,146,
};
static int s390x_syscall_s2i(const char *s, int *value) {
	size_t len, i;
	len = strlen(s);
	{ char copy[len + 1];
	for (i = 0; i < len; i++) {
		char c = s[i];
		copy[i] = GT_ISUPPER(c) ? c - 'A' + 'a' : c;
	}
	copy[i] = 0;
	return s2i__(s390x_syscall_strings, s390x_syscall_s2i_s, s390x_syscall_s2i_i, 276, copy, value);
	}
}
static const unsigned s390x_syscall_i2s_direct[] = {
	321,477,1496,2641,1309,183,-1u,189,997,2545,
	314,81,-1u,1095,87,-1u,-1u,-1u,1043,675,
	1129,2524,-1u,-1u,-1u,1444,49,-1u,1339,2582,
	-1u,-1u,8,1304,-1u,2311,975,1581,1081,1609,
	223,1373,2497,-1u,63,-1u,-1u,2169,-1u,-1u,
	15,2531,-1u,925,434,-1u,2043,-1u,-1u,2518,
	99,2576,227,690,667,2111,2147,-1u,-1u,-1u,
	-1u,2228,2195,2015,2101,-1u,740,764,2118,-1u,
	-1u,-1u,2293,-1u,1519,2569,2286,1545,1511,1124,
	1247,2509,535,402,-1u,698,2051,-1u,2262,511,
	-1u,2239,2353,2027,649,2257,1059,505,-1u,-1u,
	2611,793,-1u,2628,2278,2345,953,529,2218,177,
	1966,2539,-1u,28,1135,2206,195,798,209,561,
	1487,659,395,55,2339,1361,37,-1u,-1u,-1u,
	607,1918,471,1222,1539,2647,750,440,0,1109,
	1228,1115,1236,1872,1798,1887,1813,1906,1734,1757,
	1832,1272,1215,-1u,-1u,-1u,1474,1395,1293,-1u,
	-1u,1406,1673,1615,1642,1628,1700,1657,1686,1412,
	1459,-1u,600,67,74,2157,1925,682,1451,2605,
	730,-1u,-1u,-1u,-1u,-1u,-1u,980,777,632,
	624,616,2092,2063,639,2005,418,2082,720,2072,
	710,93,2131,1998,1989,1980,1384,1073,1065,-1u,
	-1u,1501,-1u,2138,1049,495,784,987,450,1009,
	1019,460,1569,1030,482,757,2503,545,1854,1780,
	2364,-1u,906,882,893,915,872,326,237,264,
	286,1950,347,2371,2428,2414,2397,2384,163,133,
	120,147,-1u,-1u,2269,519,1552,-1u,-1u,-1u,
	1168,1205,1192,1176,1158,1144,957,20,1597,968,
	2634,942,931,828,810,855,-1u,1332,1087,1101,
	425,551,1282,2552,1588,1002,2301,1528,409,337,
	1435,1400,2561,1934,577,2250,2316,2360,2619,-1u,
	593,274,2598,357,2588,2176,2442,297,2450,2481,
	2465,2185,305,841,1378,232,250,1418,1466,1716,
	1345,367,381,1425,1254,1314,106,2332,2037,
};
static const char *s390x_syscall_i2s(int v) {
	return i2s_direct__(s390x_syscall_strings, s390x_syscall_i2s_direct, 1, 339, v);
}
