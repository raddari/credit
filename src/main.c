#include "terminal.h"
#include "util.h"

#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main() {
  term_enable_raw_mode();
  atexit(term_restore);

  while (true) {
    refresh_screen();
    char c = '\0';
    QCHECK(read(STDIN_FILENO, &c, 1) >= 0 || errno == EAGAIN);
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
