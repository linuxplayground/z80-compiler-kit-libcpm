#include <core.h>
#include <cpm.h>

size_t write(uint8_t fd, const void *buf, size_t count)
{
  size_t n;
  char *b = (char*)buf;
  if ((fd==1) || (fd == 2))  /* we only support stdout and stderr */
    for (n=0; (n<count && *b !=0); ++n)
      cpm_conout(*b++);
  else {
    /* Must be writing to a file which is not yet supported. */
    return -1;
  }
  return n;
}
