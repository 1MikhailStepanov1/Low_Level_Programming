#ifndef __FILE_HANDLER__
#define __FILE_HANDLER__

#include <bits/types/FILE.h>
#include <stdio.h>
#include "string.h"
#include "../structs/structs.h"

void create_file(const char* directory);
FILE* open_file_to_read(const char* directory);
FILE* open_file_to_write(const char* directory);

#endif
