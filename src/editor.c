#include "editor.h"

#include "creddefs.h"
#include "util/common.h"
#include "util/strbuf.h"

#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>


#define WELCOME_MESSAGE "Credit editor -- version " CREDIT_VERSION_STR


static void draw_rows(StrBuf *out);


static EditorConfig g_config;


char editor_read_key() {
  ssize_t nread;
  char c;
  while ((nread = STDIN_READ_BYTES(&c, 1)) != 1) {
    CHECK(nread >= 0 || errno == EAGAIN);
  }
  return c;
}

void editor_process_keypress() {
  char c = editor_read_key();

  switch (c) {
    case CTRL_KEY('q'):
      exit(EXIT_SUCCESS);
      break;

    default:
      break;
  }
}

void editor_refresh_screen() {
  StrBuf out = {0};

  str_buf_append(&out, SEQ_CURS_HIDE);
  str_buf_append(&out, SEQ_CURS_RESET);

  draw_rows(&out);

  str_buf_append(&out, SEQ_CURS_RESET);
  str_buf_append(&out, SEQ_CURS_SHOW);

  STDOUT_WRITE_BYTES(out.buffer, out.len);
  str_buf_destroy(&out);
}

static void draw_rows(StrBuf *out) {
  for (int row = 0; row < g_config.screen_rows; row++) {
    if (row == g_config.screen_rows / 3) {
      int welcome_len = sizeof WELCOME_MESSAGE;
      if (welcome_len > g_config.screen_cols) {
        welcome_len = g_config.screen_cols;
      }

      int padding = (g_config.screen_cols - welcome_len) / 2;
      if (padding > 0) {
        str_buf_append(out, "~");
      }
      while (padding-- > 0) {
        str_buf_append(out, " ");
      }

      str_buf_append_bytes(out, WELCOME_MESSAGE, welcome_len);
    } else {
      str_buf_append(out, "~");
    }

    // Clear each line rather than the whole screen
    str_buf_append(out, SEQ_ERASE_RIGHT);
    if (row < g_config.screen_rows - 1) {
      str_buf_append(out, "\n\r");
    }
  }
}

void editor_set_config(EditorConfig config) {
  g_config = config;
}
