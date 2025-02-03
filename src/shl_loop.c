#include "shl_loop.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shl_execute.h"
#include "shl_init.h"
#include "shl_io.h"
#include "shl_utils.h"

void shl_display(char *dirname, shell_settings_t *settings) {
  if (settings->show_directory) {
    dirname = get_current_dirname();

    printf("%s%s\033[0m > ", settings->color_code ? settings->color_code : "", dirname);
    free(dirname);
  }
  else {
    printf("> ");
  }
}

void shl_loop(void) {
  char *dirname;
  shell_settings_t *settings = get_shell_settings();

  char *line;
  char **args;
  int status = 1;

  do {
    shl_display(dirname, settings);

    line = shl_read_line();
    args = shl_split_line(line);
    status = shl_execute(args);

    free(line);
    free(args);
  } while (status);
}