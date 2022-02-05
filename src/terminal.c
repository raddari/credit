#include "terminal.h"

#include <termios.h>
#include <unistd.h>


static struct termios original_termios;


void term_enable_raw_mode() {
  tcgetattr(STDIN_FILENO, &original_termios);
  struct termios raw = original_termios;
  raw.c_lflag &= ~(ECHO | ICANON);

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void term_restore() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_termios);
}
