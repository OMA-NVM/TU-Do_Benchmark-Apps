/* Auto generated file. DO NOT EDIT */

#include <uk/syscall.h>
#include <uk/print.h>
#include <stdlib.h>

long (*uk_syscall_r_fn(long nr))(void)
{
	switch (nr) {
	case SYS_fork:
		return (long (*)(void)) uk_syscall_r_fork;
	case SYS_vfork:
		return (long (*)(void)) uk_syscall_r_vfork;
	case SYS_execve:
		return (long (*)(void)) uk_syscall_r_execve;
	case SYS_wait4:
		return (long (*)(void)) uk_syscall_r_wait4;
	case SYS_getpgid:
		return (long (*)(void)) uk_syscall_r_getpgid;
	case SYS_setpgid:
		return (long (*)(void)) uk_syscall_r_setpgid;
	case SYS_setsid:
		return (long (*)(void)) uk_syscall_r_setsid;
	case SYS_getsid:
		return (long (*)(void)) uk_syscall_r_getsid;
	case SYS_setpriority:
		return (long (*)(void)) uk_syscall_r_setpriority;
	case SYS_getpriority:
		return (long (*)(void)) uk_syscall_r_getpriority;
	case SYS_getpgrp:
		return (long (*)(void)) uk_syscall_r_getpgrp;
	case SYS_getpid:
		return (long (*)(void)) uk_syscall_r_getpid;
	case SYS_getppid:
		return (long (*)(void)) uk_syscall_r_getppid;
	case SYS_prlimit64:
		return (long (*)(void)) uk_syscall_r_prlimit64;
	case SYS_getrlimit:
		return (long (*)(void)) uk_syscall_r_getrlimit;
	case SYS_setrlimit:
		return (long (*)(void)) uk_syscall_r_setrlimit;
	case SYS_getrusage:
		return (long (*)(void)) uk_syscall_r_getrusage;
	case SYS_prctl:
		return (long (*)(void)) uk_syscall_r_prctl;
	case SYS_sysinfo:
		return (long (*)(void)) uk_syscall_r_sysinfo;
	case SYS_uname:
		return (long (*)(void)) uk_syscall_r_uname;
	case SYS_sethostname:
		return (long (*)(void)) uk_syscall_r_sethostname;
	case SYS_getegid:
		return (long (*)(void)) uk_syscall_r_getegid;
	case SYS_geteuid:
		return (long (*)(void)) uk_syscall_r_geteuid;
	case SYS_getgid:
		return (long (*)(void)) uk_syscall_r_getgid;
	case SYS_getuid:
		return (long (*)(void)) uk_syscall_r_getuid;
	case SYS_setuid:
		return (long (*)(void)) uk_syscall_r_setuid;
	case SYS_capset:
		return (long (*)(void)) uk_syscall_r_capset;
	case SYS_setfsgid:
		return (long (*)(void)) uk_syscall_r_setfsgid;
	case SYS_setfsuid:
		return (long (*)(void)) uk_syscall_r_setfsuid;
	case SYS_getgroups:
		return (long (*)(void)) uk_syscall_r_getgroups;
	case SYS_getresgid:
		return (long (*)(void)) uk_syscall_r_getresgid;
	case SYS_setgid:
		return (long (*)(void)) uk_syscall_r_setgid;
	case SYS_setreuid:
		return (long (*)(void)) uk_syscall_r_setreuid;
	case SYS_setregid:
		return (long (*)(void)) uk_syscall_r_setregid;
	case SYS_setgroups:
		return (long (*)(void)) uk_syscall_r_setgroups;
	case SYS_capget:
		return (long (*)(void)) uk_syscall_r_capget;
	case SYS_setresuid:
		return (long (*)(void)) uk_syscall_r_setresuid;
	case SYS_getresuid:
		return (long (*)(void)) uk_syscall_r_getresuid;
	case SYS_setresgid:
		return (long (*)(void)) uk_syscall_r_setresgid;
	case SYS_nanosleep:
		return (long (*)(void)) uk_syscall_r_nanosleep;
	case SYS_clock_gettime:
		return (long (*)(void)) uk_syscall_r_clock_gettime;
	case SYS_clock_settime:
		return (long (*)(void)) uk_syscall_r_clock_settime;
	case SYS_clock_getres:
		return (long (*)(void)) uk_syscall_r_clock_getres;
	case SYS_gettimeofday:
		return (long (*)(void)) uk_syscall_r_gettimeofday;
	case SYS_times:
		return (long (*)(void)) uk_syscall_r_times;
	case SYS_time:
		return (long (*)(void)) uk_syscall_r_time;
	case SYS_setitimer:
		return (long (*)(void)) uk_syscall_r_setitimer;
	case SYS_timer_create:
		return (long (*)(void)) uk_syscall_r_timer_create;
	case SYS_timer_delete:
		return (long (*)(void)) uk_syscall_r_timer_delete;
	case SYS_timer_settime:
		return (long (*)(void)) uk_syscall_r_timer_settime;
	case SYS_timer_gettime:
		return (long (*)(void)) uk_syscall_r_timer_gettime;
	case SYS_timer_getoverrun:
		return (long (*)(void)) uk_syscall_r_timer_getoverrun;
	default:
		return NULL;
	}
}
