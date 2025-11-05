#include <stdlib.h>
#include <stdio.h>

/*
 * Simple demonstration of the use of malloc an free.
 * In this test we see the top of the heap growing higher.
 * When buf1 is freed the breakline remainst constant even
 * when buf1 is re-allocated.  Proving that the memory
 * allocator functions do work.
 *
 * They are no perfect though.  So use carefully.
*/
int main()
{
  char *buf1;
  char *buf2;

  puts("\nMalloc and Free tests");
  printf("\nBreakline is at 0x%x", (uintptr_t)_sbrk(0));

  puts("\n\nAllocating buf1. (2048)");
  buf1 = malloc(2048);    // Allocate 2048 bytes
  printf("\nAddress of buf1 is: 0x%x",(uintptr_t)buf1);
  printf("\nBreakline is at 0x%x", (uintptr_t)_sbrk(0));
  puts("\n\nAllocating buf2. (1024)");
  buf2 = malloc(1024);
  printf("\nAddress of buf2 is: 0x%x",(uintptr_t)buf2);
  printf("\nBreakline is at 0x%x", (uintptr_t)_sbrk(0));

  puts("\n\nFreeing buf1");
  free(buf1);
  printf("\nBreakline is at 0x%x", (uintptr_t)_sbrk(0));

  puts("\n\nAllocate buf1 again. 1024");
  buf1 = malloc(1024);
  printf("\nAddress of buf1 is: 0x%x",(uintptr_t)buf1);
  printf("\nBreakline is at 0x%x", (uintptr_t)_sbrk(0));

  puts("\nFree buf2");
  free(buf2);
  printf("\nBreakline is at 0x%x", (uintptr_t)_sbrk(0));

  return 0;
}

