/* This is a generated file, see Makefile.am for its inputs. */
static const char ppc_syscall_strings[] = "_llseek\0_newselect\0_sysctl\0accept\0accept4\0access\0acct\0add_key\0adjtimex\0afs_syscall\0"
	"alarm\0bdflush\0bind\0break\0brk\0capget\0capset\0chdir\0chmod\0chown\0"
	"chroot\0clock_adjtime\0clock_getres\0clock_gettime\0clock_nanosleep\0clock_settime\0clone\0close\0connect\0creat\0"
	"create_module\0delete_module\0dup\0dup2\0dup3\0epoll_create\0epoll_create1\0epoll_ctl\0epoll_pwait\0epoll_wait\0"
	"eventfd\0eventfd2\0execve\0exit\0exit_group\0faccessat\0fadvise64\0fadvise64_64\0fallocate\0fanotify_init\0"
	"fanotify_mark\0fchdir\0fchmod\0fchmodat\0fchown\0fchownat\0fcntl\0fcntl64\0fdatasync\0fgetxattr\0"
	"flistxattr\0flock\0fork\0fremovexattr\0fsetxattr\0fstat\0fstat64\0fstatat\0fstatfs\0fstatfs64\0"
	"fsync\0ftime\0ftruncate\0ftruncate64\0futex\0futimesat\0get_kernel_syms\0get_robust_list\0getcpu\0getcwd\0"
	"getdents\0getdents64\0getegid\0geteuid\0getgid\0getgroups\0getitimer\0getpeername\0getpgid\0getpgrp\0"
	"getpid\0getpmsg\0getppid\0getpriority\0getresgid\0getresuid\0getrlimit\0getrusage\0getsid\0getsockname\0"
	"getsockopt\0gettid\0gettimeofday\0getuid\0getxattr\0gtty\0idle\0init_module\0inotify_add_watch\0inotify_init\0"
	"inotify_init1\0inotify_rm_watch\0io_cancel\0io_destroy\0io_getevents\0io_setup\0io_submit\0ioctl\0ioperm\0iopl\0"
	"ioprio_get\0ioprio_set\0ipc\0kexec_load\0keyctl\0kill\0lchown\0lgetxattr\0link\0linkat\0"
	"listen\0listxattr\0llistxattr\0lock\0lookup_dcookie\0lremovexattr\0lseek\0lsetxattr\0lstat\0lstat64\0"
	"madvise\0mincore\0mkdir\0mkdirat\0mknod\0mknodat\0mlock\0mlockall\0mmap\0mmap2\0"
	"modify_ldt\0mount\0move_pages\0mprotect\0mpx\0mq_getsetattr\0mq_notify\0mq_open\0mq_timedreceive\0mq_timedsend\0"
	"mq_unlink\0mremap\0msync\0multiplexer\0munlock\0munlockall\0munmap\0name_to_handle_at\0nanosleep\0nfsservctl\0"
	"nice\0oldfstat\0oldlstat\0oldolduname\0oldstat\0olduname\0open\0open_by_handle_at\0openat\0pause\0"
	"pciconfig_iobase\0pciconfig_read\0pciconfig_write\0perf_counter_open\0personality\0pipe\0pipe2\0pivot_root\0poll\0ppoll\0"
	"prctl\0pread\0preadv\0prlimit64\0prof\0profil\0pselect6\0ptrace\0putpmsg\0pwrite\0"
	"pwritev\0query_module\0quotactl\0read\0readahead\0readdir\0readlink\0readlinkat\0readv\0reboot\0"
	"recv\0recvfrom\0recvmmsg\0recvmsg\0remap_file_pages\0removexattr\0rename\0renameat\0request_key\0rmdir\0"
	"rt_sigaction\0rt_sigpending\0rt_sigprocmask\0rt_sigqueueinfo\0rt_sigreturn\0rt_sigsuspend\0rt_sigtimedwait\0rt_tgsigqueueinfo\0rtas\0sched_get_priority_max\0"
	"sched_get_priority_min\0sched_getaffinity\0sched_getparam\0sched_getscheduler\0sched_rr_get_interval\0sched_setaffinity\0sched_setparam\0sched_setscheduler\0sched_yield\0select\0"
	"send\0sendfile\0sendfile64\0sendmmsg\0sendmsg\0sendto\0set_robust_list\0set_tid_address\0setdomainname\0setfsgid\0"
	"setfsuid\0setgid\0setgroups\0sethostname\0setitimer\0setns\0setpgid\0setpriority\0setregid\0setresgid\0"
	"setresuid\0setreuid\0setrlimit\0setsid\0setsockopt\0settimeofday\0setuid\0setxattr\0sgetmask\0shutdown\0"
	"sigaction\0sigaltstack\0signal\0signalfd\0signalfd4\0sigpending\0sigprocmask\0sigreturn\0sigsuspend\0socket\0"
	"socketcall\0socketpair\0splice\0spu_create\0spu_run\0ssetmask\0stat\0stat64\0statfs\0statfs64\0"
	"stime\0stty\0subpage_prot\0swapcontext\0swapoff\0swapon\0symlink\0symlinkat\0sync\0sync_file_range2\0"
	"syncfs\0sysfs\0sysinfo\0syslog\0tee\0tgkill\0time\0timer_create\0timer_delete\0timer_getoverrun\0"
	"timer_gettime\0timer_settime\0timerfd\0timerfd_gettime\0timerfd_settime\0times\0tkill\0truncate\0truncate64\0tuxcall\0"
	"ugetrlimit\0ulimit\0umask\0umount\0umount2\0uname\0unlink\0unlinkat\0unshare\0uselib\0"
	"ustat\0utime\0utimensat\0utimes\0vfork\0vhangup\0vm86\0vmsplice\0wait4\0waitid\0"
	"waitpid\0write\0writev";
