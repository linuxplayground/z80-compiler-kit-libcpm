#include "core.h"
#include <stddef.h>

static void *allocp;

void *malloc(size_t size)
{
  void *tmp = allocp;

  tmp += size;
  if (tmp >= (void*)getsp())
    return (void*)NULL;
  if (sbrk(size) > (void*)-1)
  {
    allocp = tmp;
    return tmp;
  }
  return (void*)NULL;
}

void free_all(void *ptr)
{
  allocp = _end; // Brutally nuke all allocations.
}
