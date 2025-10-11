#include <stdbool.h>
#include <stdint.h>

extern uint8_t kbdBufReadPos;
extern uint8_t kbdBufWritePos;
extern uint8_t kbdBuffer[256];

bool is_key_pressed()
{
  return ~(kbdBufReadPos==kbdBufWritePos);
}

char get_char()
{
  return kbdBuffer[kbdBufReadPos++];
}
