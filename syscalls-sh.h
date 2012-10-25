#include "trinity.h"
#include "sanitise.h"
#include "syscall.h"
#include "syscalls/syscalls.h"

#include <stdint.h>

#if __WORDSIZE == 64

/* arch/sh/kernel/syscalls_64.S */
struct syscalltable syscalls_sh[] = {
	{ .entry = &syscall_restart_syscall },	/* 0  -  old "setup()" system call  */
	{ .entry = &syscall_exit },
	{ .entry = &syscall_fork },
	{ .entry = &syscall_read },
	{ .entry = &syscall_write },
	{ .entry = &syscall_open },			/* 5 */
	{ .entry = &syscall_close },
	{ .entry = &syscall_waitpid },
	{ .entry = &syscall_creat },
	{ .entry = &syscall_link },
	{ .entry = &syscall_unlink },		/* 10 */
	{ .entry = &syscall_execve },
	{ .entry = &syscall_chdir },
	{ .entry = &syscall_time },
	{ .entry = &syscall_mknod },
	{ .entry = &syscall_chmod },			/* 15 */
	{ .entry = &syscall_lchown16 },
	{ .entry = &syscall_ni_syscall },	/* old break syscall holder */
	{ .entry = &syscall_stat },
	{ .entry = &syscall_lseek },
	{ .entry = &syscall_getpid },		/* 20 */
	{ .entry = &syscall_mount },
	{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_oldumount },*/
	{ .entry = &syscall_setuid16 },
	{ .entry = &syscall_getuid16 },
	{ .entry = &syscall_stime },			/* 25 */
	{ .entry = &syscall_ptrace },
	{ .entry = &syscall_alarm },
	{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_fstat },*/
	{ .entry = &syscall_pause },
	{ .entry = &syscall_utime },			/* 30 */
	{ .entry = &syscall_ni_syscall },	/* old stty syscall holder */
	{ .entry = &syscall_ni_syscall },	/* old gtty syscall holder */
	{ .entry = &syscall_access },
	{ .entry = &syscall_nice },
	{ .entry = &syscall_ni_syscall },		/* 35 */ /* old ftime syscall holder */
	{ .entry = &syscall_sync },
	{ .entry = &syscall_kill },
	{ .entry = &syscall_rename },
	{ .entry = &syscall_mkdir },
	{ .entry = &syscall_rmdir },			/* 40 */
	{ .entry = &syscall_dup },
	{ .entry = &syscall_pipe },
	{ .entry = &syscall_times },
	{ .entry = &syscall_ni_syscall },	/* old prof syscall holder */
	{ .entry = &syscall_brk },			/* 45 */
	{ .entry = &syscall_setgid16 },
	{ .entry = &syscall_getgid16 },
	{ .entry = &syscall_signal },
	{ .entry = &syscall_geteuid16 },
	{ .entry = &syscall_getegid16 },		/* 50 */
	{ .entry = &syscall_acct },
	{ .entry = &syscall_umount },		/* recycled never used phys( */
	{ .entry = &syscall_ni_syscall },	/* old lock syscall holder */
	{ .entry = &syscall_ioctl },
	{ .entry = &syscall_fcntl },			/* 55 */
	{ .entry = &syscall_ni_syscall },	/* old mpx syscall holder */
	{ .entry = &syscall_setpgid },
	{ .entry = &syscall_ni_syscall },	/* old ulimit syscall holder */
	{ .entry = &syscall_ni_syscall },	/* sys_olduname */
	{ .entry = &syscall_umask },			/* 60 */
	{ .entry = &syscall_chroot },
	{ .entry = &syscall_ustat },
	{ .entry = &syscall_dup2 },
	{ .entry = &syscall_getppid },
	{ .entry = &syscall_getpgrp },		/* 65 */
	{ .entry = &syscall_setsid },
	{ .entry = &syscall_sigaction },
	{ .entry = &syscall_sgetmask },
	{ .entry = &syscall_ssetmask },
	{ .entry = &syscall_setreuid16 },		/* 70 */
	{ .entry = &syscall_setregid16 },
	{ .entry = &syscall_sigsuspend },
	{ .entry = &syscall_sigpending },
	{ .entry = &syscall_sethostname },
	{ .entry = &syscall_setrlimit },		/* 75 */
	{ .entry = &syscall_getrlimit }, /* old_getrlimit */
	{ .entry = &syscall_getrusage },
	{ .entry = &syscall_gettimeofday },
	{ .entry = &syscall_settimeofday },
	{ .entry = &syscall_getgroups16 },		/* 80 */
	{ .entry = &syscall_setgroups16 },
	{ .entry = &syscall_ni_syscall },	/* sys_oldselect */
	{ .entry = &syscall_symlink },
	{ .entry = &syscall_lstat },
	{ .entry = &syscall_readlink },		/* 85 */
	{ .entry = &syscall_uselib },
	{ .entry = &syscall_swapon },
	{ .entry = &syscall_reboot },
	{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_old_readdir },*/
	{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_old_mmap },*/			/* 90 */
	{ .entry = &syscall_munmap },
	{ .entry = &syscall_truncate },
	{ .entry = &syscall_ftruncate },
	{ .entry = &syscall_fchmod },
	{ .entry = &syscall_fchown16 },		/* 95 */
	{ .entry = &syscall_getpriority },
	{ .entry = &syscall_setpriority },
	{ .entry = &syscall_ni_syscall },	/* old profil syscall holder */
	{ .entry = &syscall_statfs },
	{ .entry = &syscall_fstatfs },		/* 100 */
	{ .entry = &syscall_ni_syscall },	/* ioperm */
	{ .entry = &syscall_socketcall },	/* Obsolete implementation of socket syscall */
	{ .entry = &syscall_syslog },
	{ .entry = &syscall_setitimer },
	{ .entry = &syscall_getitimer },		/* 105 */
	{ .entry = &syscall_newstat },
	{ .entry = &syscall_newlstat },
	{ .entry = &syscall_newfstat },
	{ .entry = &syscall_uname },
	{ .entry = &syscall_ni_syscall },		/* 110 */ /* iopl */
	{ .entry = &syscall_vhangup },
	{ .entry = &syscall_ni_syscall },	/* idle */
	{ .entry = &syscall_ni_syscall },	/* vm86old */
	{ .entry = &syscall_wait4 },
	{ .entry = &syscall_swapoff },		/* 115 */
	{ .entry = &syscall_sysinfo },
	{ .entry = &syscall_ipc },		/* Obsolete ipc syscall implementation */
	{ .entry = &syscall_fsync },
	{ .entry = &syscall_sigreturn },
	{ .entry = &syscall_clone },			/* 120 */
	{ .entry = &syscall_setdomainname },
	{ .entry = &syscall_newuname },
	{ .entry = &syscall_sh_cacheflush },	/* x86: sys_modify_ldt */
	{ .entry = &syscall_adjtimex },
	{ .entry = &syscall_mprotect },		/* 125 */
	{ .entry = &syscall_sigprocmask },
	{ .entry = &syscall_ni_syscall },		/* old "create_module" */
	{ .entry = &syscall_init_module },
	{ .entry = &syscall_delete_module },
	{ .entry = &syscall_ni_syscall },		/* 130: old "get_kernel_syms" */
	{ .entry = &syscall_quotactl },
	{ .entry = &syscall_getpgid },
	{ .entry = &syscall_fchdir },
	{ .entry = &syscall_bdflush },
	{ .entry = &syscall_sysfs },			/* 135 */
	{ .entry = &syscall_personality },
	{ .entry = &syscall_ni_syscall },	/* for afs_syscall */
	{ .entry = &syscall_setfsuid16 },
	{ .entry = &syscall_setfsgid16 },
	{ .entry = &syscall_llseek },		/* 140 */
	{ .entry = &syscall_getdents },
	{ .entry = &syscall_select },
	{ .entry = &syscall_flock },
	{ .entry = &syscall_msync },
	{ .entry = &syscall_readv },			/* 145 */
	{ .entry = &syscall_writev },
	{ .entry = &syscall_getsid },
	{ .entry = &syscall_fdatasync },
	{ .entry = &syscall_sysctl },
	{ .entry = &syscall_mlock },			/* 150 */
	{ .entry = &syscall_munlock },
	{ .entry = &syscall_mlockall },
	{ .entry = &syscall_munlockall },
	{ .entry = &syscall_sched_setparam },
	{ .entry = &syscall_sched_getparam },	/* 155 */
	{ .entry = &syscall_sched_setscheduler },
	{ .entry = &syscall_sched_getscheduler },
	{ .entry = &syscall_sched_yield },
	{ .entry = &syscall_sched_get_priority_max },
	{ .entry = &syscall_sched_get_priority_min },  /* 160 */
	{ .entry = &syscall_sched_rr_get_interval },
	{ .entry = &syscall_nanosleep },
	{ .entry = &syscall_mremap },
	{ .entry = &syscall_setresuid16 },
	{ .entry = &syscall_getresuid16 },		/* 165 */
	{ .entry = &syscall_ni_syscall },	/* vm86 */
	{ .entry = &syscall_ni_syscall },	/* old "query_module" */
	{ .entry = &syscall_poll },
	{ .entry = &syscall_ni_syscall },	/* was nfsservctl */
	{ .entry = &syscall_setresgid16 },		/* 170 */
	{ .entry = &syscall_getresgid16 },
	{ .entry = &syscall_prctl },
	{ .entry = &syscall_rt_sigreturn },
	{ .entry = &syscall_rt_sigaction },
	{ .entry = &syscall_rt_sigprocmask },	/* 175 */
	{ .entry = &syscall_rt_sigpending },
	{ .entry = &syscall_rt_sigtimedwait },
	{ .entry = &syscall_rt_sigqueueinfo },
	{ .entry = &syscall_rt_sigsuspend },
	{ .entry = &syscall_pread64 },		/* 180 */
	{ .entry = &syscall_pwrite64 },
	{ .entry = &syscall_chown16 },
	{ .entry = &syscall_getcwd },
	{ .entry = &syscall_capget },
	{ .entry = &syscall_capset },		/* 185 */
	{ .entry = &syscall_sigaltstack },
	{ .entry = &syscall_sendfile },
	{ .entry = &syscall_ni_syscall },	/* getpmsg */
	{ .entry = &syscall_ni_syscall },	/* putpmsg */
	{ .entry = &syscall_vfork },			/* 190 */
	{ .entry = &syscall_getrlimit },
	{ .entry = &syscall_mmap2 },
	{ .entry = &syscall_truncate64 },
	{ .entry = &syscall_ftruncate64 },
	{ .entry = &syscall_stat64 },		/* 195 */
	{ .entry = &syscall_lstat64 },
	{ .entry = &syscall_fstat64 },
	{ .entry = &syscall_lchown },
	{ .entry = &syscall_getuid },
	{ .entry = &syscall_getgid },		/* 200 */
	{ .entry = &syscall_geteuid },
	{ .entry = &syscall_getegid },
	{ .entry = &syscall_setreuid },
	{ .entry = &syscall_setregid },
	{ .entry = &syscall_getgroups },		/* 205 */
	{ .entry = &syscall_setgroups },
	{ .entry = &syscall_fchown },
	{ .entry = &syscall_setresuid },
	{ .entry = &syscall_getresuid },
	{ .entry = &syscall_setresgid },		/* 210 */
	{ .entry = &syscall_getresgid },
	{ .entry = &syscall_chown },
	{ .entry = &syscall_setuid },
	{ .entry = &syscall_setgid },
	{ .entry = &syscall_setfsuid },		/* 215 */
	{ .entry = &syscall_setfsgid },
	{ .entry = &syscall_pivot_root },
	{ .entry = &syscall_mincore },
	{ .entry = &syscall_madvise },
	/* Broken-out socket family (maintain backwards compatibility in syscall
	   numbering with 2.4) */
	{ .entry = &syscall_socket },		/* 220 */
	{ .entry = &syscall_bind },
	{ .entry = &syscall_connect },
	{ .entry = &syscall_listen },
	{ .entry = &syscall_accept },
	{ .entry = &syscall_getsockname },		/* 225 */
	{ .entry = &syscall_getpeername },
	{ .entry = &syscall_socketpair },
	{ .entry = &syscall_send },
	{ .entry = &syscall_sendto },
	{ .entry = &syscall_recv },			/* 230*/
	{ .entry = &syscall_recvfrom },
	{ .entry = &syscall_shutdown },
	{ .entry = &syscall_setsockopt },
	{ .entry = &syscall_getsockopt },
	{ .entry = &syscall_sendmsg },		/* 235 */
	{ .entry = &syscall_recvmsg },
	/* Broken-out IPC family (maintain backwards compatibility in syscall
	   numbering with 2.4) */
	{ .entry = &syscall_semop },
	{ .entry = &syscall_semget },
	{ .entry = &syscall_semctl },
	{ .entry = &syscall_msgsnd },		/* 240 */
	{ .entry = &syscall_msgrcv },
	{ .entry = &syscall_msgget },
	{ .entry = &syscall_msgctl },
	{ .entry = &syscall_shmat },
	{ .entry = &syscall_shmdt },			/* 245 */
	{ .entry = &syscall_shmget },
	{ .entry = &syscall_shmctl },
	/* Rest of syscalls listed in 2.4 i386 unistd.h */
	{ .entry = &syscall_getdents64 },
	{ .entry = &syscall_fcntl },			/* fcntl64 */
	{ .entry = &syscall_ni_syscall },		/* 250 reserved for TUX */
	{ .entry = &syscall_ni_syscall },		/* Reserved for Security */
	{ .entry = &syscall_gettid },
	{ .entry = &syscall_readahead },
	{ .entry = &syscall_setxattr },
	{ .entry = &syscall_lsetxattr },		/* 255 */
	{ .entry = &syscall_fsetxattr },
	{ .entry = &syscall_getxattr },
	{ .entry = &syscall_lgetxattr },
	{ .entry = &syscall_fgetxattr },
	{ .entry = &syscall_listxattr },		/* 260 */
	{ .entry = &syscall_llistxattr },
	{ .entry = &syscall_flistxattr },
	{ .entry = &syscall_removexattr },
	{ .entry = &syscall_lremovexattr },
	{ .entry = &syscall_fremovexattr },  	/* 265 */
	{ .entry = &syscall_tkill },
	{ .entry = &syscall_sendfile64 },
	{ .entry = &syscall_futex },
	{ .entry = &syscall_sched_setaffinity },
	{ .entry = &syscall_sched_getaffinity },	/* 270 */
	{ .entry = &syscall_ni_syscall },		/* reserved for set_thread_area */
	{ .entry = &syscall_ni_syscall },		/* reserved for get_thread_area */
	{ .entry = &syscall_io_setup },
	{ .entry = &syscall_io_destroy },
	{ .entry = &syscall_io_getevents },		/* 275 */
	{ .entry = &syscall_io_submit },
	{ .entry = &syscall_io_cancel },
	{ .entry = &syscall_fadvise64 },
	{ .entry = &syscall_ni_syscall },
	{ .entry = &syscall_exit_group },		/* 280 */
	/* Rest of new 2.6 syscalls */
	{ .entry = &syscall_lookup_dcookie },
	{ .entry = &syscall_epoll_create },
	{ .entry = &syscall_epoll_ctl },
	{ .entry = &syscall_epoll_wait },
	{ .entry = &syscall_remap_file_pages },	/* 285 */
	{ .entry = &syscall_set_tid_address },
	{ .entry = &syscall_timer_create },
	{ .entry = &syscall_timer_settime },
	{ .entry = &syscall_timer_gettime },
	{ .entry = &syscall_timer_getoverrun },	/* 290 */
	{ .entry = &syscall_timer_delete },
	{ .entry = &syscall_clock_settime },
	{ .entry = &syscall_clock_gettime },
	{ .entry = &syscall_clock_getres },
	{ .entry = &syscall_clock_nanosleep },	/* 295 */
	{ .entry = &syscall_statfs64 },
	{ .entry = &syscall_fstatfs64 },
	{ .entry = &syscall_tgkill },
	{ .entry = &syscall_utimes },
	{ .entry = &syscall_fadvise64_64 },		/* 300 */
	{ .entry = &syscall_ni_syscall },	/* Reserved for vserver */
	{ .entry = &syscall_ni_syscall },	/* Reserved for mbind */
	{ .entry = &syscall_ni_syscall },	/* get_mempolicy */
	{ .entry = &syscall_ni_syscall },	/* set_mempolicy */
	{ .entry = &syscall_mq_open },		/* 305 */
	{ .entry = &syscall_mq_unlink },
	{ .entry = &syscall_mq_timedsend },
	{ .entry = &syscall_mq_timedreceive },
	{ .entry = &syscall_mq_notify },
	{ .entry = &syscall_mq_getsetattr },		/* 310 */
	{ .entry = &syscall_ni_syscall },	/* Reserved for kexec */
	{ .entry = &syscall_waitid },
	{ .entry = &syscall_add_key },
	{ .entry = &syscall_request_key },
	{ .entry = &syscall_keyctl },		/* 315 */
	{ .entry = &syscall_ioprio_set },
	{ .entry = &syscall_ioprio_get },
	{ .entry = &syscall_inotify_init },
	{ .entry = &syscall_inotify_add_watch },
	{ .entry = &syscall_inotify_rm_watch },	/* 320 */
	{ .entry = &syscall_ni_syscall },
	{ .entry = &syscall_migrate_pages },
	{ .entry = &syscall_openat },
	{ .entry = &syscall_mkdirat },
	{ .entry = &syscall_mknodat },		/* 325 */
	{ .entry = &syscall_fchownat },
	{ .entry = &syscall_futimesat },
	{ .entry = &syscall_fstatat64 },
	{ .entry = &syscall_unlinkat },
	{ .entry = &syscall_renameat },		/* 330 */
	{ .entry = &syscall_linkat },
	{ .entry = &syscall_symlinkat },
	{ .entry = &syscall_readlinkat },
	{ .entry = &syscall_fchmodat },
	{ .entry = &syscall_faccessat },		/* 335 */
	{ .entry = &syscall_pselect6 },
	{ .entry = &syscall_ppoll },
	{ .entry = &syscall_unshare },
	{ .entry = &syscall_set_robust_list },
	{ .entry = &syscall_get_robust_list },	/* 340 */
	{ .entry = &syscall_splice },
	{ .entry = &syscall_sync_file_range },
	{ .entry = &syscall_tee },
	{ .entry = &syscall_vmsplice },
	{ .entry = &syscall_move_pages },		/* 345 */
	{ .entry = &syscall_getcpu },
	{ .entry = &syscall_epoll_pwait },
	{ .entry = &syscall_utimensat },
	{ .entry = &syscall_signalfd },
	{ .entry = &syscall_timerfd_create },	/* 350 */
	{ .entry = &syscall_eventfd },
	{ .entry = &syscall_fallocate },
	{ .entry = &syscall_timerfd_settime },
	{ .entry = &syscall_timerfd_gettime },
	{ .entry = &syscall_signalfd4 },		/* 355 */
	{ .entry = &syscall_eventfd2 },
	{ .entry = &syscall_epoll_create1 },
	{ .entry = &syscall_dup3 },
	{ .entry = &syscall_pipe2 },
	{ .entry = &syscall_inotify_init1 },		/* 360 */
	{ .entry = &syscall_preadv },
	{ .entry = &syscall_pwritev },
	{ .entry = &syscall_rt_tgsigqueueinfo },
	{ .entry = &syscall_perf_event_open },
	{ .entry = &syscall_recvmmsg },		/* 365 */
	{ .entry = &syscall_accept4 },
	{ .entry = &syscall_fanotify_init },
	{ .entry = &syscall_fanotify_mark },
	{ .entry = &syscall_prlimit64 },
	{ .entry = &syscall_name_to_handle_at },	/* 370 */
	{ .entry = &syscall_open_by_handle_at },
	{ .entry = &syscall_clock_adjtime },
	{ .entry = &syscall_syncfs },
	{ .entry = &syscall_sendmmsg },
	{ .entry = &syscall_setns },			/* 375 */
	{ .entry = &syscall_process_vm_readv },
	{ .entry = &syscall_process_vm_writev },
	{ .entry = &syscall_kcmp },
};
#else

