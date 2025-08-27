#include "core.h"
#include "malloc.h"
#include "string.h"
#include <stdbool.h>
#include <stdint.h>

#define print_kvd(s, v) print_kv(s, v, 8, 10)
#define print_kvh(s, v) print_kv(s, v, 5, 16)

char buf[128];
char *b = NULL;
char *c = NULL;

bool print_kv(const char *k, size_t v, uint8_t l, uint8_t base) {
  strcpy(buf, k);
  itoa(v, buf + strlen(k), l, base);
  printstr(buf);
  return true;
}

void main() {
  print_kvh("\r\nsbrk(0x0) [end]           0x", (uintptr_t)sbrk(0));
  b = (char *)malloc(0x2000);
  print_kvh("\r\nsbrk(0x0) [> malloc 0x8k] 0x", (uintptr_t)sbrk(0));

  printstr("\r\n-------------------");
  print_kvh("\r\nAddress of `b` 0x", (uintptr_t)b);

  c = (char *)malloc(0x100);
  print_kvh("\r\nAddress of `c` 0x", (uintptr_t)c);
  print_kvh("\r\nsbrk(0x0) [> malloc c]     0x", (uintptr_t)sbrk(0));

  free(b);
  print_kvh("\r\nsbrk(0x0) [< free b]       0x", (uintptr_t)sbrk(0));

  b = (char *)malloc(0x100);
  print_kvh("\r\nAddress of `b` 0x", (uintptr_t)b);
  print_kvh("\r\nsbrk(0x0) [> malloc 0x100] 0x", (uintptr_t)sbrk(0));
}
