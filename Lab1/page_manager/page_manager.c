#include <malloc.h>
#include "page_manager.h"
#define PAGE_SIZE_IN_b 4096;

//TODO Delete constant 4096 and add it in some config. Change malloc to more valid memory allocation
bool create_new_page(struct page prev_page, struct page_header header, struct block_info* block_info){
    struct page* new_page = malloc(4096 * sizeof(char));
    new_page->length = PAGE_SIZE_IN_b;
    new_page->page_header = header;
    new_page->first_block_info = block_info;
    return true;
}