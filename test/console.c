#include <stdbool.h>
#include <stdint.h>

#include <core.h>
#include <malloc.h>
#include <fcntl.h>
#include <string.h>

#define print_kvd(s, v) print_kv(s, v, 8, 10)
#define print_kvh(s, v) print_kv(s, v, 5, 16)

char *b = NULL;
char *c = NULL;
char k;
int8_t n;

bool print_kv(const char *k, size_t v, uint8_t l, uint8_t base) {
  char *buf = malloc(128);
  if (buf == NULL)
    return false;
  strcpy(buf, k);
  itoa(v, buf + strlen(k), l, base);
  printstr(buf);
  free(buf);
  return true;
}

void main() {
  print_kvh("\r\nsbrk(0x0) [end]            0x", (uintptr_t)sbrk(0));
  b = (char *)malloc(0x2000);
  print_kvh("\r\nsbrk(0x0) [> malloc 0x8k]  0x", (uintptr_t)sbrk(0));

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

  printstr("\r\n");
  while (true)
  {
    if (read(STDIN, &k, 1) == -1)
    {
      printstr("ERROR READING FROM STDIN");
      break;
    }
    if (k == 0x1b)
      break;
    if (write(STDOUT, &k, 1) == -1)
    {
      printstr("ERROR WRITING TO STDOUT");
      break;
    }
  }
}
