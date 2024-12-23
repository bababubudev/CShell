#include <stdio.h>
#include <stdlib.h>

#define EXIT_FAILURE 1
#define SHL_TOK_BUFSIZE 1024

char* shl_read_line() {
  int buffer_size = SHL_TOK_BUFSIZE;

  int position = 0;
  char* buffer = malloc(sizeof(char) * buffer_size);

  int c;

  if (!buffer) {
    fprintf(stderr, "shl: allocation error\n");
    exit(EXIT_FAILURE);
  }

  while (1) {
    c = getchar();

    if (c == EOF || c == '\n') {
      buffer[position] = '\0';
      printf("buffer: %s\n", buffer);
      printf("position: %d\n", position);
      return buffer;
    }
    else {
      buffer[position] = c;
    }

    position++;

    if (position >= buffer_size) {
      buffer_size += SHL_TOK_BUFSIZE;
      buffer = realloc(buffer, buffer_size);
      if (!buffer) {
        fprintf(stderr, "shl: allocation error\n");
        exit(EXIT_FAILURE);
      }
    }
  }
}

void shl_loop(void) {
  char *line;
  char **args;
  int status;

  do {
    printf("> ");
    line = shl_read_line();
    // args = shl_split_line(line);
    // status = shl_execute(args);

    free(line);
    free(args);
  }
  while (status);
}

int main(int argc, char **argv) {
  shl_loop();
  return 0;
}