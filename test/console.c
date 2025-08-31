#include <stdbool.h>
#include <stdint.h>

#include <core.h>
#include <malloc.h>
#include <fcntl.h>
#include <string.h>
#include <stddef.h>

char *b = NULL;
char *c = NULL;
char k;
size_t i,j, y, z;
int8_t fd_src, fd_dst;
int8_t n;
char buf[128];

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

  // Find size of a file...
  fd_src = open("dump.asm", O_NULL);
  if (fd_src == -1) {
    printstr("\r\nCould not open dump.asm for reading");
    return;
  }
  fd_dst = open("dump2.txt", O_CREAT);
  if (fd_dst == -1) {
    printstr("\r\nCould not open dump2.asm for writing.");
    return;
  }
  print_kvd("\r\nFD_SRC: ",fd_src);
  print_kvd("\r\nFD_DST: ",fd_dst);

  i = f_size(fd_src);
  print_kvd("\r\nDUMP.ASM is ",i);
  printstr(" blocks long");
  for (j=0; j<i; ++j) {
    read(fd_src, buf, 128);
    cpm_conout('r');
    write(fd_dst, buf, 128);
    cpm_conout('w');
  }
  close(fd_dst);

}
