#include "custom_cmd.h"

#include <stdio.h>

#include "builtin_cmd.h"

static const shell_command_t custom_cmds[] = {
    {"clear", &shl_clear, "Clears screen"},
    {"help", shl_help, "Displays help information"},
    {NULL, NULL, NULL}};

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
  printf("\033[2J\033[H");
  return 1;
}

int shl_help(char **args) {
  printf("\nBuilt-in commands:\n");
  printf("====================\n");
  const shell_command_t *builtin_cmds = get_builtin_cmds();
  for (int i = 0; builtin_cmds[i].name != NULL; i++) {
    printf("%-15s - %s\n", builtin_cmds[i].name, builtin_cmds[i].description);
  }

  printf("\nCustom commands:\n");
  printf("===================\n");
  const shell_command_t *custom_cmds = get_custom_cmds();
  for (int i = 0; custom_cmds[i].name != NULL; i++) {
    printf("%-15s - %s\n", custom_cmds[i].name, custom_cmds[i].description);
  }

  printf("\nUse: [command] [arguments]\n\n");
  return 1;
}
