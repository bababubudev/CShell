#ifndef SHL_UTILS_H
#define SHL_UTILS_H

#define SHL_TOK_BUFSIZE 1024
#define SHL_TOK_ARR_BUFSIZE 64
#define SHL_TOK_ARR_DELIM " \t\r\n\a"
#define EXIT_FAILURE 1

#define GREEN_SHL "\033[0;32m"
#define BLUE_SHL "\033[1;34m"
#define YELLOW_SHL "\033[0;33m"
#define WHITE_SHL "\033[0m"
#define GREY_SHL "\033[;37m"

#include "builtin_cmd.h"

char *get_current_dirname(void);
int arr_includes(const char *input, const char **arr);
int find_commands(const char *input, const shell_command_t *commands, int cmd_count);
int clear_command(void);

#endif