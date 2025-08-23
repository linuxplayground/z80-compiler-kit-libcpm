#include "string.h"
#include <stdint.h>

uint16_t strlen(char *str) {
  uint16_t len = 0;
  while (*str++ != '\0')
    len++;
  return len;
}