static const unsigned ppc_syscall_s2i_s[] = {
	0,8,19,27,34,42,49,54,62,71,
	83,89,97,102,108,112,119,126,132,138,
	144,151,165,178,192,208,222,228,234,242,
	248,262,276,280,285,290,303,317,327,339,
	350,358,367,374,379,390,400,410,423,433,
	447,461,468,475,484,491,500,506,514,524,
	534,545,551,556,569,579,585,593,601,609,
	619,625,631,641,653,659,669,685,701,708,
	715,724,735,743,751,758,768,778,790,798,
	806,813,821,829,841,851,861,871,881,888,
	900,911,918,931,938,947,952,957,969,987,
	1000,1014,1031,1041,1052,1065,1074,1084,1090,1097,
	1102,1113,1124,1128,1139,1146,1151,1158,1168,1173,
	1180,1187,1197,1208,1213,1228,1241,1247,1257,1263,
	1271,1279,1287,1293,1301,1307,1315,1321,1330,1335,
	1341,1352,1358,1369,1378,1382,1396,1406,1414,1430,
	1443,1453,1460,1466,1478,1486,1497,1504,1522,1532,
	1543,1548,1557,1566,1578,1586,1595,1600,1618,1625,
	1631,1648,1663,1679,1697,1709,1714,1720,1731,1736,
	1742,1748,1754,1761,1771,1776,1783,1792,1799,1807,
	1814,1822,1835,1844,1849,1859,1867,1876,1887,1893,
	1900,1905,1914,1923,1931,1948,1960,1967,1976,1988,
	1994,2007,2021,2036,2052,2065,2079,2095,2113,2118,
	2141,2164,2182,2197,2216,2238,2256,2271,2290,2302,
	2309,2314,2323,2334,2343,2351,2358,2374,2390,2404,
	2413,2422,2429,2439,2451,2461,2467,2475,2487,2496,
	2506,2516,2525,2535,2542,2553,2566,2573,2582,2591,
	2600,2610,2622,2629,2638,2648,2659,2671,2681,2692,
	2699,2710,2721,2728,2739,2747,2756,2761,2768,2775,
	2784,2790,2795,2808,2820,2828,2835,2843,2853,2858,
	2875,2882,2888,2896,2903,2907,2914,2919,2932,2945,
	2962,2976,2990,2998,3014,3030,3036,3042,3051,3062,
	3070,3081,3088,3094,3101,3109,3115,3122,3131,3139,
	3146,3152,3158,3168,3175,3181,3189,3194,3203,3209,
	3216,3224,3230,
};
static const int ppc_syscall_s2i_i[] = {
	140,142,149,330,344,33,51,269,124,137,
	27,134,327,17,45,183,184,12,15,181,
	61,347,247,246,248,245,120,6,328,8,
	127,129,41,63,316,236,315,237,303,238,
	307,314,11,1,234,298,233,254,309,323,
	324,133,94,297,95,289,55,204,148,214,
	217,143,2,220,211,108,197,291,100,253,
	118,35,93,194,221,290,130,299,302,182,
	141,202,50,49,47,80,105,332,132,65,
	20,187,64,96,170,165,76,77,147,331,
	340,207,78,24,212,32,112,128,276,275,
	318,277,231,228,229,227,230,54,101,110,
	274,273,117,268,271,37,16,213,9,294,
	329,215,216,53,235,219,19,210,107,196,
	205,206,39,287,14,288,150,152,90,192,
	123,21,301,125,56,267,266,262,265,264,
	263,163,144,201,151,153,91,345,162,168,
	34,28,84,59,18,109,5,346,286,29,
	200,198,199,319,136,42,317,203,167,281,
	171,179,320,325,44,98,280,26,188,180,
	321,166,131,3,191,89,85,296,145,88,
	336,337,343,342,239,218,38,293,270,40,
	173,175,174,177,172,178,176,322,255,159,
	160,223,155,157,161,222,154,156,158,82,
	334,186,226,349,341,335,300,232,121,139,
	138,46,81,74,104,350,57,97,71,169,
	164,70,75,66,339,79,23,209,68,338,
	67,185,48,305,313,73,126,119,72,326,
	102,333,283,279,278,69,106,195,99,252,
	25,31,310,249,115,87,83,295,36,308,
	348,135,116,103,284,250,13,240,244,243,
	242,241,306,312,311,43,208,92,193,225,
	190,58,60,22,52,122,10,292,282,86,
	62,30,304,251,189,111,113,285,114,272,
	7,4,146,
};
static int ppc_syscall_s2i(const char *s, int *value) {
	size_t len, i;
	len = strlen(s);
	{ char copy[len + 1];
	for (i = 0; i < len; i++) {
		char c = s[i];
		copy[i] = GT_ISUPPER(c) ? c - 'A' + 'a' : c;
	}
	copy[i] = 0;
	return s2i__(ppc_syscall_strings, ppc_syscall_s2i_s, ppc_syscall_s2i_i, 343, copy, value);
	}
}
static const unsigned ppc_syscall_i2s_direct[] = {
	374,551,1844,3224,1595,228,3216,242,1168,3115,
	367,126,2914,1301,132,1151,102,1578,1241,806,
	1352,3094,2566,931,2784,1792,83,1548,1625,3152,
	2790,947,42,1543,625,2853,1146,1960,1287,1988,
	276,1709,3030,1771,108,2422,751,2622,743,735,
	49,3101,1208,1084,500,1378,2467,3081,1566,3088,
	144,3146,280,821,798,2535,2600,2582,2747,2516,
	2487,2681,2648,2439,2525,861,871,918,2553,758,
	2429,2302,2835,1557,1867,3139,2828,1893,1859,1330,
	1497,3042,631,468,484,829,2475,1776,2768,601,
	1090,2699,2896,2451,768,2756,1257,579,1586,1097,
	3181,952,3189,3203,2820,2888,1124,619,2671,222,
	2390,3109,1341,62,1369,2659,248,957,262,669,
	1835,790,461,89,2882,1697,71,2413,2404,0,
	715,8,545,1460,1887,3230,881,514,19,1315,
	1478,1321,1486,2256,2182,2271,2197,2290,2118,2141,
	2216,1522,1453,2506,851,1822,1731,1532,2496,841,
	1742,2052,1994,2021,2007,2079,2036,2065,1748,1807,
	138,708,112,119,2610,2314,813,1799,3175,3070,
	1849,1335,3051,641,2761,1263,585,1648,1663,1631,
	1466,724,1720,506,1271,1279,911,3036,2573,1247,
	569,938,1158,524,1187,1197,534,1948,1228,556,
	653,2238,2164,-1u,3062,2323,1065,1041,1052,1074,
	1031,2374,400,379,1213,290,317,339,1931,2919,
	2976,2962,2945,2932,208,178,165,192,2808,2907,
	3168,2775,609,410,2113,-1u,-1u,-1u,-1u,-1u,
	-1u,1406,1443,1430,1414,1396,1382,1128,54,1976,
	1139,3209,1113,1102,987,969,1014,2739,2728,1783,
	1736,3131,2721,2903,3194,1618,1293,1307,491,659,
	593,3122,1967,1173,2843,1876,475,390,685,2358,
	1358,701,327,3158,2629,2990,350,2858,423,2795,
	3014,2998,2638,358,303,285,1714,1000,1679,1754,
	1814,2095,433,447,1761,2692,97,234,1180,27,
	888,778,2710,2309,2351,1900,1905,2591,2542,900,
	2343,1923,1914,34,1504,1600,151,2875,2334,2461,
};
static const char *ppc_syscall_i2s(int v) {
	return i2s_direct__(ppc_syscall_strings, ppc_syscall_i2s_direct, 1, 350, v);
}
