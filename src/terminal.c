#include "terminal.h"

#include "creddefs.h"
#include "util.h"

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
    return -1;
  } else {
    if (rows) *rows = ws.ws_row;
    if (cols) *cols = ws.ws_col;
    return 0;
  }
}
