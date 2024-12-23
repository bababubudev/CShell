#include <stdio.h>
#include <stdlib.h>

#include "../include/shl_loop.h"
#include "../include/shl_io.h"
#include "../include/shl_utils.h"

void shl_loop(void) {
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = shl_read_line();
    // args = shl_split_line(line);
    // status = shl_execute(args);

    free(line);
    free(args);
  }
  while (status);
}