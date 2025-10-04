#include <stdio.h>
#include <tms_patterns.h>
#include <tms.h>
#include <joy.h>
#include <cpm.h>
#include <string.h>

#include "colours.h"

// 5 sprites
char sprite_patterns[5*4*8] = {
  0x07,0x1F,0x38,0x70,0x61,0xC1,0xC1,0xC0,
  0xC0,0xC1,0xC1,0x61,0x70,0x38,0x1F,0x07,
  0xE0,0xF8,0x1C,0x0E,0x86,0x83,0x83,0x83,
  0x83,0x83,0x83,0x86,0x0E,0x1C,0xF8,0xE0,
  0x07,0x1F,0x38,0x73,0x63,0xC0,0xC0,0xC1,
  0xC3,0xC3,0xC3,0x63,0x73,0x38,0x1F,0x07,
  0xE0,0xF8,0x1C,0xCE,0xC6,0xC3,0xC3,0xC3,
  0x83,0x03,0x03,0xC6,0xCE,0x1C,0xF8,0xE0,
  0x07,0x1F,0x38,0x73,0x63,0xC0,0xC0,0xC3,
  0xC3,0xC0,0xC0,0x63,0x73,0x38,0x1F,0x07,
  0xE0,0xF8,0x1C,0xCE,0xC6,0xC3,0xC3,0x83,
  0x83,0xC3,0xC3,0xC6,0xCE,0x1C,0xF8,0xE0,
  0x07,0x1F,0x38,0x74,0x6C,0xCC,0xCC,0xCF,
  0xC7,0xC0,0xC0,0x60,0x70,0x38,0x1F,0x07,
  0xE0,0xF8,0x1C,0xCE,0xC6,0xC3,0xC3,0x83,
  0x83,0xC3,0xC3,0xC6,0xCE,0x1C,0xF8,0xE0,
  0x07,0x1F,0x38,0x73,0x63,0xC3,0xC3,0xC3,
  0xC1,0xC0,0xC0,0x63,0x73,0x38,0x1F,0x07,
  0xE0,0xF8,0x1C,0xCE,0xC6,0x03,0x03,0x83,
  0xC3,0xC3,0xC3,0xC6,0xCE,0x1C,0xF8,0xE0
};

char txt[64]; //buffer for text on screen
size_t i;
char c;
uint8_t mag = 0;
uint8_t cur_sp = 0;
bool running = true;
uint8_t jcur = 0;
uint8_t jnext = 0;
uint8_t status = 0;
uint8_t temp;

void print()
{
  memset(&tms_buf[22*32], ' ', 32); // clear the second to last line of the buffer.
  memset(txt,0,64);
  sprintf(txt, "-%c%c %u [ 0x%x ]", (status & 0x40) ? 'S' : '-', (status & 0x20) ? 'C' : '-', status & 0x1F, status);
  tms_puts_xy(0,22,txt);

  memset(&tms_buf[23*32], ' ', 32); // clear the last line of the buffer.
  memset(txt,0,64);
  sprintf(txt, "sp:%u X:%u Y:%u ecb:%u mag:%u", 
          cur_sp + 1,
          sprites[cur_sp].x & 0xFF,
          sprites[cur_sp].y & 0xFF,
          (sprites[cur_sp].color & 0x80) ? 1 : 0,
          mag
  );
  tms_puts_xy(0,23,txt);
}

void main()
{
  tms_init_g1(GRAY, DARK_YELLOW, true, mag);
  tms_load_pat(tms_patterns, 0x400);
  tms_load_col(colors, 32);
  tms_load_spr(sprite_patterns, 5*4*8);

  tms_fill_buf(' ');

  // do this 3 times because timings are still not quite right on the retro.
  tms_wait();
  tms_g1flush(tms_buf);
  tms_wait();
  tms_g1flush(tms_buf);
  tms_wait();
  tms_g1flush(tms_buf);


  //initialize 5 sprites
  for (i=0; i<5; i++)
  {
    sprites[i].y = 16 + (i*18);
    sprites[i].x = 16 + (i*18);
    sprites[i].pattern = i*4;
    sprites[i].color = BLACK;
  }

  sprites[0].color = DARK_RED;

  sprites[5].y = 0xD0; // Sentinel marker

  print();

  tms_wait();
  tms_flush_sprites();

  jcur = 0xFF;
  jnext = 0xFF;

  while (running)
  {
    // press escape to quit
    c = cpm_rawio();
    switch(c)
    {
      case 0x1b:
        running = false;
        break;

      case 'e':   // toggle ecb for current sprite
        if (sprites[cur_sp].color & 0x80) {
          sprites[cur_sp].color &= 0x7F;
        } else {
          sprites[cur_sp].color |= 0x80;
        }
        print();
        break;

      case 'm': // toggle magnification
        mag = !mag;
        tms_set_reg(1, 0xE2 | mag);
        break;

      case 'a':
        sprites[cur_sp].x --;
        break;
      case 's':
        sprites[cur_sp].y ++;
        break;
      case 'd':
      sprites[cur_sp].x ++;
        break;
      case 'w':
        sprites[cur_sp].y --;
        break;
    }

    jnext = joy(0);     // read the first joystick: J3, mapped to io port A8
    // Move the current sprite around the screen.
    // Press button to cycle to the next sprite

    if ((jnext & JOY_MAP_UP    ) == 0) {
      sprites[cur_sp].y --;
    }

    if ((jnext & JOY_MAP_DOWN  ) == 0) {
      sprites[cur_sp].y ++;
    }

    if ((jnext & JOY_MAP_LEFT  ) == 0) {
      sprites[cur_sp].x --;
    }

    if ((jnext & JOY_MAP_RIGHT ) == 0) {
      sprites[cur_sp].x ++;
    }

    if (jnext != jcur) {
      if ((jnext & JOY_MAP_BUTTON) == 0) {
        sprites[cur_sp].color = (sprites[cur_sp].color & 0x80) | BLACK;
        cur_sp ++;
        if (cur_sp > 4) cur_sp = 0;
        sprites[cur_sp].color = (sprites[cur_sp].color & 0x80) | DARK_RED;
      }

    }

    print();

    jcur = jnext;

    status = tms_wait();
    tms_g1flush(tms_buf);
    tms_flush_sprites();
  }
}
