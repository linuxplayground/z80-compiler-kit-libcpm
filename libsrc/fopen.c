#include <cpm.h>
#include <stdio.h>
#include <string.h>
#include <malloc.h>

FILE *fopen(char *filename)
{
  uint8_t result;
  FILE *f = malloc(sizeof(FILE));

  memset(f, 0, sizeof(FILE));
  if (!set_fcb_file(&f->fcb, filename)) {
    return NULL;
  }

  // we succesfully parsed the filename.  Search for the file.
  result = cpm_f_sfirst(&f->fcb);
  if (result == 0xFF) {
    // need to create the file.
    result = cpm_f_make(&f->fcb);
    if (result == 0xFF)
      return NULL;
    else
      return f;
  } else {
    // need to open the file.
    result = cpm_f_open(&f->fcb);
    if (result == 0xFF)
      return NULL;
    else
      return f;
  }
  return NULL;
}
