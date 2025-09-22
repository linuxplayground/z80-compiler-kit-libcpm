#include <cpm.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void main()
{
  printf("\r\nExiting with a non zero exit code\n\r");
  exit(0x69);
}
