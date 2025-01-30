#ifndef SHL_UTILS_H
#define SHL_UTILS_H

#define SHL_TOK_BUFSIZE 1024
#define SHL_TOK_ARR_BUFSIZE 64
#define SHL_TOK_ARR_DELIM " \t\r\n\a"
#define EXIT_FAILURE 1

int is_exit_command(const char *input);

#endif