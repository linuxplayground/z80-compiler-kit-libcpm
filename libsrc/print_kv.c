#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <malloc.h>
#include <core.h>
#include <stddef.h>

bool print_kv(const char *k, size_t v, uint8_t l, uint8_t base) {
  char *buf = malloc(128);
  if (buf == NULL)
    return false;
  strcpy(buf, k);
  itoa(v, buf + strlen(k), l, base);
  printstr(buf);
  free(buf);
  return true;
}
