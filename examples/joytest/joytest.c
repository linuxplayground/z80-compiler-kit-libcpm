#include <stdio.h>
#include <joy.h>
#include <stdlib.h>
#include <cpm.h>


void main()
{
  char c;
  bool running = true;
  uint8_t j0 = 0xFF;
  uint8_t j1 = 0xFF;
  printf("\r\nJOYSTICK TESTER: (ESCAPE TO QUIT)\r\n");

  while (running)
  {
    c = cpm_rawio();
    if (c)
    {
      printf("\r\nKEY: %x = %c", c, c);
      if (c == 0x1b) {
        running = false;
      }
    }
    j0 = joy(0);
    if (j0 != j1)
    {
      printf("\r\nJOY: %x",j0);
      j1 = j0;
    }
  }
}
