#include "editor.h"

#include "util.h"

#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>


#define SEQ_CLEAR "\x1b[2J"
#define SEQ_CURS_RESET "\x1b[H"



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
  STDOUT_WRITE(SEQ_CLEAR);
  STDOUT_WRITE(SEQ_CURS_RESET);

  editor_draw_rows();

  STDOUT_WRITE(SEQ_CURS_RESET);
}

void editor_draw_rows() {
  for (int row = 0; row < 24; row++) {
    STDOUT_WRITE("~\n\r");
  }
}
