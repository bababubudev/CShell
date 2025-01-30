#include "shl_utils.h"

#include <stdio.h>
#include <string.h>

int is_exit_command(const char* input) {
  const char* exit_commands[] = {"exit", "quit", "q", NULL};
  for (int i = 0; exit_commands[i] != NULL; i++) {
    if (strcmp(input, exit_commands[i]) == 0) {
      return 0;
    }
  }

  return -1;
}
