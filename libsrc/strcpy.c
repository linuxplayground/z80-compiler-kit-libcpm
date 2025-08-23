#include <stdint.h>

void strcpy(char *dst, char *src) {
  char *d = dst;
  char *s = src;
  do {
    *d++ = *s++;
  } while (*s != 0);
}

