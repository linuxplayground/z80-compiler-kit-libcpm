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

#ifndef _H_ERRNO
#define _H_ERRNO
#include <stdint.h>

enum F_ERRNO {
  EOK,    // used to indicate that stuff worked.
  EBADF,  // The provided file descriptor is not a valid open file descriptor.
  EINVAL, // An invalid argument was provided to fcntl()
  EFAULT, // flock structure that a bad address was provided as an argument;
  EIO,    // general IO error used when CPM fails to read or write.
};

extern uint8_t errno;

#endif //_H_ERRNO
