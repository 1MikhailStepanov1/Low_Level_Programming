#include <malloc.h>
#include "page_manager.h"
#define PAGE_SIZE_IN_b 4096;

//TODO Delete constant 4096 and add it in some config. Change malloc to more valid memory allocation (Repeat it for all methods)
bool create_new_page(struct page prev_page, struct page_header header, struct block_info* block_info){
    struct page* new_page = malloc(4096 * sizeof(char));
    new_page->length = PAGE_SIZE_IN_b;
    new_page->page_header = header;
    new_page->first_block_info = block_info;
    return true;
}

//TODO Length + size??
bool create_new_block_info(struct node* node, struct relationship* relationship, struct property* property){
    struct block_info* new_block_info = malloc(4096 * sizeof(char));
    if (node != NULL && relationship == NULL && property == NULL){
        new_block_info->type = 1;
        new_block_info->data_link = node;
    } else if (node == NULL && relationship != NULL && property == NULL){
        new_block_info->type = 2;
        new_block_info->data_link = relationship;
    } else if (node == NULL && relationship == NULL && property != NULL){
        new_block_info->type = 3;
        new_block_info->data_link = property;
    } else {
        fprintf(stderr, "%s", "Choose one option of input data: node, relationship or property.");
        return false;
    }
    return true;
}

//TODO Length+size??
bool create_new_string_bucket(char* string_link){
    struct string_bucket* new_string_bucket = malloc(4096 * sizeof(char));
    new_string_bucket->data_start = string_link;
    return true;
}
//TODO Length + size + method for id??
bool create_new_node(){
    struct node* new_node = malloc(4096 * sizeof(char));
    new_node->next_rel_link = NULL;
    new_node->next_prop_link = NULL;
}
