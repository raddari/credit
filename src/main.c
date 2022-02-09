#include "input.h"
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
    process_keypress();
  }

  return EXIT_SUCCESS;
}
