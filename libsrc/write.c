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
* https://github.com/linuxplayground/z80-retro-libcpm.git
*
*****************************************************************************
*/

#include <fcntl.h>
#include <string.h>

int write(int8_t fd, void *buf, size_t count) {
  size_t n = 0;
  uint8_t result;
  char *b = (char *)buf;
  FILE *f;

  if ( fd == STDIN ) {
    errno = EBADF;
    return -1;
  }


  if ((fd == STDOUT) || (fd==STDERR)) {
    for (n = 0; n < count; ++n) {
      cpm_conout(*b++);
    }
  } else {
    f = &sys_open_files[fd-3];

    if (((fd-3) > MAX_OPEN_FILES) || (!f->used)) {
      errno = EBADF;
      return -1;
    }

    n = count;
    for (;;) {
      memcpy(f->dma, buf, 128);
      cpm_f_dmaoff(f->dma);
      result = cpm_f_write(&f->fcb);
      if (result > 1) {
        errno = EIO;
        return 0;
      }
      buf+=128;
      n = n - 128;
      if (n < 128)
        break;
    }
    if (n > 0)
    {
      // do the remainder (if it exists)
      memset(f->dma, 0, 128);
      memcpy(f->dma, buf, n);
      cpm_f_dmaoff(f->dma);
      result = cpm_f_write(&f->fcb);
      if (result > 1) {
        errno = EIO;
        return 0;
      }
     }
  }
  errno = EOK;
  return count;
}
