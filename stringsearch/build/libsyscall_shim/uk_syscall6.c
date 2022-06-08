/* Auto generated file. DO NOT EDIT */


#include <uk/syscall.h>
#include <uk/print.h>

long uk_syscall6(long nr, long arg1, long arg2, long arg3, long arg4, long arg5, long arg6)
{
	(void) arg1;
	(void) arg2;
	(void) arg3;
	(void) arg4;
	(void) arg5;
	(void) arg6;

	switch (nr) {
	case SYS_fork:
		return uk_syscall_e_fork();
	case SYS_vfork:
		return uk_syscall_e_vfork();
	case SYS_execve:
		return uk_syscall_e_execve(arg1, arg2, arg3);
	case SYS_wait4:
		return uk_syscall_e_wait4(arg1, arg2, arg3, arg4);
	case SYS_getpgid:
		return uk_syscall_e_getpgid(arg1);
	case SYS_setpgid:
		return uk_syscall_e_setpgid(arg1, arg2);
	case SYS_setsid:
		return uk_syscall_e_setsid();
	case SYS_getsid:
		return uk_syscall_e_getsid(arg1);
	case SYS_setpriority:
		return uk_syscall_e_setpriority(arg1, arg2, arg3);
	case SYS_getpriority:
		return uk_syscall_e_getpriority(arg1, arg2);
	case SYS_getpgrp:
		return uk_syscall_e_getpgrp();
	case SYS_getpid:
		return uk_syscall_e_getpid();
	case SYS_getppid:
		return uk_syscall_e_getppid();
	case SYS_prlimit64:
		return uk_syscall_e_prlimit64(arg1, arg2, arg3, arg4);
	case SYS_getrlimit:
		return uk_syscall_e_getrlimit(arg1, arg2);
	case SYS_setrlimit:
		return uk_syscall_e_setrlimit(arg1, arg2);
	case SYS_getrusage:
		return uk_syscall_e_getrusage(arg1, arg2);
	case SYS_prctl:
		return uk_syscall_e_prctl(arg1, arg2, arg3, arg4, arg5);
	case SYS_sysinfo:
		return uk_syscall_e_sysinfo(arg1);
	case SYS_uname:
		return uk_syscall_e_uname(arg1);
	case SYS_sethostname:
		return uk_syscall_e_sethostname(arg1, arg2);
	case SYS_getegid:
		return uk_syscall_e_getegid();
	case SYS_geteuid:
		return uk_syscall_e_geteuid();
	case SYS_getgid:
		return uk_syscall_e_getgid();
	case SYS_getuid:
		return uk_syscall_e_getuid();
	case SYS_setuid:
		return uk_syscall_e_setuid(arg1);
	case SYS_capset:
		return uk_syscall_e_capset(arg1, arg2);
	case SYS_setfsgid:
		return uk_syscall_e_setfsgid(arg1);
	case SYS_setfsuid:
		return uk_syscall_e_setfsuid(arg1);
	case SYS_getgroups:
		return uk_syscall_e_getgroups(arg1, arg2);
	case SYS_getresgid:
		return uk_syscall_e_getresgid(arg1, arg2, arg3);
	case SYS_setgid:
		return uk_syscall_e_setgid(arg1);
	case SYS_setreuid:
		return uk_syscall_e_setreuid(arg1, arg2);
	case SYS_setregid:
		return uk_syscall_e_setregid(arg1, arg2);
	case SYS_setgroups:
		return uk_syscall_e_setgroups(arg1, arg2);
	case SYS_capget:
		return uk_syscall_e_capget(arg1, arg2);
	case SYS_setresuid:
		return uk_syscall_e_setresuid(arg1, arg2, arg3);
	case SYS_getresuid:
		return uk_syscall_e_getresuid(arg1, arg2, arg3);
	case SYS_setresgid:
		return uk_syscall_e_setresgid(arg1, arg2, arg3);
	case SYS_nanosleep:
		return uk_syscall_e_nanosleep(arg1, arg2);
	case SYS_clock_gettime:
		return uk_syscall_e_clock_gettime(arg1, arg2);
	case SYS_clock_settime:
		return uk_syscall_e_clock_settime(arg1, arg2);
	case SYS_clock_getres:
		return uk_syscall_e_clock_getres(arg1, arg2);
	case SYS_gettimeofday:
		return uk_syscall_e_gettimeofday(arg1, arg2);
	case SYS_times:
		return uk_syscall_e_times(arg1);
	case SYS_time:
		return uk_syscall_e_time(arg1);
	case SYS_setitimer:
		return uk_syscall_e_setitimer(arg1, arg2, arg3);
	case SYS_timer_create:
		return uk_syscall_e_timer_create(arg1, arg2, arg3);
	case SYS_timer_delete:
		return uk_syscall_e_timer_delete(arg1);
	case SYS_timer_settime:
		return uk_syscall_e_timer_settime(arg1, arg2, arg3, arg4);
	case SYS_timer_gettime:
		return uk_syscall_e_timer_gettime(arg1, arg2);
	case SYS_timer_getoverrun:
		return uk_syscall_e_timer_getoverrun(arg1);
	default:
		uk_pr_debug("syscall \"%s\" is not available\n", uk_syscall_name(nr));
		errno = -ENOSYS;
		return -1;
	}
}
