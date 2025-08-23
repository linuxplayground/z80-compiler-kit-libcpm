#include "string.h"
#include <stdint.h>

char toupper(char c) {
  char r;
  if ( (c >= 'a') || (c <= 'z') ) {
    r = c & 0xDF;
  }
  return r;
}

