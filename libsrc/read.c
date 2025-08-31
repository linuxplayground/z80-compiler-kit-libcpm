#include <core.h>
#include <cpm.h>
#include <fcntl.h>
#include <stdint.h>
#include <string.h>

int read(int8_t fd, void *buf, size_t count) {
  size_t n;
  uint8_t result;
  char *b = (char *)buf;
  FILE *f;

  n = 0;

  if ((fd == STDOUT) || (fd == STDERR)) {
    errno = EBADF;
    return -1;
  }

  if (fd == STDIN) {
    for (n = 0; n < count; ++n) {
      *b++ = cpm_conin();
    }
  } else {
    f = &sys_open_files[fd-3];

    if (((fd-3) > MAX_OPEN_FILES) || (!f->used)) {
      errno = EBADF;
      return -1;
    }
    while (n < count) {
      cpm_f_dmaoff(f->dma);
      result = cpm_f_read(&f->fcb);
      if (result > 1) {
        errno = EIO;
        return n;
      }
      memcpy(buf, f->dma, 128);
      buf += 128;
      n += 128;
    }
  }
  errno = EOK;
  return n;
}
