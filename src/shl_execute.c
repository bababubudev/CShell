#include "shl_execute.h"

#include <stdio.h>
#include <string.h>

#include "builtin_cmd.h"
#include "custom_cmd.h"
#include "shl_launch.h"
#include "shl_utils.h"

int shl_execute(char **args) {
  if (args[0] == NULL) {
    return 1;
  }

  // BUILT IN COMMANDS
  const shell_command_t *builtin_cmds = get_builtin_cmds();
  int cmd_index = find_commands(args[0], builtin_cmds, builtin_cmd_amt());
  if (cmd_index != -1) {
    return builtin_cmds[cmd_index].func(args);
  }

  // CUSTOM COMMANDS
  const shell_command_t *custom_cmds = get_custom_cmds();
  cmd_index = find_commands(args[0], custom_cmds, custom_cmd_amt());
  if (cmd_index != -1) {
    return custom_cmds[cmd_index].func(args);
  }

  return shl_launch(args);
}