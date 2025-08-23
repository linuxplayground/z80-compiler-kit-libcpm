#include "string.h"
#include <stdint.h>

char *strchr(char *str, uint8_t ch) {
  char *s = str;

  if (*str == ch)
    return ((char *)s);

  while (*s) {
    if (*s == (char)ch)
      return s;
    s++;
  }
  return NULL;
}
