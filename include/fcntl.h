#ifndef _H_FCNTL
#define _H_FCNTL

#include "core.h"
#include "cpm.h"

#define STDIN 0
#define STDOUT 1
#define STDERR 2

#define MAX_OPEN_FILES 4

enum t_flags {
  O_CREAT,
};

enum F_ERRNO {
  EOK,    // used to indicate that stuff worked.
  EBADF,  // The provided file descriptor is not a valid open file descriptor.
  EINVAL, // An invalid argument was provided to fcntl()
  EFAULT, // flock structure that a bad address was provided as an argument;
  EIO,    // general IO error used when CPM fails to read or write.
};

extern uint8_t errno;

typedef struct s_file {
  FCB fcb;
  char dma[128];
  bool used;
} FILE;

extern FILE sys_open_files[MAX_OPEN_FILES]; /* We allow 8 files to be open at once */

/* creates a new open file description, an entry in the system-wide table of
 * open files All files are created equal. Mode is ignored in the case of CPM.
 */
int8_t creat(const char *pathname, uint8_t mode);

/* opens a file.  adds it to the sys_open_files array if there is room, creates
 * the file if it doesn't exist */
int8_t open(const char *pathname, uint8_t flags);

/* write to open file */
int write(int8_t fd, void *buf, size_t count);

/* read from open file */
int read(int8_t fd, void *buf, size_t count);

/* Close a file, free it from the array of open files */
int8_t close(int8_t fd);

#endif //_H_FCNTL
