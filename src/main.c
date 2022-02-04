#include "terminal.h"

#include <stdlib.h>
#include <unistd.h>


int main() {
  term_enable_raw_mode();
  atexit(term_disable_raw_mode);

  char c;
  while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q');

  return EXIT_SUCCESS;
}
