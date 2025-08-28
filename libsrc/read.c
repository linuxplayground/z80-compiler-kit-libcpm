#include <core.h>
#include <cpm.h>

size_t read(uint8_t fd, const void *buf, size_t count) {
  size_t n;
  char *b = (char *)buf;

  if (fd != 0) {
    for (n = 0; (n < count); ++n) {
      *b++ = conin();
    }
  } else if (fd > 2) { /* trying to read from stdout or stderr.  Don't yet know
                          how to support that. */
    return -1;
  } else { /* Must be reading from a file which is not supported yet. */
    return -1;
  }
  return n;
}
