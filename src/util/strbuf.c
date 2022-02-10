#include "util/strbuf.h"

#include "util/xalloc.h"

#include <string.h>


void str_buf_destroy(StrBuf *str_buf) {
  if (str_buf->buffer) {
    xfree(str_buf->buffer);
    str_buf->buffer = NULL;
  }
  str_buf->len = 0;
}

void str_buf_append(StrBuf *str_buf, const char *str) {
  int len = (int) strlen(str);
  str_buf_append_bytes(str_buf, str, len);
}

void str_buf_append_bytes(StrBuf *str_buf, const char *bytes, int len) {
  char *buffer = xrealloc(str_buf->buffer, str_buf->len + len);
  memcpy(&buffer[str_buf->len], bytes, len);
  str_buf->buffer = buffer;
  str_buf->len += len;
}

char* str_buf_buffer(StrBuf *str_buf) {
  return str_buf->buffer;
}

int str_buf_len(StrBuf *str_buf) {
  return str_buf->len;
}
