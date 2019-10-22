struct tlsh
{
  void *obj;
};

typedef struct tlsh tlsh_t;

tlsh_t *tlsh_create();
void tlsh_destroy(tlsh_t *t);
const char *tlsh_get_hash(const tlsh_t *t, const unsigned char *data, unsigned int len);