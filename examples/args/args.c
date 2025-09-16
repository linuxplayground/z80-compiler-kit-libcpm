#include <cpm.h>

void main()
{
  char **argv;
  uint8_t argc = cpm_parse_args(&*argv);
  size_t i;

  for (i=0; i<argc; ++i)
  {
    puts("\r\n");
    puts(argv[i]);
  }
  puts("\r\n");
}
