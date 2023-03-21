#ifndef LLP_META_H
#define LLP_META_H

#include "node.h"
#include <cereal/types/unordered_set.hpp>

struct meta{
    int32_t node_count = 0;
    std::vector<int32_t> free;
    std::unordered_map<std::string, int32_t> node_names;
    std::unordered_map<std::string, std::unordered_set<int32_t>> node_classes;

    meta();

    int32_t get_id_by_node_name(const std::string &node_name);

    void serialize(const std::string& file, std::ios::openmode mode);
    void deserialize(const std::string& file);
};
#endif
