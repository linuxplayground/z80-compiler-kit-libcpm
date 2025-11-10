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

#ifndef _STRING_H
#define _STRING_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/* Convert all lowercase letters to upper case.  Other characters are unchanged
 */
char toupper(char c);

/* These externs are all provided by the Fuzix-Compiler-Kit but for some reason
 * a header is not provided for them.  So one is provided here.
 */

void *memcpy(void *dst, void *src, size_t len);
void *memset(void *dest, int data, size_t len);
int memcmp(const void *s1, const void *s2, size_t n);

int strcmp(const char *s1, const char *s2);
int strncmp(const char *s1, const char *s2, size_t n);

char *strchr(const char *s, int c);
char *strrchr(const char *s, int c);
char *strcpy(char *dst, const char *src);

size_t strlen(const char *s);

char *strtok(char *s, const char *delim);
size_t strspn(const char *s, const char *accept);
char *strpbrk(const char *str, const char *set);

#endif //_STRING_H
