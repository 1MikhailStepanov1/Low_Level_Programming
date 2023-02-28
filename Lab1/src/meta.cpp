#include "../include/meta.h"

meta::meta(){
    this->node_count = 0;
    this->free = std::vector<int32_t>();
    this->node_names = std::unordered_map<std::string, int32_t>();
    this->node_classes = std::unordered_map<std::string, std::unordered_set<int32_t>>();
}

int32_t meta::get_id_by_node_name(const std::string &node_name) {
    return this->node_names[node_name];
}

void meta::serialize(const std::string &file, std::ios::openmode mode) {
    std::ofstream fout(file, mode);
    fout.seekp(0);
    cereal::BinaryOutputArchive obin(fout);

    size_t start = fout.tellp();
    obin(node_count);
    obin(node_names);
    obin(node_classes);
    obin(free);
    size_t end = fout.tellp();

    assert(end - start <= META);

    fout.close();
}

void meta::deserialize(const std::string &file) {
    std::ifstream fin(file, BI);
    fin.seekg(0);
    cereal::BinaryInputArchive ibin(fin);

    size_t start = fin.tellg();
    ibin(node_count);
    ibin(node_names);
    ibin(node_classes);
    ibin(free);
    size_t end = fin.tellg();

    assert(end - start <= META);

    fin.close();
}
