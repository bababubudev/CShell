#ifndef SHL_INIT_H
#define SHL_INIT_H

typedef enum { COLOR_DEFAULT = 0, COLOR_GREEN, COLOR_BLUE, COLOR_YELLOW, COLOR_WHITE, COLOR_GREY } shell_color_t;

typedef struct {
  int show_directory;
  shell_color_t current_color;
  char *color_code;
} shell_settings_t;

const char *get_color_code(shell_color_t color);
int set_color(const char *color_input);

int shl_init(void);
shell_settings_t *get_shell_settings(void);
void shl_reset_settings(void);

#endif