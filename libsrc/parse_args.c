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

#include <string.h>
#include <stddef.h>

#define CMDLINE 0x80

char *cmd_line = (char*)CMDLINE;

uint8_t cpm_parse_args(char **argv)
{
  char *tok;
  uint8_t count = 0;
  uint8_t len = cmd_line[0];
  cmd_line[len + 1] = '\0';

  tok = strtok(&cmd_line[1], " ");
  for (;;)
  {
    if (tok == NULL) break;
    argv[count++] = tok;
    tok = strtok(NULL, " ");
  }
  return count;
}
