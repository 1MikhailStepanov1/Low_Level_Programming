#ifndef __HEADER_MANAGER__
#define __HEADER_MANAGER__

#include <stddef.h>
#include <stdint.h>

struct page_header {
    void* first_node_info_address;
    void* first_rel_info_address;
    void* first_prop_info_address;
    uint32_t length;
};

struct file_header {
    uint32_t page_amount;
    void* first_page_address;
};

struct file_header create_new_file_header();
struct page_header create_new_page_header();

#endif
