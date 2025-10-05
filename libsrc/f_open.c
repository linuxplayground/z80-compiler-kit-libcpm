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
#include <stdlib.h>
#include <string.h>

uint8_t get_free_idx() {
  uint8_t i;
  uint8_t idx;

  idx = 255;

  for (i = 0; i < MAX_OPEN_FILES; ++i) {
    if (!sys_open_files[i].used) {
      idx = i + 3;
      break;
    }
  }
  return idx;
}

int8_t creat(const char *pathname, uint8_t mode) {
  uint8_t result;
  FILE *f;

  uint8_t idx;
  idx = get_free_idx();
  if (idx == 255) {
    errno = EBADF;
    return -1;
  }
  f = &sys_open_files[idx-3];

  memset(f, 0, sizeof(FILE));
  if (!set_fcb_file(&f->fcb, pathname)) {
    errno = EINVAL;
    return -1;
  }
  return idx;
}

int8_t open(const char *pathname, uint8_t mode) {
  uint8_t result;
  FILE *f;

  uint8_t idx;
  idx = get_free_idx();
  if (idx == 255) {
    errno = EINVAL;
    return -1;
  }

  f = &sys_open_files[idx-3];
  memset(f, 0, sizeof(FILE));

  if (!set_fcb_file(&f->fcb, pathname)) {
    errno = EINVAL;
    return -1;
  }

  // we succesfully parsed the filename.  Search for the file.
  result = cpm_f_sfirst(&f->fcb);
  if ((result == 0xFF) && (mode == O_CREAT)) {
    // need to create the file if O_CREAT
    idx = creat(pathname, 0);
    result = cpm_f_make(&f->fcb);
    if (result == 0xFF) {
      errno = EINVAL;
      return -1;
    }
  }
  // need to open the file.
  result = cpm_f_open(&f->fcb);
  if (result == 0xFF) {
    errno = EINVAL;
    return -1;
  }
  else {
    f->used = 1;
    return idx;
  }
  errno = EINVAL;
  return -1;
}
