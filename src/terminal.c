#include "terminal.h"

#include <termios.h>
#include <unistd.h>


static struct termios original_termios;


void term_enable_raw_mode() {
  tcgetattr(STDIN_FILENO, &original_termios);
  struct termios raw = original_termios;
  // Miscellaneous flags for traditional "raw mode"
  raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
  // Disable output formatting (\n -> \n\r)
  raw.c_oflag &= ~(OPOST);
  // Set character size to 8 bits per byte (probably the default anyway)
  raw.c_cflag |= (CS8);
  // Disable echo, line reading, <C-v> and interrupt signals
  raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void term_restore() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
}
