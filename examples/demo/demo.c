#include "tms_patterns.h"
#include <cpm.h>
#include <string.h>
#include <tms.h>
#include <stdlib.h>

/* - fill the screen with characters every 8th frame
*  - move a sprite around the screen and have it bounce off the walls
*  - sprite moves one pixel every SPEED frames
*/
#define SPEED 2 // lower numbers are faster

// 16x16 ball sprite
char ball[16 * 4] = { 0x07,0x1F,0x3E,0x7C,0x7F,0xFF,0xFF,0xFF,
                      0xFF,0xFF,0xFF,0x7F,0x7F,0x3F,0x1F,0x07,
                      0xE0,0xF8,0x3C,0x0E,0x06,0xC7,0xE3,0xE3,
                      0xF3,0xF7,0xFF,0xFE,0xFE,0xFC,0xF8,0xE0};

void main() {
  uint8_t len, ticks;
  int8_t velx, vely;
  int16_t x,y,acii;

  char *msg_begin = "SPACE to begin then ESC to quit";
  // Write something to the console.
  puts("Hello, World!\n");

  tms_init_g1(WHITE, DARK_YELLOW, true, false);
  tms_load_pat(tms_patterns, 0x400);
  tms_load_col(tms_g1_colors, 32);
  tms_load_spr(ball, 32);

  // clear the screen
  memset(tms_buf,0x20,768);
  tms_wait();
  tms_g1flush(tms_buf);

  sprites[0].y = 0; // set up the ball sprite
  sprites[0].x = 0;
  sprites[0].pattern = 0;
  sprites[0].color = DARK_GREEN;

  sprites[1].y = 0xD0; // disables sprite processing after the ball.

  len = strlen(msg_begin);
  // printing text in the middle of the screen
  tms_puts_xy(16 - (len / 2), 24 / 2, msg_begin);

  tms_wait();
  tms_g1flush(tms_buf);

  // wait for space bar
  while (cpm_rawio() != ' ');
  velx = SPEED;
  vely = SPEED;

  x = sprites[0].x;
  y = sprites[0].y;
  acii = 0x20;
  ticks = 0;
  while (cpm_rawio() != 0x1b) {
    y += vely;
    x += velx;

    if (x <= 0) velx *= -1;
    if (x >= (255-16)) velx *= -1;
    if (y <= -1) vely *= -1;
    if (y >= (191-16))  vely *= -1;

    sprites[0].y = y;
    sprites[0].x = x;

    ticks++;
    if ((ticks & 7) == 0) {
      memset(tms_buf,acii,768);
      acii += 1;
      if (acii > 0x7E) acii = 0x20;
    }
    tms_wait();
    tms_g1flush(tms_buf);
    tms_flush_sprites();
  }
}
