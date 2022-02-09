#pragma once


#define SEQ_CLEAR "\x1b[2J"
#define SEQ_CURS_RESET "\x1b[H"

#define S0_(x) #x
#define S_(x) S0_(x)

#define CHECK(expr) if (!(expr)) die(__FILE__ ":" S_(__LINE__) ": " S_(expr))
#define CHECK_EQ(expr, eq) CHECK((expr) == (eq))

#define STDOUT_WRITE_BYTES(buffer, size) write(STDOUT_FILENO, (buffer), (size))
#define STDOUT_WRITE(buffer) STDOUT_WRITE_BYTES((buffer), sizeof (buffer))

#define STDIN_READ_BYTES(buffer, size) read(STDIN_FILENO, (buffer), (size))

void die(const char *message);
