#pragma once


#define CTRL_KEY(k) ((k) & 0x1F)


typedef struct EditorConfig {
  int screen_rows;
  int screen_cols;
} EditorConfig;


/* Input */

char editor_read_key();
void editor_process_keypress();

/* Output */

void editor_refresh_screen();
void editor_draw_rows();

/* Other */

void editor_set_config(EditorConfig config);
