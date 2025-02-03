#include "shl_init.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "shl_utils.h"

static const char *color_codes[] = {
    "\033[0m",     // Default (reset)
    "\033[0;32m",  // Green
    "\033[1;34m",  // Blue
    "\033[0;33m",  // Yellow
    "\033[0m",     // White (reset)
    "\033[;37m"    // Grey
};

static shell_settings_t shell_settings = {.show_directory = 1};

const char *get_color_code(shell_color_t color) {
  return (color < 0 || color > COLOR_GREY) ? color_codes[COLOR_DEFAULT] : color_codes[color];
}

int set_color(const char *color_input) {
  shell_settings_t *settings = get_shell_settings();
  int color_num;

  char *endptr;
  color_num = (int)strtol(color_input, &endptr, 10);

  if (*endptr == '\0' && color_num >= COLOR_DEFAULT && color_num <= COLOR_GREY) {
    if (settings->color_code) {
      free(settings->color_code);
    }

    settings->current_color = (shell_color_t)color_num;
    settings->color_code = strdup(get_color_code((shell_color_t)color_num));

    if (settings->color_code == NULL) {
      fprintf(stderr, "Memory allocation failed for color code\n");
      return 0;
    }

    return 1;
  }

  struct {
    const char *name;
    shell_color_t color;
  } color_names[] = {{"default", COLOR_DEFAULT}, {"green", COLOR_GREEN}, {"blue", COLOR_BLUE},
                     {"yellow", COLOR_YELLOW},   {"white", COLOR_WHITE}, {"grey", COLOR_GREY}};

  for (size_t i = 0; i < sizeof(color_names) / sizeof(color_names[0]); i++) {
    if (strcasecmp(color_input, color_names[i].name) == 0) {
      free(settings->color_code);
      settings->current_color = color_names[i].color;
      settings->color_code = strdup(get_color_code(color_names[i].color));
      return 1;
    }
  }

  fprintf(stderr, "Invalid color: %s\n", color_input);
  fprintf(stderr, "Available colors:\n");
  fprintf(stderr, "0/default, 1/green, 2/blue, 3/yellow, 4/white, 5/grey\n");
  return 0;
}

int shl_init(void) {
  shell_settings_t *settings = get_shell_settings();

  if (settings->color_code) {
    free(settings->color_code);
  }

  settings->current_color = COLOR_DEFAULT;
  settings->color_code = strdup(get_color_code(COLOR_DEFAULT));

  if (settings->color_code == NULL) {
    fprintf(stderr, "Memory allocation failed for color code\n");
    return 0;
  }

  clear_command();
  printf("Simple Shell (shl) - Type 'help' for commands\n\n");
  return 1;
}

shell_settings_t *get_shell_settings(void) {
  return &shell_settings;
}

void shl_reset_settings(void) {
  shell_settings_t *settings = &shell_settings;
  settings->show_directory = 1;

  if (settings->color_code) {
    free(settings->color_code);
    settings->color_code = NULL;
  }

  settings->current_color = COLOR_DEFAULT;
  settings->color_code = strdup(get_color_code(COLOR_DEFAULT));

  if (settings->color_code == NULL) {
    fprintf(stderr, "Memory allocation failed during reset\n");
  }
}