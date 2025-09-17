#include <cpm.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void main()
{
  char *argv[16];
  char c;
  size_t i;
  uint8_t argc = cpm_parse_args(argv);

  for (i=0; i<argc; ++i)
  {
    puts("\r\n");
    puts(argv[i]);
  }
  puts("\r\n");

  puts("\r\npress a key\r\n");
  for (;;)
  {
    c = cpm_rawio();
    if (c) break;
  }
  printf("You pressed : %c\n", c);
  i = printf("Hello, %s\n", "Dave Latham");
  printf("The number of chars written was: %d\n", i);
  printf("You are %d years old.\n", 50);
  printf("Your rom starts at 0x%x.\n", 0xD400);
}
