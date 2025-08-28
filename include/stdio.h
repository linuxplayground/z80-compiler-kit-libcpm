#ifndef _H_STDIO
#define _H_STDIO

#include "core.h"
#include "cpm.h"

typedef struct s_file {
  FCB fcb;
  char *dma;
} FILE;

/* fopen opens a file in read write mode.  It allocates a 128 byte buffer and sets the dma.
 * If the file does not exist, it creates one for you.
 * Returns NULL if filename can not be parsed or if the new file can not be created.
 */
FILE *fopen(char *filename);
size_t fread(FILE *fh, size_t len);
size_t fwrite(FILE *fh, char *src, size_t len);
bool *fclose(FILE *fh);

#endif //_H_STDIO

