#include "shl_io.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shl_utils.h"

char *shl_read_line() {
  int buffer_size = SHL_TOK_BUFSIZE, position = 0;
  char *buffer = malloc(sizeof(char) * buffer_size);

  int character;

  if (!buffer) {
    fprintf(stderr, "shl: allocation error\n");
    exit(EXIT_FAILURE);

    return NULL;
  }

  while (1) {
    character = getchar();

    if (character == EOF || character == '\n') {
      buffer[position] = '\0';
      return buffer;
    }
    else {
      buffer[position] = character;
    }

    position++;

    if (position >= buffer_size) {
      buffer_size += SHL_TOK_BUFSIZE;
      char *temp = realloc(buffer, buffer_size);

      if (!temp) {
        free(buffer);
        fprintf(stderr, "shl: allocation error\n");
        exit(EXIT_FAILURE);
      }

      buffer = temp;
    }
  }
}

char **shl_split_line(char *line) {
  if (line == NULL) {
    return NULL;
  }

  int buffer_size = SHL_TOK_ARR_BUFSIZE, position = 0;
  char **parsed_tokens = malloc(sizeof(char *) * buffer_size);

  char *token;

  if (!parsed_tokens) {
    fprintf(stderr, "shl: allocation error\n");
    exit(EXIT_FAILURE);
    return NULL;
  }

  token = strtok(line, SHL_TOK_ARR_DELIM);
  while (token != NULL) {
    parsed_tokens[position] = strdup(token);
    position++;

    if (position >= buffer_size) {
      buffer_size += SHL_TOK_ARR_BUFSIZE;
      char **temp = realloc(parsed_tokens, sizeof(char *) * buffer_size);

      if (!temp) {
        for (size_t i = 0; i < position; i++) {
          free(parsed_tokens[i]);
        }

        free(parsed_tokens);
        fprintf(stderr, "shl: allocation error\n");
        exit(EXIT_FAILURE);
        return NULL;
      }

      parsed_tokens = temp;
    }

    token = strtok(NULL, SHL_TOK_ARR_DELIM);
  }

  parsed_tokens[position] = NULL;
  return parsed_tokens;
}