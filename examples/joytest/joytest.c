#include <string.h>
#include <cpm.h>
#include <joy.h>

/*
#define JOY_MAP_LEFT      0b00000100
#define JOY_MAP_RIGHT     0b00100000
#define JOY_MAP_UP        0b10000000
#define JOY_MAP_DOWN      0b01000000
#define JOY_MAP_BUTTON    0b00000001
*/

void print_joy(uint8_t j)
{
  if (j & JOY_MAP_LEFT)
    puts("LEFT\n");
  else if (j & JOY_MAP_RIGHT)
    puts("RIGHT\n");
  else if (j & JOY_MAP_UP)
    puts("UP\n");
  else if (j & JOY_MAP_DOWN)
    puts("DOWN\n");
  else if (j & JOY_MAP_BUTTON)
    puts("BUTTON\n");
/*
  else if (j & (JOY_MAP_LEFT|JOY_MAP_UP))
    puts("LEFT UP\n");
  else if (j & (JOY_MAP_LEFT|JOY_MAP_DOWN))
    puts("LEFT DOWN\n");
  else if (j & (JOY_MAP_RIGHT|JOY_MAP_UP))
    puts("RIGHT UP\n");
  else if (j & (JOY_MAP_RIGHT|JOY_MAP_DOWN))
    puts("RIGHT DOWN\n");
*/
  else
    puts("CENTER\n");
}

void main()
{
  uint8_t j0, j1;

  while (cpm_rawio() != 0x1b)
  {
    j0 = joy(0);
    j1 = joy(1);
    puts("Joy 0: ");
    print_joy(j0);
    puts("Joy 1: ");
    print_joy(j1);
  }
}
