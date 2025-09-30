#include <stdio.h>
#include <tms.h>
#include <tms_patterns.h>

// solid 8x8 sprite - we are testing collisions and 5th sprite flag etc.
char block[8] = {
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff
};

char colors[32] = {
  0x6e, 0x6e, 0x4e, 0x6e, 0xce, 0xce, 0xce, 0xce,
  0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce, 0xce,
  0x6e, 0x6e, 0x6e, 0x6e, 0x6e, 0x6e, 0x6e, 0x6e,
  0x6e, 0x6e, 0x6e, 0x6e, 0x6e, 0x4e, 0x4e, 0x4e 
};

void main()
{
  uint8_t i;
  uint8_t c = 1;
  uint8_t status;

  tms_init_g1(GRAY, DARK_YELLOW, false, false);
  tms_load_pat(tms_patterns, 0x400);
  tms_load_col(colors, 0x20);
  tms_load_spr(block, 8);

  tms_wait();
  tms_fill_buf(0x20);
  tms_wait();
  tms_g1flush(tms_buf);
  tms_wait();
  tms_g1flush(tms_buf);
  tms_wait();
  tms_g1flush(tms_buf);

  // Place 5 sprites on the top row starting at the top left.
  // 9 pixels apart
  for (i=0; i<5; ++i) {
    sprites[i].y = 0;
    sprites[i].x = 0 + (i*9);
    sprites[i].pattern = 0;
    sprites[i].color = c;
    c++;
  }

  // Place 5 sprites in the middle of the screen
  // 9 pixels apart
  for (i=5; i<10; ++i) {
    sprites[i].y = (191/2)-4;
    sprites[i].x = 0 + (i-5)*9;
    sprites[i].pattern = 0;
    sprites[i].color = c;
    c++;
  }
  // place 5 sprites in the bottom of the screen
  // 9 pixels apart
  for (i=10; i<15; ++i) {
    sprites[i].y = 191-8;
    sprites[i].x = 0 + (i-10)*9;
    sprites[i].pattern = 0;
    sprites[i].color = c;
    c++;
  }
  sprites[15].y = 0xD0;

  // That's 15 sprites.
  tms_wait();
  tms_flush_sprites();
  tms_wait();

  printf("\r\nStatus after flushing sprites is: 0x%x\r\n", tms_status);
}
