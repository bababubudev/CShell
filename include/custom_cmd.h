#ifndef CUSTOM_CMD_H
#define CUSTOM_CMD_H

#include "builtin_cmd.h"

int custom_cmd_amt(void);
const shell_command_t *get_custom_cmds(void);

int shl_clear(char **args);
int shl_toggle_dir(char **args);
int shl_set_color(char **args);
int shl_greet(char **args);

#endif