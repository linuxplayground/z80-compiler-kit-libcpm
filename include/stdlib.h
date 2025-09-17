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

#ifndef _STDLIB_H
#define _STDLIB_H

#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/* Malloc and Free are transcribed from "The C Programming Language - Second
 * Edition" by Brian W. Kernighan and Dennis M. Ritchie */
extern int8_t _brk(void *addr);
extern void *_sbrk(uintptr_t incr);

/* return the absolute value of provided int */
extern int abs(int j);

/* Exit with a code.  Prints code if non-zero */
extern void exit(uint8_t code);

/* Free the memory pointed to by p */
void free(void *p);

/* Convert an integer to an ascii representation. */
int8_t itoa(uint16_t val, char *str, uint8_t len, uint8_t base);

/* Allocate size_t bytes on the heap and return a pointer to the allocated
 * memory. If the allocation would clash with the stack, the function returns
 * NULL */
void *malloc(size_t size);

/* Print a zero terminated C string using CPM conout
 */
void puts(char *s);

#endif //_STDLIB_H
