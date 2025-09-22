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

#ifndef _H_FCNTL
#define _H_FCNTL

#include <stdint.h>
#include <errno.h>
#include <cpm.h>

#define stdin 0
#define stdout 1
#define stderr 2

#define MAX_OPEN_FILES 4

enum t_flags {
  O_NULL,
  O_CREAT,
};

typedef struct s_file {
  FCB fcb;
  char dma[128];
  bool used;
} FILE;

extern FILE sys_open_files[MAX_OPEN_FILES]; /* We allow 4 files to be open at once */

/* creates a new open file description, an entry in the system-wide table of
 * open files All files are created equal. Mode is ignored in the case of CPM.
 */
int8_t creat(const char *pathname, uint8_t mode);

/* opens a file.  adds it to the sys_open_files array if there is room, creates
 * the file if it doesn't exist */
int8_t open(const char *pathname, uint8_t mode);

#endif //_H_FCNTL
