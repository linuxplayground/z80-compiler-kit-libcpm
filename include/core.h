#ifndef _H_CORE
#define _H_CORE

#include <stdint.h>

typedef uint16_t size_t;

#define TPA (*(uint16_t*)0x0006)
extern int abs(int j);

extern int8_t brk(void *addr);
extern void *sbrk(uintptr_t incr);
extern void exit();

#endif //_H_CORE
