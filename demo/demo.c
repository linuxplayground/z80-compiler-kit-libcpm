#include "tms_patterns.h"
#include <cpm.h>
#include <string.h>
#include <tms.h>

#define SPEED 2

char ball[16 * 4] = {0x0a, 0xa0, 0x0a, 0xa0, 0x0a, 0xa0, 0x0a, 0xa0,
                     0x0a, 0xa0, 0x0a, 0xa0, 0x0a, 0xa0, 0x0a, 0xa0,
                     0x0a, 0xa0, 0x0a, 0xa0, 0x0a, 0xa0, 0x0a, 0xa0,
                     0x0a, 0xa0, 0x0a, 0xa0, 0x0a, 0xa0, 0x0a, 0xa0};

void main() {
  uint8_t len;
  int8_t velx, vely;
  int16_t x,y;

  printstr("Hello, World!\n");
  tms_init_g1(WHITE, DARK_YELLOW, true, false);
  tms_load_pat(tms_patterns, 0x400);
  tms_load_col(tms_g1_colors, 32);
  tms_load_spr(ball, 32);

  sprites[0].y = 0; // set up the ball sprite
  sprites[0].x = 0;
  sprites[0].pattern = 0;
  sprites[0].color = DARK_GREEN;

  sprites[1].y = 0xD0; // disables sprite processing after the ball.

  len = strlen("Hello, World!");
  tms_print_xy(15 - (len / 2), 24 / 2, "Hello, World!");

  velx = SPEED;
  vely = SPEED;

  x = sprites[0].x;
  y = sprites[0].y;

  while (cpm_rawio() != 0x1b) {

    y += vely;
    x += velx;

    if (x <= 0) velx *= -1;
    if (x >= (255-16)) velx *= -1;
    if (y <= 0) vely *= -1;
    if (y >= (191-16)) vely *= -1;


    sprites[0].y = y;
    sprites[0].x = x;

    tms_wait();
    // tms_g1flush(tms_buf);
    tms_flush_sprites();
  }
}
