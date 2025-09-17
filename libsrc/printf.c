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
* https://elgibbor.hashnode.dev/building-your-own-printf-in-c-a-step-by-step-guide
*
*****************************************************************************
*/

#include <stdlib.h>
#include <stdarg.h>
#include <cpm.h>
#include <stddef.h>

/* -1 returned means erro of some sort */

int format_integer(int16_t val, char* b, uint8_t base, uint8_t s)
{
  uint8_t l;
  uint8_t j;
  l = 0;
  if (s)
    itoa(val, b, base);
  else
    uitoa(val, b);
  for (j = 0; b[j] != '\0'; j++)
  {
    cpm_conout(b[j]);
    l ++;
  }
  return l;
}

int printf(const char *format, ...)
{
  int len = 0;
  va_list arg_list;
  int i, j;
  size_t val;
  char c;
  char *str;

  char *buf = malloc(16); //largest number is 15 digits long
  if (buf == NULL)
    return -1;

  va_start(arg_list, format);

  for (i=0; format[i] != '\0'; i++)
  {
    if (format[i] == '%')
    {
      i++;
      // char literal
      if (format[i] == 'c')
      {
        c = va_arg(arg_list, unsigned char);
        cpm_conout(c);
        len ++;
      }
      // string literal
      if (format[i] == 's')
      {
        str = va_arg(arg_list, char *);
        for (j = 0; str[j] != '\0'; j++)
        {
          cpm_conout(str[j]);
          len ++;
        }
      }
      // signed 16 bit decimal
      if (format[i] == 'd')
      {
        val = va_arg(arg_list, size_t);
        j = format_integer(val, buf, 10, 1);
        if (j == -1)
          return -1;
        len += j;
      }

      // unsigned 16 bit decimal
      if (format[i] == 'u')
      {
        val = va_arg(arg_list, size_t);
        j = format_integer(val, buf, 10, 0);
        if (j == -1)
          return -1;
        len += j;
      }

      // unsigned 16 bit hexadecimal
      if (format[i] == 'x')
      {
        val = va_arg(arg_list, size_t);
        j = format_integer(val, buf, 16, 1);
        if (j == -1)
          return -1;
        len += j;
      }
      /* other formatters */
    }
    else
    {
      cpm_conout(format[i]);
      len ++;
    }
  }
  va_end(arg_list);
  free(buf);
  return len;
}

