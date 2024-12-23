#include <stdio.h>

char* shl_read_loop() {
  return "";
}

void shl_loop(void) {
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = shl_read_loop();
  }
  while (status);
}

int main(int argc, char **argv) {
  shl_loop();
  return 0;
}