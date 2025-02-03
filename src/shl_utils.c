#include "shl_utils.h"

#include <stdio.h>
#include <string.h>

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
