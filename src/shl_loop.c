#include "shl_loop.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shl_io.h"
#include "shl_launch.h"
#include "shl_utils.h"

void shl_loop(void) {
  char *line;
  char **args;
  int status = 1;

  do {
    printf("> ");
    line = shl_read_line();

    if (is_exit_command(line) == 0) {
      status = 0;
      break;
    }

    args = shl_split_line(line);
    status = shl_launch(args);

    free(line);
    free(args);
  } while (status);
}