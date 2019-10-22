#include <stdlib.h>
#include "tlsh_t.h"
#include "tlsh.h"

tlsh_t *tlsh_create()
{
  tlsh_t *t;
  Tlsh *obj;

  t = (typeof(t))malloc(sizeof(*t));
  obj = new Tlsh();
  t->obj = obj;

  return t;
};

void tlsh_destroy(tlsh_t *t)
{
  if (t == NULL)
  {
    return;
  }

  delete static_cast<Tlsh *>(t->obj);
  free(t);
}

const char *tlsh_get_hash(const tlsh_t *t, const unsigned char *data, unsigned int len)
{
  Tlsh *obj;

  // if (t == NULL)
  //   return;

  obj = static_cast<Tlsh *>(t->obj);

  obj->final(data, len);
  return obj->getHash();
}