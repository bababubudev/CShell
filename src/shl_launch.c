#include "shl_launch.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int shl_launch(char **args) {
  pid_t pid, wpid;
  int status;

  pid = fork();
  if (pid < 0) {
    perror("fork failed");
    return 1;
  }

  if (pid == 0) {
    // CHILD PROCESS
    if (execvp(args[0], args) == -1) {
      perror("shl");
      _exit(EXIT_FAILURE);
    }
  }
  else {
    // PARENT PROCESS
    do {
      wpid = waitpid(pid, &status, WUNTRACED);
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
  }

  return 1;
}