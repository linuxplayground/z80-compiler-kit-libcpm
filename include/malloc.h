#ifndef _MALLOC_H
#define _MALLOC_H

#include <core.h>

/* Malloc and Free are transcribed from "The C Programming Language - Second
 * Edition" by Brian W. Kernighan and Dennis M. Ritchie */

/* Allocate size_t bytes on the heap and return a pointer to the allocated
 * memory. If the allocation would clash with the stack, the function returns
 * NULL */
void *malloc(size_t size);

/* Free the memory pointed to by p */
void free(void *p);

#endif //_MALLOC_H
