#include "custom_cmd.h"

#include <stdio.h>

#include "builtin_cmd.h"
#include "shl_init.h"
#include "shl_utils.h"

static const char *greet_commands[] = {"greet", "hello", "hi", NULL};

static const shell_command_t custom_cmds[] = {
    {"clear", NULL, &shl_clear, "Clear screen"},
    {"help", NULL, shl_help, "Display help information"},
    {"toggledir", NULL, shl_toggle_dir, "Toggle current directory display in prompt"},
    {"setclr", NULL, shl_set_color, "Set foreground color for terminal"},
    {"greet", greet_commands, shl_greet, "Print a greet message"},
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

int shl_toggle_dir(char **args) {
  shell_settings_t *settings = get_shell_settings();
  settings->show_directory = !settings->show_directory;

  return 1;
}

int shl_set_color(char **args) {
  if (args[1] == NULL) {
    fprintf(stderr, "shl: expected argument to \"setclr\"\n");
    fprintf(stderr, "Usage: setclr <color number or name>\n");
    return 1;
  }

  return set_color(args[1]);
}

int shl_greet(char **args) {
  if (args[1] != NULL) {
    fprintf(stderr, "greet: too many arguments. Usage: greet\n");
    return 1;
  }

  printf("Hi! Welcome to Sea Shell.\n\n");
  return 1;
}

int shl_help(char **args) {
  printf("\n");
  const shell_command_t *builtin_cmds = get_builtin_cmds();
  for (int i = 0; builtin_cmds[i].name != NULL; i++) {
    printf("%-15s - %s\n\n", builtin_cmds[i].name, builtin_cmds[i].description);
  }

  const shell_command_t *custom_cmds = get_custom_cmds();
  for (int i = 0; custom_cmds[i].name != NULL; i++) {
    printf("%-15s - %s\n\n", custom_cmds[i].name, custom_cmds[i].description);
  }

  printf("\nUse: [command] [arguments]\n\n");
  return 1;
}
