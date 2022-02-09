#include "terminal.h"

#include "util.h"

#include <termios.h>
#include <unistd.h>


static struct termios original_termios;


void term_enable_raw_mode() {
  CHECK_EQ(tcgetattr(STDIN_FILENO, &original_termios), 0);
  struct termios raw = original_termios;
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
  CHECK_EQ(tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios), 0);
}
