#include <stdio.h>
#include <stdlib.h>

#include "shl_io.h"
#include "shl_utils.h"

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