#ifndef LLP_DATABASE_H
#define LLP_DATABASE_H

#include "../include/meta.h"
#include "../include/util.h"
#include "../include/node.h"

struct database{
    std::string file;
    meta information;

    database(const std::string& file);

    void create();
    void open();
    void save();

    void add_node(node node);
    void update_node(node node);
    node get_node(const std::string& node_class);
    void delete_node(const std::string& node_class);

private:
    void add_valid(node node);
    void update_node(node node);
    void get_node(const std::string& node_class);
    void delete_node(const std::string& node_class);
};

#endif
