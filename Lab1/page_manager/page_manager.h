#ifndef __PAGE_MANAGER__
#define __PAGE_MANAGER__

#include "../structs/structs.h"

bool create_new_page();
bool create_new_block_info();
bool create_new_string_bucket();
bool create_new_node();
bool create_new_relationship();
bool create_new_property();

bool delete_page();
bool delete_new_block_info();
bool delete_new_string_bucket();
bool delete_new_node();
bool delete_new_relationship();
bool delete_new_property();

#endif
