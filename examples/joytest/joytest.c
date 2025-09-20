#include <stdio.h>
#include <cpm.h>
#include <joy.h>

/*
#define JOY_MAP_LEFT      0b00000100
#define JOY_MAP_RIGHT     0b00100000
#define JOY_MAP_UP        0b10000000
#define JOY_MAP_DOWN      0b01000000
#define JOY_MAP_BUTTON    0b00000001
*/

void main()
{
  uint8_t j0 = 0xFF;
  uint8_t j1 = 0xFF;

  printf("\n\nJOYSTICK TESTER: (ESCAPE TO QUIT)\n\n");

  while (cpm_rawio() != 0x1b)
  {
    j0 = joy(0);
    if (j0 != j1)
    {
      printf("LEFT  %s - ",  (j0 & JOY_MAP_LEFT) ?   "UP  " :  "DOWN");
      printf("RIGHT %s - ",  (j0 & JOY_MAP_RIGHT) ?  "UP  " :  "DOWN");
      printf("UP    %s - ",  (j0 & JOY_MAP_UP) ?     "UP  " :  "DOWN");
      printf("DOWN  %s - ",  (j0 & JOY_MAP_DOWN) ?   "UP  " :  "DOWN");
      printf("BTN   %s\n",   (j0 & JOY_MAP_BUTTON) ? "UP  " :  "DOWN");
      j1 = j0;
    }
  }
}
