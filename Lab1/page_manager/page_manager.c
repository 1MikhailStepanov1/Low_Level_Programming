#include <malloc.h>
#include "page_manager.h"
#define PAGE_SIZE_IN_b 4096;

//TODO Delete constant 4096 and add it in some config
bool create_new_page(struct page prev_page, struct page_header header, struct block_info* block_info){
    struct page* new_page = malloc(4096 * sizeof(char));
    prev_page.page_header.next_page_address = (void*) new_page;
    return true;
}