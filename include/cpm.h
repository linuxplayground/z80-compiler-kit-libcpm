#ifndef _CPM_H
#define _CPM_H

#include <stdbool.h>

extern void conout(char c);
extern char conin();

/* CPM Writestr expects chars to be terminated with a `$` */
extern void writestr(char *s);

extern void readstr(char *buf);
extern bool constat();

/* Print a regular C string using direct IO rather than via CPM
 * For normal CPM console write, use the writestr(char *c) function.
 */
void printstr(char *s);

#endif //_CPM_H
