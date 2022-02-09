#include "util/xalloc.h"

#include "util/common.h"

#include <stdlib.h>


void* xmalloc(size_t size) {
  void *alloc = malloc(size);
  CHECK_NE(alloc, NULL);
  return alloc;
}

void* xcalloc(size_t num, size_t size) {
  void *alloc = calloc(num, size);
  CHECK_NE(alloc, NULL);
  return alloc;
}

void* xrealloc(void *ptr, size_t new_size) {
  void *alloc = realloc(ptr, new_size);
  CHECK_NE(alloc, NULL);
  return alloc;
}

void xfree(void *ptr) {
  free(ptr);
}
