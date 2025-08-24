#ifndef _STRING_H
#define _STRING_H

#include "core.h"
#include <stddef.h>
#include <stdint.h>

/* Print a regular C string using direct IO rather than via CPM
 * For normal CPM console write, use the writestr(char *c) function.
 */
void printstr(char *s);
extern void *memcpy(void *dst, void *src, size_t n);
extern void* memset(void *dest, uint8_t c, size_t n);
extern int8_t memcmp(void *s1, void *s2, size_t n);

extern int8_t strcmp(const char *s1, const char *s2);
extern int8_t strncmp(const char *s1, const char *s2, size_t n);

extern char *strchr(const char *str, int8_t c);
extern char *strrchr(const char *s, int c);
extern char *stpcpy(char *dst, const char *src);

extern size_t strlcat(char *dst, const char *src, size_t size);
extern char *strcpy(char *dst, const char *src);

extern size_t strlen(const char *s);
void itoa(size_t val, char *buf);
char toupper(char c);

#endif //_STRING_H

