#pragma once


#include "config.h"


#define S0_(x) #x
#define S_(x) S0_(x)

#define CREDIT_VERSION_STR \
    S_(CREDIT_VERSION_MAJOR) "." S_(CREDIT_VERSION_MINOR) "." S_(CREDIT_VERSION_PATCH)

#define CHECK(expr) if (!(expr)) die(__FILE__ ":" S_(__LINE__) ": " S_(expr))
#define CHECK_EQ(expr, eq) CHECK((expr) == (eq))
#define CHECK_NE(expr, eq) CHECK((expr) != (eq))

#define STDOUT_WRITE_BYTES(buffer, size) write(STDOUT_FILENO, (buffer), (size))
#define STDOUT_WRITE(str) STDOUT_WRITE_BYTES((str), (sizeof (str)) - 1)

#define STDIN_READ_BYTES(buffer, size) read(STDIN_FILENO, (buffer), (size))
#define STDIN_READ_ONE(buffer) STDIN_READ_BYTES((buffer), sizeof *(buffer))

#define SET_NON_NULL(ptr, value) if (ptr) *(ptr) = (value)


void die(const char *message);
