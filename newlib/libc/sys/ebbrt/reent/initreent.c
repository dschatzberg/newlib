#include <reent.h>

void ebbrt_init_reent(struct _reent *reent)
{
  _REENT_INIT_PTR(reent);
}
