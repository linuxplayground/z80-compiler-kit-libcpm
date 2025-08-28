#ifndef _H_FCNTL
#define _H_FCNTL

#include "core.h"

#define STDIN  0
#define STDOUT 1
#define STDERR 2

/* Allows writing to STDOUT and STDERR *only* */
size_t write(uint8_t fd, const void *buf, size_t count);

/* Allows reading from STDIN *only* */
size_t read(uint8_t fd, const void *buf, size_t count);

#endif //_H_FCNTL
