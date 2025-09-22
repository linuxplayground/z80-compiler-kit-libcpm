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
* https://elgibbor.hashnode.dev/building-your-own-printf-in-c-a-step-by-step-guide
*
*****************************************************************************
*/

#include <cpm.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>

/* -1 returned means erro of some sort */

static char _buf[16]; // largest number is 15 digits long

int format_integer(char *dst, int16_t val, uint8_t base, uint8_t s) {
  uint8_t l;
  uint8_t j;
  l = 0;
  if (s)
    itoa(val, _buf, base);
  else
    uitoa(val, _buf);

  for (j = 0; _buf[j] != '\0'; j++) {
    if (dst == NULL) cpm_conout(_buf[j]);
    else *dst++ = _buf[j];
    l++;
  }
  return l;
}
int _printf(char *dst, const char *format, ...) {
  int len = 0;
  va_list arg_list;
  int i, j;
  size_t val;
  char c;
  char *str;

  va_start(arg_list, format);

  for (i = 0; format[i] != '\0'; i++) {
    if (format[i] == '%') {
      i++;
      // char literal
      if (format[i] == 'c') {
        c = va_arg(arg_list, unsigned char);
        if (dst == NULL)
          cpm_conout(c);
        else
          *dst++ = c;
        len++;
      }
      // string literal
      if (format[i] == 's') {
        str = va_arg(arg_list, char *);
        for (j = 0; str[j] != '\0'; j++) {
          if (dst == NULL)
            cpm_conout(str[j]);
          else
            *dst++ = str[j];
          len++;
        }
      }
      // signed 16 bit decimal
      if (format[i] == 'd') {
        val = va_arg(arg_list, size_t);
        j = format_integer(dst, val, 10, 1);
        if (j == -1)
          return -1;
        len += j;
        if (dst != NULL) dst += j;
      }

      // unsigned 16 bit decimal
      if (format[i] == 'u') {
        val = va_arg(arg_list, size_t);
        j = format_integer(dst, val, 10, 0);
        if (j == -1)
          return -1;
        len += j;
        if (dst != NULL) dst += j;
      }

      // unsigned 16 bit hexadecimal
      if (format[i] == 'x') {
        val = va_arg(arg_list, size_t);
        j = format_integer(dst, val, 16, 1);
        if (j == -1)
          return -1;
        len += j;
        if (dst != NULL) dst += j;
      }
      /* other formatters */
    } else {
      if (dst == NULL) cpm_conout(format[i]);
      else *dst++ = format[i];
      len++;
    }
  }
  va_end(arg_list);
  return len;
}

int sprintf(char *dst, const char* format, va_list args)
{
  return _printf(dst, format, args);
}

int printf(const char *format, va_list args) {
  return _printf(NULL, format, args); 
}

