#include "terminal.h"

#include <stdlib.h>
#include <unistd.h>


int main() {
  term_enable_raw_mode();
  atexit(term_restore);

  char c;
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');

  return EXIT_SUCCESS;
}
