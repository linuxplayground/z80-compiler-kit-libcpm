#include "cpm.h"
#include "sio.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

static FCB my_fcb;
FCB *fcb = &my_fcb;

char rec[128];

void print_result(uint16_t val, char *buf, char *user) {
  printstr("\r\n");
  itoa(val, buf);
  printstr(buf);
  printstr(user);
  printstr("\r\n");
}

int main() {
  uint8_t n;
  char c;
  char *s;
  char buf[64];

  buf[63] = '$';
#if 0
  c = conin();
  conout(c);
  writestr("\r\nHello, World!\r\n$");
  buf[0] = 16;
  readstr(buf);

  writestr("\r\nYou typed: $");
  n = buf[1];
  buf[n+2] = '\0';

  printstr(&buf[2]);
  printstr("\r\n");
#endif

  if (parse_fcb_filename(fcb, "hello.txt")) {
    n = f_open(fcb);
    // print_result(n, buf, "OPEN");
    f_dmaoff(rec);
    n = f_read(fcb);
    // print_result(n, buf, "READ");

    for (n=0; n<128; ++n) {
      if (rec[n] == 26)
        break;
      conout(rec[n]);
    }
    f_close(fcb);
  } else {
    printstr("Could not open \"hello.txt\"\r\n");
  }
  return 0;
}
