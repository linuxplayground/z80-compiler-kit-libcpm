#include <malloc.h>
#include <string.h>

/*
 * Simple demonstration of the use of malloc an free.
 * In this test we see the top of the heap growing higher.
 * When buf1 is freed the breakline remainst constant even
 * when buf1 is re-allocated.  Proving that the memory
 * allocator functions do work.
 *
 * They are no perfect though.  So use carefully.
*/
void main()
{
  char *buf1;
  char *buf2;

  puts("\r\nMalloc and Free tests");
  print_kvh("\r\nBreakline is at 0x", (uintptr_t)sbrk(0));

  puts("\r\n\r\nAllocating buf1. (2048)");
  buf1 = malloc(2048);    // Allocate 2048 bytes
  print_kvh("\r\nAddress of buf1 is: 0x",(uintptr_t)buf1);
  print_kvh("\r\nBreakline is at 0x", (uintptr_t)sbrk(0));
  puts("\r\n\r\nAllocating buf2. (1024)");
  buf2 = malloc(1024);
  print_kvh("\r\nAddress of buf2 is: 0x",(uintptr_t)buf2);
  print_kvh("\r\nBreakline is at 0x", (uintptr_t)sbrk(0));

  puts("\r\n\r\nFreeing buf1");
  free(buf1);
  print_kvh("\r\nBreakline is at 0x", (uintptr_t)sbrk(0));

  puts("\r\n\r\nAllocate buf1 again. 1024");
  buf1 = malloc(1024);
  print_kvh("\r\nAddress of buf1 is: 0x",(uintptr_t)buf1);
  print_kvh("\r\nBreakline is at 0x", (uintptr_t)sbrk(0));

  puts("\r\nFree buf2");
  free(buf2);
  print_kvh("\r\nBreakline is at 0x", (uintptr_t)sbrk(0));
}

