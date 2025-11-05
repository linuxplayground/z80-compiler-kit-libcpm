// vim: set ts=2 sw=2:
/*
*****************************************************************************
*
*    Copyright (C) 2025 David Latham
*
*    This library is free software; you can redistribute it and/or
*    modify it under the terms of the GNU Lesser General Public
*    License as published by the Free Software Foundation; either
*    version 2.1 of the License, or (at your option) any later version.
*
*    This library is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*    Lesser General Public License for more details.
*
*    You should have received a copy of the GNU Lesser General Public
*    License along with this library; if not, write to the Free Software
*    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301
*    USA
*
* https://github.com/linuxplayground/z80-compiler-kit-libcpm
*
* https://gist.github.com/bert/1085538 - for line and circle routines
*
*****************************************************************************
*/

#include <cpm.h>
#include <stdlib.h>
#include <tms.h>


void plot_line (int x0, int y0, int x1, int y1, uint8_t c)
{
  int dx =  abs (x1 - x0), sx = x0 < x1 ? 1 : -1;
  int dy = -abs (y1 - y0), sy = y0 < y1 ? 1 : -1; 
  int err = dx + dy, e2; /* error value e_xy */
 
  for (;;){  /* loop */
    tms_plot_g2(x0,y0, c, BLACK);

    if (x0 == x1 && y0 == y1) break;
    e2 = 2 * err;
    if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
    if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
  }
}
void plot_circle (int xm, int ym, int r, uint8_t c)
{
   int x = -r, y = 0, err = 2-2*r; /* II. Quadrant */ 
   do {
      tms_plot_g2(xm-x, ym+y, c, BLACK); /*   I. Quadrant */
      tms_plot_g2(xm-y, ym-x, c, BLACK); /*  II. Quadrant */
      tms_plot_g2(xm+x, ym-y, c, BLACK); /* III. Quadrant */
      tms_plot_g2(xm+y, ym+x, c, BLACK); /*  IV. Quadrant */
      r = err;
      if (r >  x) err += ++x*2+1; /* e_xy+e_x > 0 */
      if (r <= y) err += ++y*2+1; /* e_xy+e_y < 0 */
   } while (x < 0);
}

int main() {
  char c;
  uint8_t x;
  uint8_t y;

  /* init g2 in bitmap mode */
  tms_init_g2(GRAY, BLACK, false, false);
  tms_set_reg(7, DARK_YELLOW);
  tms_init_bitmap_mode();
  for (y=0; y<19; y++) {
    plot_line(0, y*10, y*14, 191, DARK_GREEN);
    plot_line(255,y*10,255-(y*14), 191, DARK_GREEN);
    plot_line(y*14, 0, 0, 191-(y*10), DARK_GREEN);
    plot_line(y*14, 0, 255, y*10, DARK_GREEN);
  }

  plot_circle(127,191/2,191/2,MEDIUM_RED);
  plot_circle(127,191/2,191/2-1,MEDIUM_RED);
  plot_circle(127,191/2,191/2-2,MEDIUM_RED);

  return 0;
}
