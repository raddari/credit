#include "terminal.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
  term_enable_raw_mode();
  atexit(term_restore);

  char c;
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
    if (iscntrl(c)) {
      printf("%d\n\r", c);
    } else {
      printf("%d ('%c')\n\r", c, c);
    }
  }

  return EXIT_SUCCESS;
}
