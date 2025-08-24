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

int8_t itoa(uint16_t val, char *str, uint8_t len, uint8_t base)
{
  uint16_t sum = val;
  uint8_t i = 0;
  uint8_t digit;

  if (len == 0)
    return -1;
  do {
    digit = sum % base;
    if (digit < 0xA)
      str[i++] = '0' + digit;
    else
      str[i++] = 'A' + digit - 0xA;
    sum /= base;
  } while (sum && (i < (len-1)));
  str[i] = '\0';
  my_strrev(str);
  return 0;
}
