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
* https://github.com/linuxplayground/z80-retro-cpmlib.git
*
*****************************************************************************
*/

#include <cpm.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

size_t f_size(int8_t fd) {
  if (fd < 3) {
    errno = EINVAL;
    return 0;
  }
  cpm_f_size(&sys_open_files[fd-3].fcb);
  return sys_open_files[fd-3].fcb.rn;
}

