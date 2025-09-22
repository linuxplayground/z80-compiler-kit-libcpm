/*
*****************************************************************************
* Taken from Fuzix-Compiler-Kit, 
* (c) Alan Cox https://codeberg.org/etchedpixels/fuzix-compiler-kit.git
*
* /opt/fcc/lib/z80/include/stddef.h
*
* Added typedef for size_t
*****************************************************************************
*/
#ifndef _STDDEF_H
#define _STDDEF_H

#include <stdint.h>

#define NULL ((void *)0)

#define offsetof(type, ident) ((size_t) &((type *)0)->ident)

typedef uint16_t size_t;

#endif
