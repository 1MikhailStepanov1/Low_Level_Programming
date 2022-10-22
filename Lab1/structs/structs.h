#ifndef __STRUCTS__
#define __STRUCTS__

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

struct node {
    uint32_t id;
    uint32_t next_rel_id;
    uint32_t next_prop_id;
};

struct relationship {
    uint32_t id;
    uint32_t first_node_id;
    uint32_t second_node_id;
    uint16_t type;
    uint32_t next_prop_id;
    uint32_t prev_rel_id;
    uint32_t next_rel_id;
};

struct property {
    uint32_t id;
    uint32_t prev_prop_id;
    uint32_t next_prop_id;
    bool is_props_data_string;
    union props_block{
        int props_block1;
        int props_block2;
        float props_block3;
        bool props_block4;
    };

};

struct string_bucket {
    uint16_t length;
    char *data_start;
};

struct block_info {
    uint16_t type; // 1 node, 2 - relation, 3 - props
    size_t tuple_address;
    size_t next_block_address;
};

struct page_header {
    size_t next_page_address;
    size_t first_node_info_address;
    size_t first_rel_info_address;
    size_t first_prop_info_address;
};

struct page {
    struct page_header page_header;
    size_t prev_page_address;
    size_t next_page_address;
};

struct file_header {
    uint32_t page_amount;
    size_t first_page_address;
    size_t last_page_address;
};

#endif