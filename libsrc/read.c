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
*****************************************************************************
*/

#include <cpm.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

int read(int8_t fd, void *buf, size_t count) {
  size_t n;
  uint8_t result;
  char *b = (char *)buf;
  FILE *f;

  n = 0;

  if ((fd == stdout) || (fd == stderr)) {
    errno = EBADF;
    return -1;
  }

  if (fd == stdin) {
    for (n = 0; n < count; ++n) {
      *b++ = cpm_conin();
    }
  } else {
    f = &sys_open_files[fd - 3];

    if (((fd - 3) > MAX_OPEN_FILES) || (!f->used)) {
      errno = EBADF;
      return -1;
    }
    n = count;
    for (;;) {
      cpm_f_dmaoff(f->dma);
      result = cpm_f_read(f->fcb);
      if (result > 1) {
        errno = EIO;
        return 0;
      }
      memcpy(buf, f->dma, 128);
      buf += 128;
      n = n - 128;
      if (n < 128)
        break;
    }
    if (n > 0) {
      // do the remainder (if it exists)
      memset(f->dma, 0, 128);
      cpm_f_dmaoff(f->dma);
      result = cpm_f_read(f->fcb);
      if (result > 1) {
        errno = EIO;
        return 0;
      }
      memcpy(buf, f->dma, n);
    }
  }
  errno = EOK;
  return count;
}
