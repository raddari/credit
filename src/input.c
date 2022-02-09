#include "input.h"

#include "util.h"

#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>


char read_key() {
  ssize_t nread;
  char c;
  while ((nread = read(STDIN_FILENO, &c, 1)) != 1) {
    CHECK(nread >= 0 || errno == EAGAIN);
  }
  return c;
}

void process_keypress() {
  char c = read_key();

  switch (c) {
    case CTRL_KEY('q'):
      exit(EXIT_SUCCESS);
      break;

    default:
      break;
  }
}
