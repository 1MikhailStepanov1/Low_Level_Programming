#ifndef LLP_META_H
#define LLP_META_H

#include "../include/node.h"
struct meta{
    int32_t node_count = 0;

    std::vector<int32_t> free;

    meta();

    void serialize(const std::string& file, std::ios::openmode mode);
    void deserialize(const std::string& file);
};
#endif
