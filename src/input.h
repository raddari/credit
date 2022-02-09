#pragma once


#define CTRL_KEY(k) ((k) & 0x1F)


char read_key();
void process_keypress();
