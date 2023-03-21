#ifndef LLP_DATABASE_H
#define LLP_DATABASE_H

#include "meta.h"
#include "util.h"
#include "node.h"

struct database{
    std::string file;
    meta information;

    database();
    explicit database(const std::string& file);

    void create();
    void open();
    void save();

    void add_node(node node);
    void update_node(const std::string& node_name, node node);
    node get_node(const std::string& node_name);
    void delete_node(const std::string& node_name);

private:
    void add_node_to_meta(const node& node);
    void node_name_validation(const std::string& node_name, bool is_in_mem);
    void delete_node_meta(const std::string& node_name, int32_t pos);
};

#endif
