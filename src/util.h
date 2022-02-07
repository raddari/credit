#pragma once


#define S0_(x) #x
#define S_(x) S0_(x)

#define QCHECK(expr) if (!(expr)) die(__FILE__ ":" S_(__LINE__) ": " S_(expr))
#define QCHECK_EQ(expr, eq) QCHECK((expr) == (eq))

void die(const char *message);
