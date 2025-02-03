#ifndef BUILTIN_CMNDS_H
#define BUILTIN_CMNDS_H

typedef int (*command_func)(char **);

typedef struct {
  const char *name;
  const char **call_names;
  command_func func;
  const char *description;
} shell_command_t;

int shl_cd(char **args);
int shl_help(char **args);
int shl_exit(char **args);

int builtin_cmd_amt(void);
const shell_command_t *get_builtin_cmds(void);

#endif