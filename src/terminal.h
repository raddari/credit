#pragma once


#define SEQ_CLEAR "\x1b[2J"
#define SEQ_CURS_RESET "\x1b[H"


void term_enable_raw_mode();
void term_restore();
