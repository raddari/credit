#pragma once


#define S0_(x) #x
#define S_(x) S0_(x)

#define CHECK(expr) if (!(expr)) die(__FILE__ ":" S_(__LINE__) ": " S_(expr))
#define CHECK_EQ(expr, eq) CHECK((expr) == (eq))

#define SEQ_CLEAR "\x1b[2J"
#define SEQ_CURS_RESET "\x1b[H"

void die(const char *message);
void refresh_screen();