/* arch/sh/kernel/syscalls_32.S */
struct syscalltable syscalls_sh[] = {
	{ .entry = &syscall_restart_syscall },	/* 0  -  old "setup()" system call*/
	{ .entry = &syscall_exit },
	{ .entry = &syscall_fork },
	{ .entry = &syscall_read },
	{ .entry = &syscall_write },
	{ .entry = &syscall_open },		/* 5 */
	{ .entry = &syscall_close },
	{ .entry = &syscall_waitpid },
	{ .entry = &syscall_creat },
	{ .entry = &syscall_link },
	{ .entry = &syscall_unlink },		/* 10 */
	{ .entry = &syscall_execve },
	{ .entry = &syscall_chdir },
	{ .entry = &syscall_time },
	{ .entry = &syscall_mknod },
	{ .entry = &syscall_chmod },		/* 15 */
	{ .entry = &syscall_lchown16 },
	{ .entry = &syscall_ni_syscall },	/* old break syscall holder */
	{ .entry = &syscall_stat },
	{ .entry = &syscall_lseek },
	{ .entry = &syscall_getpid },		/* 20 */
	{ .entry = &syscall_mount },
	{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_oldumount },*/
	{ .entry = &syscall_setuid16 },
	{ .entry = &syscall_getuid16 },
	{ .entry = &syscall_stime },		/* 25 */
	{ .entry = &syscall_ptrace },
	{ .entry = &syscall_alarm },
	/*{ .entry = &syscall_fstat },*/ { .entry = &syscall_ni_syscall },
	{ .entry = &syscall_pause },
	{ .entry = &syscall_utime },		/* 30 */
	{ .entry = &syscall_ni_syscall },	/* old stty syscall holder */
	{ .entry = &syscall_ni_syscall },	/* old gtty syscall holder */
	{ .entry = &syscall_access },
	{ .entry = &syscall_nice },
	{ .entry = &syscall_ni_syscall },	/* 35 */		/* old ftime syscall holder */
	{ .entry = &syscall_sync },
	{ .entry = &syscall_kill },
	{ .entry = &syscall_rename },
	{ .entry = &syscall_mkdir },
	{ .entry = &syscall_rmdir },		/* 40 */
	{ .entry = &syscall_dup },
	{ .entry = &syscall_pipe },
	{ .entry = &syscall_times },
	{ .entry = &syscall_ni_syscall },	/* old prof syscall holder */
	{ .entry = &syscall_brk },		/* 45 */
	{ .entry = &syscall_setgid16 },
	{ .entry = &syscall_getgid16 },
	{ .entry = &syscall_signal },
	{ .entry = &syscall_geteuid16 },
	{ .entry = &syscall_getegid16 },	/* 50 */
	{ .entry = &syscall_acct },
	{ .entry = &syscall_umount },		/* recycled never used phys() */
	{ .entry = &syscall_ni_syscall },	/* old lock syscall holder */
	{ .entry = &syscall_ioctl },
	{ .entry = &syscall_fcntl },		/* 55 */
	{ .entry = &syscall_ni_syscall },	/* old mpx syscall holder */
	{ .entry = &syscall_setpgid },
	{ .entry = &syscall_ni_syscall },	/* old ulimit syscall holder */
	{ .entry = &syscall_ni_syscall },	/* sys_olduname */
	{ .entry = &syscall_umask },		/* 60 */
	{ .entry = &syscall_chroot },
	{ .entry = &syscall_ustat },
	{ .entry = &syscall_dup2 },
	{ .entry = &syscall_getppid },
	{ .entry = &syscall_getpgrp },		/* 65 */
	{ .entry = &syscall_setsid },
	{ .entry = &syscall_sigaction },
	{ .entry = &syscall_sgetmask },
	{ .entry = &syscall_ssetmask },
	{ .entry = &syscall_setreuid16 },	/* 70 */
	{ .entry = &syscall_setregid16 },
	{ .entry = &syscall_sigsuspend },
	{ .entry = &syscall_sigpending },
	{ .entry = &syscall_sethostname },
	{ .entry = &syscall_setrlimit },	/* 75 */
	{ .entry = &syscall_getrlimit }, /* old_getrlimit */
	{ .entry = &syscall_getrusage },
	{ .entry = &syscall_gettimeofday },
	{ .entry = &syscall_settimeofday },
	{ .entry = &syscall_getgroups16 },	/* 80 */
	{ .entry = &syscall_setgroups16 },
	{ .entry = &syscall_ni_syscall },	/* sys_oldselect */
	{ .entry = &syscall_symlink },
	{ .entry = &syscall_lstat },
	{ .entry = &syscall_readlink },		/* 85 */
	{ .entry = &syscall_uselib },
	{ .entry = &syscall_swapon },
	{ .entry = &syscall_reboot },
	{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_old_readdir },*/
	{ .entry = &syscall_mmap },		/* 90 */
	{ .entry = &syscall_munmap },
	{ .entry = &syscall_truncate },
	{ .entry = &syscall_ftruncate },
	{ .entry = &syscall_fchmod },
	{ .entry = &syscall_fchown16 },		/* 95 */
	{ .entry = &syscall_getpriority },
	{ .entry = &syscall_setpriority },
	{ .entry = &syscall_ni_syscall },	/* old profil syscall holder */
	{ .entry = &syscall_statfs },
	{ .entry = &syscall_fstatfs },		/* 100 */
	{ .entry = &syscall_ni_syscall },	/* ioperm */
	{ .entry = &syscall_socketcall },
	{ .entry = &syscall_syslog },
	{ .entry = &syscall_setitimer },
	{ .entry = &syscall_getitimer },	/* 105 */
	{ .entry = &syscall_newstat },
	{ .entry = &syscall_newlstat },
	{ .entry = &syscall_newfstat },
	{ .entry = &syscall_uname },
	{ .entry = &syscall_ni_syscall },	/* 110 */ /* iopl */
	{ .entry = &syscall_vhangup },
	{ .entry = &syscall_ni_syscall },	/* idle */
	{ .entry = &syscall_ni_syscall },	/* vm86old */
	{ .entry = &syscall_wait4 },
	{ .entry = &syscall_swapoff },		/* 115 */
	{ .entry = &syscall_sysinfo },
	{ .entry = &syscall_ipc },
	{ .entry = &syscall_fsync },
	{ .entry = &syscall_sigreturn },
	{ .entry = &syscall_clone },		/* 120 */
	{ .entry = &syscall_setdomainname },
	{ .entry = &syscall_newuname },
	{ .entry = &syscall_sh_cacheflush },	/* x86: sys_modify_ldt */
	{ .entry = &syscall_adjtimex },
	{ .entry = &syscall_mprotect },		/* 125 */
	{ .entry = &syscall_sigprocmask },
	{ .entry = &syscall_ni_syscall },	/* old "create_module" */
	{ .entry = &syscall_init_module },
	{ .entry = &syscall_delete_module },
	{ .entry = &syscall_ni_syscall },	/* 130: old "get_kernel_syms" */
	{ .entry = &syscall_quotactl },
	{ .entry = &syscall_getpgid },
	{ .entry = &syscall_fchdir },
	{ .entry = &syscall_bdflush },
	{ .entry = &syscall_sysfs },		/* 135 */
	{ .entry = &syscall_personality },
	{ .entry = &syscall_ni_syscall },	/* for afs_syscall */
	{ .entry = &syscall_setfsuid16 },
	{ .entry = &syscall_setfsgid16 },
	{ .entry = &syscall_llseek },		/* 140 */
	{ .entry = &syscall_getdents },
	{ .entry = &syscall_select },
	{ .entry = &syscall_flock },
	{ .entry = &syscall_msync },
	{ .entry = &syscall_readv },		/* 145 */
	{ .entry = &syscall_writev },
	{ .entry = &syscall_getsid },
	{ .entry = &syscall_fdatasync },
	{ .entry = &syscall_sysctl },
	{ .entry = &syscall_mlock },		/* 150 */
	{ .entry = &syscall_munlock },
	{ .entry = &syscall_mlockall },
	{ .entry = &syscall_munlockall },
	{ .entry = &syscall_sched_setparam },
	{ .entry = &syscall_sched_getparam },   /* 155 */
	{ .entry = &syscall_sched_setscheduler },
	{ .entry = &syscall_sched_getscheduler },
	{ .entry = &syscall_sched_yield },
	{ .entry = &syscall_sched_get_priority_max },
	{ .entry = &syscall_sched_get_priority_min },  /* 160 */
	{ .entry = &syscall_sched_rr_get_interval },
	{ .entry = &syscall_nanosleep },
	{ .entry = &syscall_mremap },
	{ .entry = &syscall_setresuid16 },
	{ .entry = &syscall_getresuid16 },	/* 165 */
	{ .entry = &syscall_ni_syscall },	/* vm86 */
	{ .entry = &syscall_ni_syscall },	/* old "query_module" */
	{ .entry = &syscall_poll },
	{ .entry = &syscall_ni_syscall },	/* was nfsservctl */
	{ .entry = &syscall_setresgid16 },	/* 170 */
	{ .entry = &syscall_getresgid16 },
	{ .entry = &syscall_prctl },
	{ .entry = &syscall_rt_sigreturn },
	{ .entry = &syscall_rt_sigaction },
	{ .entry = &syscall_rt_sigprocmask },	/* 175 */
	{ .entry = &syscall_rt_sigpending },
	{ .entry = &syscall_rt_sigtimedwait },
	{ .entry = &syscall_rt_sigqueueinfo },
	{ .entry = &syscall_rt_sigsuspend },
	{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_pread_wrapper },*/	   /* 180 */
	{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_pwrite_wrapper },*/
	{ .entry = &syscall_chown16 },
	{ .entry = &syscall_getcwd },
	{ .entry = &syscall_capget },
	{ .entry = &syscall_capset },           /* 185 */
	{ .entry = &syscall_sigaltstack },
	{ .entry = &syscall_sendfile },
	{ .entry = &syscall_ni_syscall },	/* getpmsg */
	{ .entry = &syscall_ni_syscall },	/* putpmsg */
	{ .entry = &syscall_vfork },            /* 190 */
	{ .entry = &syscall_getrlimit },
	{ .entry = &syscall_mmap2 },
	{ .entry = &syscall_truncate64 },
	{ .entry = &syscall_ftruncate64 },
	{ .entry = &syscall_stat64 },		/* 195 */
	{ .entry = &syscall_lstat64 },
	{ .entry = &syscall_fstat64 },
	{ .entry = &syscall_lchown },
	{ .entry = &syscall_getuid },
	{ .entry = &syscall_getgid },		/* 200 */
	{ .entry = &syscall_geteuid },
	{ .entry = &syscall_getegid },
	{ .entry = &syscall_setreuid },
	{ .entry = &syscall_setregid },
	{ .entry = &syscall_getgroups },	/* 205 */
	{ .entry = &syscall_setgroups },
	{ .entry = &syscall_fchown },
	{ .entry = &syscall_setresuid },
	{ .entry = &syscall_getresuid },
	{ .entry = &syscall_setresgid },	/* 210 */
	{ .entry = &syscall_getresgid },
	{ .entry = &syscall_chown },
	{ .entry = &syscall_setuid },
	{ .entry = &syscall_setgid },
	{ .entry = &syscall_setfsuid },		/* 215 */
	{ .entry = &syscall_setfsgid },
	{ .entry = &syscall_pivot_root },
	{ .entry = &syscall_mincore },
	{ .entry = &syscall_madvise },
	{ .entry = &syscall_getdents64 },	/* 220 */
	{ .entry = &syscall_fcntl },		/* fcntl64 */
	{ .entry = &syscall_ni_syscall },	/* reserved for TUX */
	{ .entry = &syscall_ni_syscall },	/* Reserved for Security */
	{ .entry = &syscall_gettid },
	{ .entry = &syscall_readahead },	/* 225 */
	{ .entry = &syscall_setxattr },
	{ .entry = &syscall_lsetxattr },
	{ .entry = &syscall_fsetxattr },
	{ .entry = &syscall_getxattr },
	{ .entry = &syscall_lgetxattr },	/* 230 */
	{ .entry = &syscall_fgetxattr },
	{ .entry = &syscall_listxattr },
	{ .entry = &syscall_llistxattr },
	{ .entry = &syscall_flistxattr },
	{ .entry = &syscall_removexattr },	/* 235 */
	{ .entry = &syscall_lremovexattr },
	{ .entry = &syscall_fremovexattr },
	{ .entry = &syscall_tkill },
	{ .entry = &syscall_sendfile64 },
	{ .entry = &syscall_futex },		/* 240 */
	{ .entry = &syscall_sched_setaffinity },
	{ .entry = &syscall_sched_getaffinity },
	{ .entry = &syscall_ni_syscall },	/* reserved for set_thread_area */
	{ .entry = &syscall_ni_syscall },	/* reserved for get_thread_area */
	{ .entry = &syscall_io_setup },	/* 245 */
	{ .entry = &syscall_io_destroy },
	{ .entry = &syscall_io_getevents },
	{ .entry = &syscall_io_submit },
	{ .entry = &syscall_io_cancel },
	{ .entry = &syscall_fadvise64 },	/* 250 */
	{ .entry = &syscall_ni_syscall },
	{ .entry = &syscall_exit_group },
	{ .entry = &syscall_lookup_dcookie },
	{ .entry = &syscall_epoll_create },
	{ .entry = &syscall_epoll_ctl },	/* 255 */
	{ .entry = &syscall_epoll_wait },
	{ .entry = &syscall_remap_file_pages },
	{ .entry = &syscall_set_tid_address },
	{ .entry = &syscall_timer_create },
	{ .entry = &syscall_timer_settime },		/* 260 */
	{ .entry = &syscall_timer_gettime },
	{ .entry = &syscall_timer_getoverrun },
	{ .entry = &syscall_timer_delete },
	{ .entry = &syscall_clock_settime },
	{ .entry = &syscall_clock_gettime },		/* 265 */
	{ .entry = &syscall_clock_getres },
	{ .entry = &syscall_clock_nanosleep },
	{ .entry = &syscall_statfs64 },
	{ .entry = &syscall_fstatfs64 },
	{ .entry = &syscall_tgkill },		/* 270 */
	{ .entry = &syscall_utimes },
	{ .entry = &syscall_ni_syscall }, /*{ .entry = &syscall_fadvise64_64_wrapper },*/
	{ .entry = &syscall_ni_syscall },	/* Reserved for vserver */
	{ .entry = &syscall_mbind },
	{ .entry = &syscall_get_mempolicy },		/* 275 */
	{ .entry = &syscall_set_mempolicy },
	{ .entry = &syscall_mq_open },
	{ .entry = &syscall_mq_unlink },
	{ .entry = &syscall_mq_timedsend },
	{ .entry = &syscall_mq_timedreceive },       /* 280 */
	{ .entry = &syscall_mq_notify },
	{ .entry = &syscall_mq_getsetattr },
	{ .entry = &syscall_kexec_load },
	{ .entry = &syscall_waitid },
	{ .entry = &syscall_add_key },		/* 285 */
	{ .entry = &syscall_request_key },
	{ .entry = &syscall_keyctl },
	{ .entry = &syscall_ioprio_set },
	{ .entry = &syscall_ioprio_get },
	{ .entry = &syscall_inotify_init },		/* 290 */
	{ .entry = &syscall_inotify_add_watch },
	{ .entry = &syscall_inotify_rm_watch },
	{ .entry = &syscall_ni_syscall },
	{ .entry = &syscall_migrate_pages },
	{ .entry = &syscall_openat },		/* 295 */
	{ .entry = &syscall_mkdirat },
	{ .entry = &syscall_mknodat },
	{ .entry = &syscall_fchownat },
	{ .entry = &syscall_futimesat },
	{ .entry = &syscall_fstatat64 },		/* 300 */
	{ .entry = &syscall_unlinkat },
	{ .entry = &syscall_renameat },
	{ .entry = &syscall_linkat },
	{ .entry = &syscall_symlinkat },
	{ .entry = &syscall_readlinkat },		/* 305 */
	{ .entry = &syscall_fchmodat },
	{ .entry = &syscall_faccessat },
	{ .entry = &syscall_pselect6 },
	{ .entry = &syscall_ppoll },
	{ .entry = &syscall_unshare },		/* 310 */
	{ .entry = &syscall_set_robust_list },
	{ .entry = &syscall_get_robust_list },
	{ .entry = &syscall_splice },
	{ .entry = &syscall_sync_file_range },
	{ .entry = &syscall_tee },			/* 315 */
	{ .entry = &syscall_vmsplice },
	{ .entry = &syscall_move_pages },
	{ .entry = &syscall_getcpu },
	{ .entry = &syscall_epoll_pwait },
	{ .entry = &syscall_utimensat },		/* 320 */
	{ .entry = &syscall_signalfd },
	{ .entry = &syscall_timerfd_create },
	{ .entry = &syscall_eventfd },
	{ .entry = &syscall_fallocate },
	{ .entry = &syscall_timerfd_settime },	/* 325 */
	{ .entry = &syscall_timerfd_gettime },
	{ .entry = &syscall_signalfd4 },
	{ .entry = &syscall_eventfd2 },
	{ .entry = &syscall_epoll_create1 },
	{ .entry = &syscall_dup3 },			/* 330 */
	{ .entry = &syscall_pipe2 },
	{ .entry = &syscall_inotify_init1 },
	{ .entry = &syscall_preadv },
	{ .entry = &syscall_pwritev },
	{ .entry = &syscall_rt_tgsigqueueinfo },	/* 335 */
	{ .entry = &syscall_perf_event_open },
	{ .entry = &syscall_fanotify_init },
	{ .entry = &syscall_fanotify_mark },
	{ .entry = &syscall_prlimit64 },
	/* Broken-out socket family */
	{ .entry = &syscall_socket },		/* 340 */
	{ .entry = &syscall_bind },
	{ .entry = &syscall_connect },
	{ .entry = &syscall_listen },
	{ .entry = &syscall_accept },
	{ .entry = &syscall_getsockname },	/* 345 */
	{ .entry = &syscall_getpeername },
	{ .entry = &syscall_socketpair },
	{ .entry = &syscall_send },
	{ .entry = &syscall_sendto },
	{ .entry = &syscall_recv },			/* 350 */
	{ .entry = &syscall_recvfrom },
	{ .entry = &syscall_shutdown },
	{ .entry = &syscall_setsockopt },
	{ .entry = &syscall_getsockopt },
	{ .entry = &syscall_sendmsg },		/* 355 */
	{ .entry = &syscall_recvmsg },
	{ .entry = &syscall_recvmmsg },
	{ .entry = &syscall_accept4 },
	{ .entry = &syscall_name_to_handle_at },
	{ .entry = &syscall_open_by_handle_at },	/* 360 */
	{ .entry = &syscall_clock_adjtime },
	{ .entry = &syscall_syncfs },
	{ .entry = &syscall_sendmmsg },
	{ .entry = &syscall_setns },
	{ .entry = &syscall_process_vm_readv },	/* 365 */
	{ .entry = &syscall_process_vm_writev },
	{ .entry = &syscall_kcmp },
};
#endif
