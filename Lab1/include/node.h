#ifndef LLP_NODE_H
#define LLP_NODE_H

#include "property.h"
#include "relationship.h"
#include <cereal/types/unordered_map.hpp>


struct node { //entity
    int32_t id{};
    std::string node_name;
    std::string node_class;
    std::unordered_map<std::string, property> props;
    std::unordered_map<std::string, relationship> relations;

    node();
    explicit node(const std::string& node_name, const std::string& node_class);

    void add_prop(const std::string& prop_name, const property& prop);
    void update_prop(const std::string& prop_name, const property& prop);
    property get_prop(const std::string& prop_name);
    void del_prop(const std::string& prop_name);

    void add_relationship(const std::string& rel_name, const relationship& rel);
    void update_relationship(const std::string& rel_name, const relationship& rel);
    relationship get_relationship(const std::string& rel_name);
    void del_relationship(const std::string& rel_name);

    void serialize(const std::string& file, int32_t pos);
    void deserialize(const std::string& file, int32_t pos);
};

#endif
