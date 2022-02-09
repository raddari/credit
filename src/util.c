#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void die(const char *message) {
  STDOUT_WRITE("\x1b[2J");
  STDOUT_WRITE("\x1b[H");
  perror(message);
  exit(EXIT_FAILURE);
}
