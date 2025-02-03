#include "builtin_cmd.h"

#include <stdio.h>
#include <unistd.h>

#include "shl_utils.h"

static const char *exit_call_names[] = {"exit", "q", "quit", "lmao", NULL};

static const shell_command_t builtin_cmds[] = {{"cd", NULL, shl_cd, "Change directory"},
                                               {"exit", exit_call_names, shl_exit, "Exit the shell"},
                                               {NULL, NULL, NULL, NULL}};

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
      perror("shl");
      return 1;
    }
  }

  return 1;
}

int shl_exit(char **args) {
  clear_command();
  return 0;
}
