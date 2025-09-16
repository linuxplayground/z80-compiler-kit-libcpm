#include <cpm.h>
#include <core.h>
#include <stdlib.h>
#include <stdio.h>

void main()
{
  char **argv;
  char c;
  size_t i;
  uint8_t argc = cpm_parse_args(&*argv);

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
  printf("Hello, %s\n", "Dave Latham");
  printf("You are %d years old.\n", 50);
  printf("Your rom starts at %x.\n", 0xD400);
}
