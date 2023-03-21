#include "../include/database.h"

database::database(const std::string& file){
    this->file = file;
}

void database::create() {
    information.serialize(file, BIN);
}

void database::open() {
    information.deserialize(file);
}

void database::save(){
    information.serialize(file, BIO);
}

void database::add_node_to_meta(const node& node) {
    information.node_names.insert(std::make_pair(node.node_name, node.id));
    if (information.node_classes.count(node.node_class)){
        information.node_classes[node.node_class].insert(node.id);
    } else{
        information.node_classes.insert(std::make_pair(node.node_class, std::unordered_set<int32_t>{node.id}));
    }
}

void database::node_name_validation(const std::string &node_name, bool is_in_mem) {
    if (is_in_mem) {
        assert(information.node_names.count(node_name) != 0);
    } else{
        assert(information.node_names.count(node_name) == 0);
    }
}

void database::add_node(node node) {
    node_name_validation(node.node_name, false);

    if (!information.free.empty()){
        node.id = information.free.back();
        information.free.pop_back();
    } else {
        node.id = information.node_count + 1;
        information.node_count += 1;
    }

    node.serialize(file, node.id);
    add_node_to_meta(node);
}

node database::get_node(const std::string &node_name) {
    node_name_validation(node_name, true);

    node result;
    result.deserialize(file, information.get_id_by_node_name(node_name));

    return result;
}

void database::delete_node_meta(const std::string &node_name, int32_t pos) {
    information.free.push_back(pos);
    information.node_names.erase(node_name);
    for (auto & node_class : information.node_classes){
        if (information.node_classes.empty()){
            break;
        }
        if (node_class.second.count(pos) != 0){
            node_class.second.erase(pos);
        }
        if (node_class.second.empty()) {
            information.node_classes.erase(node_class.first);
        }
    }
}

void database::delete_node(const std::string &node_name) {
    node_name_validation(node_name, true);
    int32_t pos = information.get_id_by_node_name(node_name);
    delete_node_meta(node_name, pos);

    std::ofstream fout(file, BIO);
    cereal::BinaryOutputArchive obin(fout);
    fout.seekp(META + PAGE * pos, fout.beg);
    fout.close();
}

void database::update_node(const std::string& node_name, node node) {
    node_name_validation(node_name, true);
    delete_node(node_name);
    add_node(node);
}
