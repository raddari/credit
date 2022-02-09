#include "util/common.h"

#include "creddefs.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void die(const char *message) {
  STDOUT_WRITE(SEQ_CLEAR);
  STDOUT_WRITE(SEQ_CURS_RESET);
  perror(message);
  exit(EXIT_FAILURE);
}
