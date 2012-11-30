#include <reent.h>

extern struct _reent *ebbrt_newlib_getreent(void);

struct _reent *
__getreent(void)
{
  return ebbrt_newlib_getreent();
}
