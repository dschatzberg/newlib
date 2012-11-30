#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <sys/times.h>
#include <sys/errno.h>
#include <sys/time.h>
#include <stdarg.h>
#include <stdio.h>
#include <errno.h>


extern int ebbrt_newlib_exit(int);
extern int ebbrt_newlib_execve(char *, char **, char **);
extern int ebbrt_newlib_getpid(void);
extern int ebbrt_newlib_fork(void);
extern int ebbrt_newlib_kill(int, int);
extern int ebbrt_newlib_wait(int *);
extern int ebbrt_newlib_isatty(int);
extern int ebbrt_newlib_close(int);
extern int ebbrt_newlib_link(char *, char *);
extern int ebbrt_newlib_lseek(int, int, int);
extern int ebbrt_newlib_open(const char *, int, va_list);
extern int ebbrt_newlib_read(int, char *, int);
extern int ebbrt_newlib_fstat(int, struct stat *);
extern int ebbrt_newlib_stat(const char *, struct stat *);
extern int ebbrt_newlib_unlink(char *);
extern int ebbrt_newlib_write(int, char *, int);
extern caddr_t ebbrt_newlib_sbrk(int);
extern int ebbrt_newlib_gettimeofday(struct timeval *, void *);

int _exit(int val)
{
  return ebbrt_newlib_exit(val);
}

int execve(char *name, char **argv, char **env)
{
  return ebbrt_newlib_execve(name, argv, env);
}

int getpid(void)
{
  return ebbrt_newlib_getpid();
}

int fork(void)
{
  return ebbrt_newlib_fork();
}

int kill(int pid, int sig)
{
  return ebbrt_newlib_kill(pid, sig);
}

int wait(int *status)
{
  return ebbrt_newlib_wait(status);
}

int isatty(int fd)
{
  return ebbrt_newlib_isatty(fd);
}

int close(int file)
{
  return ebbrt_newlib_close(file);
}

int link(char *old, char *new)
{
  return ebbrt_newlib_link(old, new);
}

int lseek(int file, int ptr, int dir)
{
  return ebbrt_newlib_lseek(file, ptr, dir);
}

int open(const char *name, int flags, ...)
{
  va_list args;
  int ret;
  va_start(args, flags);
  ret = ebbrt_newlib_open(name, flags, args);
  va_end(args);
  return ret;
}

int read(int file, char *ptr, int len)
{
  return ebbrt_newlib_read(file, ptr, len);
}

int fstat(int file, struct stat *st)
{
  return ebbrt_newlib_fstat(file, st);
}

int stat(const char *file, struct stat *st)
{
  return ebbrt_newlib_stat(file, st);
}

int unlink(char *name)
{
  return ebbrt_newlib_unlink(name);
}

int write(int file, char *ptr, int len)
{
  return ebbrt_newlib_write(file, ptr, len);
}

caddr_t sbrk(int incr)
{
  return ebbrt_newlib_sbrk(incr);
}

int gettimeofday(struct timeval *p, void *z)
{
  return ebbrt_newlib_gettimeofday(p, z);
}
