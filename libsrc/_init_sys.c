#include <fcntl.h>
#include <string.h>

uint8_t errno = 0;
FILE sys_open_files[MAX_OPEN_FILES];

void _init_sys()
{
  errno = 0;
  memset(sys_open_files, 0, sizeof(FILE)*MAX_OPEN_FILES);
}
