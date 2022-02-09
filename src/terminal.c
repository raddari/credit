#include "terminal.h"

#include "creddefs.h"
#include "util/common.h"

#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>


static struct termios g_orig_termios;


void term_enable_raw_mode() {
  CHECK_EQ(tcgetattr(STDIN_FILENO, &g_orig_termios), 0);
  atexit(term_restore);

  struct termios raw = g_orig_termios;
  // Miscellaneous flags for traditional "raw mode"
  raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
  // Disable output formatting (\n -> \n\r)
  raw.c_oflag &= ~(OPOST);
  // Set character size to 8 bits per byte (probably the default anyway)
  raw.c_cflag |= (CS8);
  // Disable echo, line reading, <C-v> and interrupt signals
  raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

  // Set timeout for read()
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1;

  CHECK_EQ(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw), 0);
}

void term_restore() {
  STDOUT_WRITE(SEQ_CLEAR);
  STDOUT_WRITE(SEQ_CURS_RESET);
  CHECK_EQ(tcsetattr(STDIN_FILENO, TCSAFLUSH, &g_orig_termios), 0);
}

int term_window_size(int *rows, int *cols) {
  struct winsize ws;

  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
    if (STDOUT_WRITE(SEQ_TERM_RIGHT SEQ_TERM_BOTTOM) != 12) {
      return -1;
    }
    return term_cursor_pos(rows, cols);
  } else {
    SET_NON_NULL(rows, ws.ws_row);
    SET_NON_NULL(rows, ws.ws_col);
    return 0;
  }
}

int term_cursor_pos(int *row, int *col) {
  if (STDOUT_WRITE(SEQ_CURS_POS) != 4) {
    return -1;
  }

  char buffer[32] = {'\0'};
  for (size_t i = 0; i < sizeof buffer - 1; i++) {
    if (STDIN_READ_ONE(&buffer[i]) != 1 || buffer[i] == 'R') {
      break;
    }
  }

  if (buffer[0] != '\x1b' || buffer[1] != '[') {
    return -1;
  }

  int temp_row = 0;
  int temp_col = 0;
  if (sscanf(&buffer[2], "%d;%d", &temp_row, &temp_col) != 2) {
    return -1;
  }

  SET_NON_NULL(row, temp_row);
  SET_NON_NULL(col, temp_col);

  return 0;
}
