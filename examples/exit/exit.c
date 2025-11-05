#include <cpm.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  printf("\nExiting with a non zero exit code\n");
  exit(0x69);
  return 0; // unreachable
}
