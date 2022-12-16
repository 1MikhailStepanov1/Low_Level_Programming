#ifndef __PAGE_MANAGER__
#define __PAGE_MANAGER__

#include <stdbool.h>
#include <stdint.h>
#include "../header_manager/header_manager.h"

//TODO Необходима структура страницы для хранения строк

struct page {
    uint32_t length;
    struct page_header page_header;
    struct block_info* first_block_info;
};

struct node { //entity
    uint32_t id;
    uint32_t length;
    struct relationship* next_rel_link;
    struct property* next_prop_link;
};

struct relationship { //relationship
    uint32_t id;
    uint32_t length;
    struct node* first_node_link;
    struct node* second_node_link;
    struct relationship* prev_rel_link;
    struct relationship* next_rel_link;
};

struct property { //field
    uint32_t id;
    uint32_t length;
    char* type;   //name
    uint32_t prev_prop_link;
    uint32_t next_prop_id;
    bool is_props_data_string;
    union props_block{  //valueOf(type)
        int props_block1;
        int props_block2;
        float props_block3;
        bool props_block4;
    };
};

struct string_bucket {
    uint16_t length;
    char* data_start;
};

struct block_info {
    uint16_t type; // 1 - node, 2 - relation, 3 - props
    uint32_t length;
    void* data_link; //link for node or relationship or props
};

bool create_new_page(struct page prev_page, struct page_header header, struct block_info* block_info);
bool create_new_block_info(struct node* node, struct relationship* relationship, struct property* property);
bool create_new_string_bucket(char* string_link);
bool create_new_node();
bool create_new_relationship(struct node* node1, struct node* node2, struct relationship* rel1, struct relationship* rel2);
bool create_new_property();

bool delete_page();
bool delete_new_block_info();
bool delete_new_string_bucket();
bool delete_new_node();
bool delete_new_relationship();
bool delete_new_property();

#endif
