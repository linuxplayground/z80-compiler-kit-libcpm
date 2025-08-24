#include "cpm.h"
#include "stdio.h"
#include "string.h"

#if 0
FILE *fopen(char *filename)
{
  uint8_t result;
  FILE f;

  memset(&f, 0, sizeof(FILE));
  if (!parse_fcb_filename(f.fcb, filename)) {
    return NULL;
  }

  // we succesfully parsed the filename.  Search for the file.
  result = f_sfirst(&f.fcb)==0xFF);
  if (result == 0xFF) {
    // need to create the file.
    result = f_make(&f.fcb);
    if (result == 0xFF)
      return NULL;
    else
      return &f;
  } else {
    // need to open the file.
    result = f_open(&f.fcb);
  }
}
#endif
