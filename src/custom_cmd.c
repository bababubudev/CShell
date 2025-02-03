#include "custom_cmd.h"

#include <stdio.h>

#include "builtin_cmd.h"
#include "shl_utils.h"

static const shell_command_t custom_cmds[] = {
    {"clear", NULL, &shl_clear, "Clear screen"},
    {"help", NULL, shl_help, "Display help information"},
    {NULL, NULL, NULL, NULL}};

int custom_cmd_amt(void) {
  int count = 0;

  while (custom_cmds[count].name != NULL) {
    count++;
  }

  return count;
}

const shell_command_t *get_custom_cmds(void) {
  return custom_cmds;
}

int shl_clear(char **args) {
  clear_command();
  return 1;
}

int shl_help(char **args) {
  const shell_command_t *builtin_cmds = get_builtin_cmds();
  for (int i = 0; builtin_cmds[i].name != NULL; i++) {
    printf("%-15s - %s\n", builtin_cmds[i].name, builtin_cmds[i].description);
  }

  const shell_command_t *custom_cmds = get_custom_cmds();
  for (int i = 0; custom_cmds[i].name != NULL; i++) {
    printf("%-15s - %s\n", custom_cmds[i].name, custom_cmds[i].description);
  }

  printf("\nUse: [command] [arguments]\n\n");
  return 1;
}
