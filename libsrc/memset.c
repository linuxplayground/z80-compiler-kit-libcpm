#include "string.h"
#include <stdint.h>

void memset(void *dst, uint8_t c, uint16_t len) {
  char *d = dst;
  while (len-- > 0)
    *d++ = c;
}

