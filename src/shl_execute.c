#include "shl_execute.h"

#include <string.h>

#include "builtin_cmd.h"
#include "custom_cmd.h"
#include "shl_launch.h"

int shl_execute(char **args) {
  if (args[0] == NULL) {
    return 1;
  }

  // BUILT IN COMMANDS
  const shell_command_t *commands = get_builtin_cmds();
  for (int i = 0; i < builtin_cmd_amt(); i++) {
    if (strcmp(args[0], commands[i].name) == 0) {
      return commands[i].func(args);
    }
  }

  const shell_command_t *custom_cmds = get_custom_cmds();
  for (int i = 0; custom_cmds[i].name != NULL; i++) {
    if (strcmp(args[0], custom_cmds[i].name) == 0) {
      return custom_cmds[i].func(args);
    }
  }

  return shl_launch(args);
}