#include "string.h"
#include <stdint.h>

static void my_strrev(char *str) {
  uint16_t len = strlen(str);
  uint16_t i, j;
  for (i = 0, j = len - 1; i < j; i++, j--) {
    uint8_t a = str[i];
    str[i] = str[j];
    str[j] = a;
  }
}

void itoa(uint16_t val, char *buf) {
  uint8_t i = 0;
  do {
    uint8_t digit = val % 10;
    buf[i++] = '0' + digit;
    val /= 10;
  } while (val);
  buf[i] = '\0';
  my_strrev(buf);
}
