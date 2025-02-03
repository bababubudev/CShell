#include "shl_utils.h"

#include <libgen.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "shl_init.h"

static int show_directory = 1;

char *get_current_dirname(void) {
  char cwd[1024];
  char *dirname = NULL;

  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    dirname = strdup(basename(cwd));
    return dirname;
  }

  return strdup("?");
}

int is_dir_display_enabled(void) {
  shell_settings_t *settings = get_shell_settings();
  return settings->show_directory;
}

int arr_includes(const char *input, const char **arr) {
  for (int i = 0; arr[i] != NULL; i++) {
    if (strcmp(input, arr[i]) == 0) {
      return 0;
    }
  }

  return -1;
}

int find_commands(const char *input, const shell_command_t *commands, int cmd_count) {
  for (int i = 0; i < cmd_count; i++) {
    if (commands[i].call_names != NULL && arr_includes(input, commands[i].call_names) == 0) {
      return i;
    }

    if (strcmp(input, commands[i].name) == 0) {
      return i;
    }
  }
  return -1;
}

int clear_command() {
  printf("\033[2J\033[H");
  return 1;
}
