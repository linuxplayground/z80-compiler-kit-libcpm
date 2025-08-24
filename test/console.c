#include <stddef.h>
#include <string.h>

#include "core.h"

void print_kv(const char *k, size_t v) {
    char buf[256];
  strcpy(buf, k);
  itoa(v, buf + strlen(k));
  printstr(buf);
}

int main() {

  uintptr_t end = (uintptr_t)&_end;

  print_kv("\r\nSTACK POINTER: ", _STACK);
  print_kv("\r\nHEAP:          ", (size_t)end);
  print_kv("\r\nTPA:           ",TPA);
  return 0;
}
