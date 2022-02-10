#pragma once


typedef struct StrBuf {
  char *buffer;
  int len;
} StrBuf;


void str_buf_destroy(StrBuf *str_buf);
void str_buf_append(StrBuf *str_buf, const char *str);
void str_buf_append_bytes(StrBuf *str_buf, const char *bytes, int len);
