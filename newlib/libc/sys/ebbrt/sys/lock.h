#ifndef __SYS_LOCK_H__
#define __SYS_LOCK_H__

typedef void *_LOCK_T;
typedef void *_LOCK_RECURSIVE_T;

extern void ebbrt_newlib_lock_init(_LOCK_T *);
extern void ebbrt_newlib_lock_init_recursive(_LOCK_RECURSIVE_T *);
extern void ebbrt_newlib_lock_close(_LOCK_T *);
extern void ebbrt_newlib_lock_close_recursive(_LOCK_RECURSIVE_T *);
extern void ebbrt_newlib_lock_acquire(_LOCK_T *);
extern void ebbrt_newlib_lock_acquire_recursive(_LOCK_RECURSIVE_T *);
extern int ebbrt_newlib_lock_try_acquire(_LOCK_T *);
extern int ebbrt_newlib_lock_try_acquire_recursive(_LOCK_RECURSIVE_T *);
extern void ebbrt_newlib_lock_release(_LOCK_T *);
extern void ebbrt_newlib_lock_release_recursive(_LOCK_RECURSIVE_T *);

#define __LOCK_INIT(class,lock) \
  class _LOCK_T lock;
#define __LOCK_INIT_RECURSIVE(class,lock) \
  class _LOCK_RECURSIVE_T lock;
#define __lock_init(lock) ebbrt_newlib_lock_init(&lock)
#define __lock_init_recursive(lock) ebbrt_newlib_lock_init_recursive(&lock)
#define __lock_close(lock) ebbrt_newlib_lock_close(&lock)
#define __lock_close_recursive(lock) ebbrt_newlib_lock_close_recursive(&lock)
#define __lock_acquire(lock) ebbrt_newlib_lock_acquire(&lock)
#define __lock_acquire_recursive(lock) ebbrt_newlib_lock_acquire_recursive(&lock)
#define __lock_try_acquire(lock) ebbrt_newlib_lock_try_acquire(&lock)
#define __lock_try_acquire_recursive(lock) ebbrt_newlib_lock_try_acquire_recursive(&lock)
#define __lock_release(lock) ebbrt_newlib_lock_release(&lock)
#define __lock_release_recursive(lock) ebbrt_newlib_lock_release_recursive(&lock)

#endif /* __SYS_LOCK_H__ */
