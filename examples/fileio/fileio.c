#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/* Write some content to a file.
 * Read it back again.
 */

int main() {
  int8_t new_file;
  size_t i, n;
  size_t records;
  char *bigbuf1;
  char *bigbuf2;

  new_file = open("newfile.txt", O_CREAT);
  if (new_file == -1) {
    puts("\nError opening `newfile.txt`");
    exit(-2);
  }

  bigbuf1 = malloc(1234);   // reserve 1234 bytes for text
  memset(bigbuf1, 0, 1234); // initialize it

  // fill the buffer with text
  for (i = 0; i < 1234; ++i) {
    bigbuf1[i] = 'A' + (i % 26);
  }

  // Write all the data into the file.
  write(new_file, bigbuf1, 1000);
  // Free memory when not using it anymore.
  free(bigbuf1);
  // close the file.
  if (close(new_file) == -1) {
    puts("\nError closing new file");
    exit(-3);
  }

  // Open the file again.  This time so we can read it.
  new_file = open("newfile.txt", O_NULL);
  records = f_size(new_file);

  // This time allocate ram based on number of records consumed by a file.
  // thus ensuring our buffer is large enough
  bigbuf2 = malloc(records * 128);
  // init it all to zero
  memset(bigbuf2, 0, (records * 128));

  // read the whole file
  n = read(new_file, bigbuf2, 1000);
  // write it all to stdout.
  write(stdout, bigbuf2, n);

  close(new_file); // Closing the file to free up file handler resources.
  // free ram thats no longer being used.
  free(bigbuf2);
  return 0;
}
