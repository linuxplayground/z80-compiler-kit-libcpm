#include <stdio.h>
#include <joy.h>
#include <stdlib.h>

#ifdef NABU
#include <nabu.h>
#else
#include <cpm.h>
#endif


void main()
{
  char c;
  bool running = true;
  uint8_t j0 = 0xFF;
  uint8_t j1 = 0xFF;
  printf("\r\nJOYSTICK TESTER: (ESCAPE TO QUIT)\r\n");

  while (running)
  {
#ifdef NABU
    if (nb_kbhit()) {
      c = nb_getc();
#else
    c = cpm_rawio();
    if (c)
    {
#endif
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
