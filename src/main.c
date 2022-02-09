#include "editor.h"
#include "terminal.h"

#include <stdbool.h>
#include <stdlib.h>


int main() {
  term_enable_raw_mode();
  atexit(term_restore);

  while (true) {
    editor_refresh_screen();
    editor_process_keypress();
  }

  return EXIT_SUCCESS;
}
