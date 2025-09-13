#include <cpm.h>
#include <stdint.h>
#include <string.h>

int32_t a[1414];
int32_t b;
int32_t c = 1414;
int32_t d;
int32_t e;
int32_t f = 10000;
int32_t g;
int32_t h;
int32_t n;

char tb[6];

void main() {
  h = 0;
  n = 10;
  for (; b = c -= 14;) {
    for (e = d %= f; g = --b * 2; d /= g) {
      d = d * b + f * (h ? a[b] : f / 5);
      a[b] = d % --g;
    }
    h = 1;
    if (n == 10) {
      cpm_conout('\n');
      n = 1;
    } else
      n += 1;
    itoa(e + (d / f), tb, 5, 10);
    puts(tb);
  }
}
