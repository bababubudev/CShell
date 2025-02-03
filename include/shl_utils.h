#ifndef SHL_UTILS_H
#define SHL_UTILS_H

#define SHL_TOK_BUFSIZE 1024
#define SHL_TOK_ARR_BUFSIZE 64
#define SHL_TOK_ARR_DELIM " \t\r\n\a"
#define EXIT_FAILURE 1

#include "builtin_cmd.h"

int arr_includes(const char *input, const char **arr);
int find_commands(const char *input, const shell_command_t *commands, int cmd_count);
int clear_command(void);

#endif