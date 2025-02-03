#include "shl_launch.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifdef __MINGW32__
#include <windows.h>
#else
#include <sys/wait.h>
#endif

int shl_launch(char **args) {
#ifdef __MINGW32__
  // Windows implementation using CreateProcess()
  STARTUPINFO si;
  PROCESS_INFORMATION pi;

  ZeroMemory(&si, sizeof(si));
  si.cb = sizeof(si);
  ZeroMemory(&pi, sizeof(pi));

  // Convert arguments into a single command line string
  char command[1024] = "";
  for (int i = 0; args[i] != NULL; i++) {
    strcat(command, args[i]);
    strcat(command, " ");
  }

  if (!CreateProcess(NULL, command, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
    fprintf(stderr, "shl: Failed to execute command\n");
    return 1;
  }

  // Wait for the child
  WaitForSingleObject(pi.hProcess, INFINITE);
  CloseHandle(pi.hProcess);
  CloseHandle(pi.hThread);

#else
  // POSIX implementation using fork() and execvp()
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
#endif
  return 1;
}
