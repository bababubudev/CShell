#include <stdio.h>
#include <stdlib.h>

#include "../include/shl_loop.h"

#define EXIT_FAILURE 1
#define SHL_TOK_BUFSIZE 1024

int main(int argc, char **argv) {
  shl_loop();
  return 0;
}