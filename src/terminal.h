#pragma once


void term_enable_raw_mode();
void term_restore();
int term_window_size(int *rows, int *cols);
int term_cursor_pos(int *row, int *col);
