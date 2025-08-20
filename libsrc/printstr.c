#include "sio.h"

void printstr(char *s) {
  do {
    chout(*s);
  } while (*s++ != 0);
}
