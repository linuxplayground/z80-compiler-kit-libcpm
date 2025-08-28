#include "cpm.h"
#include "string.h"

bool set_fcb_file(FCB *fcb, char *filename) {
  uint8_t i;
  char buf[16];
  char *dot;

  memset(fcb, 0, sizeof(FCB));

  if ( filename[1] == ':'){
    i = toupper(filename[0]) - 'A';
    if ( (i >= 0) || (i<=15))
      fcb->dr = i;
    else
      return false;
  } else {
    fcb->dr = 0;
  }
  dot = strchr(filename, '.');
  if (dot == NULL) return false;

  for (i=0; i<8; ++i) {
    if ((filename[i]) && ((filename + i) < dot)) {
      fcb->f[i] = toupper(filename[i]);
    } else {
      fcb->f[i] = 0x20;
    }
  }

  if (dot) {
    dot ++;
    for (i=0; i<3; ++i) {
      if (dot[i]) {
        fcb->t[i] = toupper(dot[i]);
      } else {
        fcb->t[i] = 0x20;
      }
    }
  } else {
    memset(fcb->t, 0x20, 3);
  }
  return true;
}
