#include "cpm.h"
#include "sio.h"
#include <stdint.h>
#include <stdbool.h>

int main()
{
  uint8_t n;
  char c;
  char *s;
  char buf[64];

  buf[63] = '$';

  c = conin();
  conout(c);
  writestr("\r\nHello, World!\r\n$");
  buf[0] = 16;
  readstr(buf);

  writestr("\r\nYou typed: $");
  n = buf[1];
  buf[n+2] = '\0';

  printstr(&buf[2]);
  return 0;
}
