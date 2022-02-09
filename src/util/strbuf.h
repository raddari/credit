#pragma once


typedef struct StrBuf StrBuf;


StrBuf* str_buf_new();
void str_buf_destroy(StrBuf *str_buf);
void str_buf_append(StrBuf *str_buf, const char *bytes, int len);
void str_buf_append_str(StrBuf *str_buf, const char *str);
int str_buf_len(StrBuf *str_buf);
