#include "../include/relationship.h"

relationship::relationship(){}

relationship::relationship(const std::string& name, const std::string& related_with) {
    this->name = name;
    this->related_with = related_with;
}

void relationship::serialize(const std::string &file, int32_t pos) {
    std::ofstream fout(file, BO);
    fout.seekp(META + PAGE * pos);
    cereal::BinaryOutputArchive obin(fout);

    size_t start = fout.tellp();
    obin(name);
    obin(related_with);
    size_t end = fout.tellp();

    assert(end - start <= PAGE);

    fout.close();
}

void relationship::deserialize(const std::string &file, int32_t pos) {
    std::ifstream fin(file, BI);
    fin.seekg(META + PAGE * pos);
    cereal::BinaryInputArchive ibin(fin);

    size_t start = fin.tellg();
    ibin(name);
    ibin(related_with);
    size_t end = fin.tellg();

    assert(end - start <= PAGE);

    fin.close();
}