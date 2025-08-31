#include <cpm.h>
#include <fcntl.h>
#include <malloc.h>
#include <string.h>

uint8_t get_free_idx() {
  uint8_t i;
  uint8_t idx;

  idx = 255;

  for (i = 0; i < MAX_OPEN_FILES; ++i) {
    if (!sys_open_files[i].used) {
      idx = i + 3;
      break;
    }
  }
  return idx;
}

size_t f_size(int8_t fd) {
  if (fd < 3) {
    errno = EINVAL;
    return 0;
  }
  cpm_f_size(&sys_open_files[fd-3].fcb);
  return sys_open_files[fd-3].fcb.rn;
}

int8_t close(int8_t fd) {
  if ((fd-3) > MAX_OPEN_FILES) {
    errno = EINVAL;
    return -1;
  }
  cpm_f_close(&sys_open_files[fd-3].fcb);
  sys_open_files[fd-3].used=false;
  return 0;
}

int8_t creat(const char *pathname, uint8_t mode) {
  uint8_t result;
  FILE *f;

  uint8_t idx;
  idx = get_free_idx();
  if (idx == 255) {
    errno = EBADF;
    return -1;
  }
  f = &sys_open_files[idx-3];

  memset(f, 0, sizeof(FILE));
  if (!set_fcb_file(&f->fcb, pathname)) {
    errno = EINVAL;
    return -1;
  }
  return idx;
}

int8_t open(const char *pathname, uint8_t flags) {
  uint8_t result;
  FILE *f;

  uint8_t idx;
  idx = get_free_idx();
  if (idx == 255) {
    errno = EINVAL;
    return -1;
  }

  f = &sys_open_files[idx-3];
  memset(f, 0, sizeof(FILE));

  if (!set_fcb_file(&f->fcb, pathname)) {
    errno = EINVAL;
    return -1;
  }

  // we succesfully parsed the filename.  Search for the file.
  result = cpm_f_sfirst(&f->fcb);
  if ((result == 0xFF) && (flags == O_CREAT)) {
    // need to create the file if O_CREAT
    idx = creat(pathname, 0);
    result = cpm_f_make(&f->fcb);
    if (result == 0xFF) {
      errno = EINVAL;
      return -1;
    }
  }
  // need to open the file.
  result = cpm_f_open(&f->fcb);
  if (result == 0xFF) {
    errno = EINVAL;
    return -1;
  }
  else {
    f->used = 1;
    return idx;
  }
  errno = EINVAL;
  return -1;
}
