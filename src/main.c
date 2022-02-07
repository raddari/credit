#include "terminal.h"

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
  term_enable_raw_mode();
  atexit(term_restore);

  while (true) {
    char c = '\0';
    read(STDIN_FILENO, &c, 1);
    if (iscntrl(c)) {
      printf("%d\n\r", c);
    } else {
      printf("%d ('%c')\n\r", c, c);
    }

    if (c == 'q') {
      break;
    }
  }

  return EXIT_SUCCESS;
}
