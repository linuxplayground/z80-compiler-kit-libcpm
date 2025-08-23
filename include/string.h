#ifndef _STRING_H
#define _STRING_H

#include <stddef.h>
#include <stdint.h>


/* Print a regular C string using direct IO rather than via CPM
 * For normal CPM console write, use the writestr(char *c) function.
 */
void printstr(char *s);

void memcpy(void *dst, void *src, uint16_t len);
void memset(void *dst, uint8_t c, uint16_t len);
void strcpy(char *dst, char *src, uint16_t len);
uint16_t strlen(char *str);
void itoa(uint16_t val, char *buf);
char *strchr(char *str, uint8_t c);
char toupper(char c);

#endif //_STRING_H

