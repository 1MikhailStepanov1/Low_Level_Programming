#include "../include/node.h"

node::node(){}

node::node(const std::string& node_class){
    this->node_class = node_class;
}

void node::add_prop(const std::string& prop_name, const property& prop){
    this->props[prop_name] = prop;
}

void node::update_prop(const std::string &prop_name, const property &prop) {
    this->props[prop_name] = prop;
}

property node::get_prop(const std::string &prop_name) {
    return this->props[prop_name];
}

void node::del_prop(const std::string &prop_name) {
    this->props.erase(prop_name);
}

void node::add_relationship(const std::string &rel_name, const relationship &rel) {
    this->relations[rel_name] = rel;
}

void node::update_relationship(const std::string &rel_name, const relationship &rel) {
    this->relations[rel_name] = rel;
}

relationship node::get_relationship(const std::string &rel_name) {
    return this->relations[rel_name];
}

void node::del_relationship(const std::string &rel_name) {
    this->relations.erase(rel_name);
}

void node::serialize(const std::string &file, int32_t pos) {
    std::ofstream fout(file, BO);
    fout.seekp(META + PAGE * pos);
    cereal::BinaryOutputArchive obin(fout);

    size_t start = fout.tellp();
    obin(id);
    obin(node_class);
    obin(props);
    obin(relations);
    size_t end = fout.tellp();

    assert(end - start <= PAGE);

    fout.close();
}

void node::deserialize(const std::string &file, int32_t pos) {
    std::ifstream fin(file, BO);
    fin.seekg(META + PAGE * pos);
    cereal::BinaryInputArchive ibin(fin);

    size_t start = fin.tellg();
    ibin(id);
    ibin(node_class);
    ibin(props);
    ibin(relations);
    size_t end = fin.tellg();

    assert(end - start <= PAGE);

    fin.close();
}