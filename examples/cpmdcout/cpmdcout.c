#include <cpm.h>
#include <stdlib.h>

void rawouts(char *s) {
  do {
    cpm_dc_out(*s);
  } while (*s++ != 0);
}


int main()
{
  puts("Press a key to clear the screen\n");
  while (!cpm_dc_in());
  // Clear screen
  rawouts("\e[2J\e[H");
  puts("Screen was cleared\n");
  // Set text to bright green
  rawouts("\e[32m");
  puts("Text was set to green\n");
  //reset the colour
  rawouts("\e[0m");
  puts("Text was reset to default.\n");
  return 0;
}
