#include "editor.h"
#include "terminal.h"
#include "util/common.h"

#include <stdbool.h>
#include <stdlib.h>


int main() {
  term_enable_raw_mode();

  EditorConfig config;
  CHECK_EQ(term_window_size(&config.screen_rows, &config.screen_cols), 0);
  editor_set_config(config);

  while (true) {
    editor_refresh_screen();
    editor_process_keypress();
  }

  return EXIT_SUCCESS;
}
