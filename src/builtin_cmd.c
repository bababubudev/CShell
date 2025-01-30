#include "builtin_cmd.h"

#include <stdio.h>
#include <unistd.h>

static const shell_command_t builtin_cmds[] = {
    {"cd", shl_cd, "Change directory"},
    {"exit", shl_exit, "Exit the shell"},
    {NULL, NULL, NULL}};

int builtin_cmd_amt(void) {
  int count = 0;

  while (builtin_cmds[count].name != NULL) {
    count++;
  }

  return count;
}

const shell_command_t *get_builtin_cmds(void) {
  return builtin_cmds;
}

int shl_cd(char **args) {
  if (args[1] == NULL) {
    fprintf(stderr, "shl: expected argument to \"cd\"\n");
  }
  else {
    if (chdir(args[1]) != 0) {
      perror("lsh");
    }
  }

  return 1;
}

int shl_exit(char **args) {
  return 0;
}
