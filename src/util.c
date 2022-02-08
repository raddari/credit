#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void die(const char *message) {
  refresh_screen();
  perror(message);
  exit(EXIT_FAILURE);
}

void refresh_screen() {
  write(STDOUT_FILENO, SEQ_CLEAR, sizeof SEQ_CLEAR);
  write(STDOUT_FILENO, SEQ_CURS_RESET, sizeof SEQ_CURS_RESET);
}
