#ifndef _H_CORE
#define _H_CORE

#include <stdint.h>

typedef uint16_t size_t;

#define TPA (*(uint16_t*)0x0006) - 1
extern uint16_t *_end;
extern uint16_t _STACK;

extern int abs(int j);

#endif //_H_CORE
