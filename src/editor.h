#pragma once


#define CTRL_KEY(k) ((k) & 0x1F)


/* Input */

char editor_read_key();
void editor_process_keypress();

/* Output */

void editor_refresh_screen();
void editor_draw_rows();
