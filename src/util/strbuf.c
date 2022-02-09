#include "util/strbuf.h"

#include "util/xalloc.h"

#include <string.h>


struct StrBuf {
  char *buffer;
  int len;
};


StrBuf* str_buf_new() {
  StrBuf *str_buf = xcalloc(1, sizeof *str_buf);
  return str_buf;
}

void str_buf_destroy(StrBuf *str_buf) {
  xfree(str_buf->buffer);
  str_buf->buffer = NULL;
  xfree(str_buf);
}

void str_buf_append(StrBuf *str_buf, const char *bytes, int len) {
  char *buffer = xrealloc(str_buf->buffer, str_buf->len + len);
  memcpy(&buffer[str_buf->len], bytes, len);
  str_buf->buffer = buffer;
  str_buf->len += len;
}

void str_buf_append_str(StrBuf *str_buf, const char *str) {
  int len = (int) strlen(str);
  str_buf_append(str_buf, str, len - 1);
}

int str_buf_len(StrBuf *str_buf) {
  return str_buf->len;
}
