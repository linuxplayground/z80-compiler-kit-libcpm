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

#ifndef _H_UNISTD
#define _H_UNISTD

#include <stdint.h>
#include <fcntl.h>
#include <cpm.h>

/* write to open file */
int write(int8_t fd, void *buf, size_t count);

/* read from open file */
int read(int8_t fd, void *buf, size_t count);

/* Close a file, free it from the array of open files */
int8_t close(int8_t fd);

/* Get the file size in number of 128 byte blocks */
size_t f_size(int8_t fd);

#endif //_H_UNISTD
