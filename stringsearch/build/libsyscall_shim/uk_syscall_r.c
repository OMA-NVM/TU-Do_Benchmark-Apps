/* Auto generated file. DO NOT EDIT */


#include <uk/syscall.h>
#include <uk/print.h>

long uk_vsyscall_r(long nr, va_list arg)
{
	(void) arg;

	switch (nr) {
	case SYS_fork:
		return uk_syscall_r_fork();
	case SYS_vfork:
		return uk_syscall_r_vfork();
	case SYS_execve:
		return uk_syscall_r_execve(va_arg(arg, long), va_arg(arg, long), va_arg(arg, long));
	case SYS_wait4:
		return uk_syscall_r_wait4(va_arg(arg, long), va_arg(arg, long), va_arg(arg, long), va_arg(arg, long));
	case SYS_getpgid:
		return uk_syscall_r_getpgid(va_arg(arg, long));
	case SYS_setpgid:
		return uk_syscall_r_setpgid(va_arg(arg, long), va_arg(arg, long));
	case SYS_setsid:
		return uk_syscall_r_setsid();
	case SYS_getsid:
		return uk_syscall_r_getsid(va_arg(arg, long));
	case SYS_setpriority:
		return uk_syscall_r_setpriority(va_arg(arg, long), va_arg(arg, long), va_arg(arg, long));
	case SYS_getpriority:
		return uk_syscall_r_getpriority(va_arg(arg, long), va_arg(arg, long));
	case SYS_getpgrp:
		return uk_syscall_r_getpgrp();
	case SYS_getpid:
		return uk_syscall_r_getpid();
	case SYS_getppid:
		return uk_syscall_r_getppid();
	case SYS_prlimit64:
		return uk_syscall_r_prlimit64(va_arg(arg, long), va_arg(arg, long), va_arg(arg, long), va_arg(arg, long));
	case SYS_getrlimit:
		return uk_syscall_r_getrlimit(va_arg(arg, long), va_arg(arg, long));
	case SYS_setrlimit:
		return uk_syscall_r_setrlimit(va_arg(arg, long), va_arg(arg, long));
	case SYS_getrusage:
		return uk_syscall_r_getrusage(va_arg(arg, long), va_arg(arg, long));
	case SYS_prctl:
		return uk_syscall_r_prctl(va_arg(arg, long), va_arg(arg, long), va_arg(arg, long), va_arg(arg, long), va_arg(arg, long));
	case SYS_sysinfo:
		return uk_syscall_r_sysinfo(va_arg(arg, long));
	case SYS_uname:
		return uk_syscall_r_uname(va_arg(arg, long));
	case SYS_sethostname:
		return uk_syscall_r_sethostname(va_arg(arg, long), va_arg(arg, long));
	case SYS_getegid:
		return uk_syscall_r_getegid();
	case SYS_geteuid:
		return uk_syscall_r_geteuid();
	case SYS_getgid:
		return uk_syscall_r_getgid();
	case SYS_getuid:
		return uk_syscall_r_getuid();
	case SYS_setuid:
		return uk_syscall_r_setuid(va_arg(arg, long));
	case SYS_capset:
		return uk_syscall_r_capset(va_arg(arg, long), va_arg(arg, long));
	case SYS_setfsgid:
		return uk_syscall_r_setfsgid(va_arg(arg, long));
	case SYS_setfsuid:
		return uk_syscall_r_setfsuid(va_arg(arg, long));
	case SYS_getgroups:
		return uk_syscall_r_getgroups(va_arg(arg, long), va_arg(arg, long));
	case SYS_getresgid:
		return uk_syscall_r_getresgid(va_arg(arg, long), va_arg(arg, long), va_arg(arg, long));
	case SYS_setgid:
		return uk_syscall_r_setgid(va_arg(arg, long));
	case SYS_setreuid:
		return uk_syscall_r_setreuid(va_arg(arg, long), va_arg(arg, long));
	case SYS_setregid:
		return uk_syscall_r_setregid(va_arg(arg, long), va_arg(arg, long));
	case SYS_setgroups:
		return uk_syscall_r_setgroups(va_arg(arg, long), va_arg(arg, long));
	case SYS_capget:
		return uk_syscall_r_capget(va_arg(arg, long), va_arg(arg, long));
	case SYS_setresuid:
		return uk_syscall_r_setresuid(va_arg(arg, long), va_arg(arg, long), va_arg(arg, long));
	case SYS_getresuid:
		return uk_syscall_r_getresuid(va_arg(arg, long), va_arg(arg, long), va_arg(arg, long));
	case SYS_setresgid:
		return uk_syscall_r_setresgid(va_arg(arg, long), va_arg(arg, long), va_arg(arg, long));
	case SYS_nanosleep:
		return uk_syscall_r_nanosleep(va_arg(arg, long), va_arg(arg, long));
	case SYS_clock_gettime:
		return uk_syscall_r_clock_gettime(va_arg(arg, long), va_arg(arg, long));
	case SYS_clock_settime:
		return uk_syscall_r_clock_settime(va_arg(arg, long), va_arg(arg, long));
	case SYS_clock_getres:
		return uk_syscall_r_clock_getres(va_arg(arg, long), va_arg(arg, long));
	case SYS_gettimeofday:
		return uk_syscall_r_gettimeofday(va_arg(arg, long), va_arg(arg, long));
	case SYS_times:
		return uk_syscall_r_times(va_arg(arg, long));
	case SYS_time:
		return uk_syscall_r_time(va_arg(arg, long));
	case SYS_setitimer:
		return uk_syscall_r_setitimer(va_arg(arg, long), va_arg(arg, long), va_arg(arg, long));
	case SYS_timer_create:
		return uk_syscall_r_timer_create(va_arg(arg, long), va_arg(arg, long), va_arg(arg, long));
	case SYS_timer_delete:
		return uk_syscall_r_timer_delete(va_arg(arg, long));
	case SYS_timer_settime:
		return uk_syscall_r_timer_settime(va_arg(arg, long), va_arg(arg, long), va_arg(arg, long), va_arg(arg, long));
	case SYS_timer_gettime:
		return uk_syscall_r_timer_gettime(va_arg(arg, long), va_arg(arg, long));
	case SYS_timer_getoverrun:
		return uk_syscall_r_timer_getoverrun(va_arg(arg, long));
	default:
		uk_pr_debug("syscall \"%s\" is not available\n", uk_syscall_name(nr));
		return -ENOSYS;
	}
}

long uk_syscall_r(long nr, ...)
{
	long ret;
	va_list ap;

	va_start(ap, nr);
	ret = uk_vsyscall_r(nr, ap);
	va_end(ap);
	return ret;
}
