#include "core.h"
#include "string.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdint.h>
#include "malloc.h"

#define print_kvd(s, v) print_kv(s, v, 8, 10)
#define print_kvh(s, v) print_kv(s, v, 5, 16)

char buf[64];
void *p;

bool print_kv(const char *k, size_t v, uint8_t l, uint8_t base) {
  strcpy(buf, k);
  itoa(v, buf + strlen(k), l, base);
  printstr(buf);
  return true;
}


void main() {
  void* b;
  p = getsp();
  print_kvh("\r\nsbrk(0x0)      ", (uintptr_t)sbrk(0));
  //b = malloc(0x200);
  //print_kvh("\r\nmalloc ret:    ", (uint16_t)&b);
  b = sbrk(0xc9a8);
  print_kvh("\r\nsbrk(0xc9a8)   ", (uintptr_t)b);
  print_kvh("\r\nsbrk(0x0)      ", (uintptr_t)sbrk(0));
  print_kvh("\r\nStack Pointer: ", _STACK);
  print_kvh("\r\nNew Stack ptr: ", (size_t)p);
  free_all();
}

