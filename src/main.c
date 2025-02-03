#include <stdio.h>
#include <stdlib.h>

#include "shl_init.h"
#include "shl_loop.h"

int main(int argc, char **argv) {
  if (!shl_init()) {
    fprintf(stderr, "Shell initialization failed\n");
    return EXIT_FAILURE;
  }

  shl_loop();
  return 0;
}