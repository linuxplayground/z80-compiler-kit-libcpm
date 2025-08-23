#include "string.h"
#include <stdint.h>

void memcpy(void *dst, void *src, uint16_t len) {
  char *s = src;
  char *d = dst;
  while (len-- > 0)
    *d++ = *s++;
}

