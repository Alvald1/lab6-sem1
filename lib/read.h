#ifndef __READ__
#define __READ__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum { __OK = 1, NOT_FOUNDED };

char* get_word(const char* delim);

#endif
