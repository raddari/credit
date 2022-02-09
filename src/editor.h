#pragma once


#define CTRL_KEY(k) ((k) & 0x1F)


char editor_read_key();
void editor_process_keypress();
void editor_refresh_screen();
