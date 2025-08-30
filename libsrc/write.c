#include <core.h>
#include <cpm.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>

int write(int8_t fd, void *buf, size_t count) {
  size_t n = 0;
  uint8_t result;
  char *b = (char *)buf;
  FILE *f;

  if ( fd == STDIN ) {
    errno = EBADF;
    return -1;
  }


  if ((fd == STDOUT) || (fd==STDERR)) {
    for (n = 0; n < count; ++n) {
      *b++ = cpm_conin();
    }
  } else {
    f = &sys_open_files[fd];

    if ((fd > MAX_OPEN_FILES) || (!f->used)) {
      errno = EBADF;
      return -1;
    }

    // FILE should already be open - reset the FCB filepointer.
    f->fcb.cr = 0;
    while (n < count)
    {
      memcpy(buf, f->dma, 128);
      cpm_f_dmaoff(f->dma);
      result = cpm_f_write(&f->fcb);
      if (result > 1) {
        errno = EIO;
      }
      buf+=128;
      n+=128;
    }
  }
  errno = EOK;
  return n;
}
