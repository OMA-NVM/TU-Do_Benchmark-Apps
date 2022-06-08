/* Auto generated file. DO NOT EDIT */


#include <uk/syscall.h>
#include <uk/print.h>

long uk_vsyscall(long nr, va_list arg)
{
	(void) arg;

	__maybe_unused long a1, a2, a3, a4, a5, a6;
	switch (nr) {
	case SYS_fork:
		return uk_syscall_e_fork();
	case SYS_vfork:
		return uk_syscall_e_vfork();
	case SYS_execve:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		a3 = va_arg(arg, long);
		return uk_syscall_e_execve(a1, a2, a3);
	case SYS_wait4:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		a3 = va_arg(arg, long);
		a4 = va_arg(arg, long);
		return uk_syscall_e_wait4(a1, a2, a3, a4);
	case SYS_getpgid:
		a1 = va_arg(arg, long);
		return uk_syscall_e_getpgid(a1);
	case SYS_setpgid:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_setpgid(a1, a2);
	case SYS_setsid:
		return uk_syscall_e_setsid();
	case SYS_getsid:
		a1 = va_arg(arg, long);
		return uk_syscall_e_getsid(a1);
	case SYS_setpriority:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		a3 = va_arg(arg, long);
		return uk_syscall_e_setpriority(a1, a2, a3);
	case SYS_getpriority:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_getpriority(a1, a2);
	case SYS_getpgrp:
		return uk_syscall_e_getpgrp();
	case SYS_getpid:
		return uk_syscall_e_getpid();
	case SYS_getppid:
		return uk_syscall_e_getppid();
	case SYS_prlimit64:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		a3 = va_arg(arg, long);
		a4 = va_arg(arg, long);
		return uk_syscall_e_prlimit64(a1, a2, a3, a4);
	case SYS_getrlimit:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_getrlimit(a1, a2);
	case SYS_setrlimit:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_setrlimit(a1, a2);
	case SYS_getrusage:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_getrusage(a1, a2);
	case SYS_prctl:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		a3 = va_arg(arg, long);
		a4 = va_arg(arg, long);
		a5 = va_arg(arg, long);
		return uk_syscall_e_prctl(a1, a2, a3, a4, a5);
	case SYS_sysinfo:
		a1 = va_arg(arg, long);
		return uk_syscall_e_sysinfo(a1);
	case SYS_uname:
		a1 = va_arg(arg, long);
		return uk_syscall_e_uname(a1);
	case SYS_sethostname:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_sethostname(a1, a2);
	case SYS_getegid:
		return uk_syscall_e_getegid();
	case SYS_geteuid:
		return uk_syscall_e_geteuid();
	case SYS_getgid:
		return uk_syscall_e_getgid();
	case SYS_getuid:
		return uk_syscall_e_getuid();
	case SYS_setuid:
		a1 = va_arg(arg, long);
		return uk_syscall_e_setuid(a1);
	case SYS_capset:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_capset(a1, a2);
	case SYS_setfsgid:
		a1 = va_arg(arg, long);
		return uk_syscall_e_setfsgid(a1);
	case SYS_setfsuid:
		a1 = va_arg(arg, long);
		return uk_syscall_e_setfsuid(a1);
	case SYS_getgroups:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_getgroups(a1, a2);
	case SYS_getresgid:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		a3 = va_arg(arg, long);
		return uk_syscall_e_getresgid(a1, a2, a3);
	case SYS_setgid:
		a1 = va_arg(arg, long);
		return uk_syscall_e_setgid(a1);
	case SYS_setreuid:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_setreuid(a1, a2);
	case SYS_setregid:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_setregid(a1, a2);
	case SYS_setgroups:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_setgroups(a1, a2);
	case SYS_capget:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_capget(a1, a2);
	case SYS_setresuid:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		a3 = va_arg(arg, long);
		return uk_syscall_e_setresuid(a1, a2, a3);
	case SYS_getresuid:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		a3 = va_arg(arg, long);
		return uk_syscall_e_getresuid(a1, a2, a3);
	case SYS_setresgid:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		a3 = va_arg(arg, long);
		return uk_syscall_e_setresgid(a1, a2, a3);
	case SYS_nanosleep:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_nanosleep(a1, a2);
	case SYS_clock_gettime:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_clock_gettime(a1, a2);
	case SYS_clock_settime:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_clock_settime(a1, a2);
	case SYS_clock_getres:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_clock_getres(a1, a2);
	case SYS_gettimeofday:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_gettimeofday(a1, a2);
	case SYS_times:
		a1 = va_arg(arg, long);
		return uk_syscall_e_times(a1);
	case SYS_time:
		a1 = va_arg(arg, long);
		return uk_syscall_e_time(a1);
	case SYS_setitimer:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		a3 = va_arg(arg, long);
		return uk_syscall_e_setitimer(a1, a2, a3);
	case SYS_timer_create:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		a3 = va_arg(arg, long);
		return uk_syscall_e_timer_create(a1, a2, a3);
	case SYS_timer_delete:
		a1 = va_arg(arg, long);
		return uk_syscall_e_timer_delete(a1);
	case SYS_timer_settime:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		a3 = va_arg(arg, long);
		a4 = va_arg(arg, long);
		return uk_syscall_e_timer_settime(a1, a2, a3, a4);
	case SYS_timer_gettime:
		a1 = va_arg(arg, long);
		a2 = va_arg(arg, long);
		return uk_syscall_e_timer_gettime(a1, a2);
	case SYS_timer_getoverrun:
		a1 = va_arg(arg, long);
		return uk_syscall_e_timer_getoverrun(a1);
	default:
		uk_pr_debug("syscall \"%s\" is not available\n", uk_syscall_name(nr));
		errno = -ENOSYS;
		return -1;
	}
}

long uk_syscall(long nr, ...)
{
	long ret;
	va_list ap;

	va_start(ap, nr);
	ret = uk_vsyscall(nr, ap);
	va_end(ap);
	return ret;
}
