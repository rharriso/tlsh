#include "tlsh_util.h"
#include "tlsh.h"

extern "C"
{
  int get_distance(const unsigned char x[], const unsigned char y[])
  {
    return h_distance(TLSH_STRING_LEN, x, y);
  }

  const char *get_hash(const unsigned char *data, unsigned int len)
  {
    Tlsh t;
    t.final(data, len);
    return t.getHash();
  }
}