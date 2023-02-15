#ifndef LLP_RELATIONSHIP_H
#define LLP_RELATIONSHIP_H

#include "../include/util.h"

struct relationship { //relationship
    std::string name;
    std::string related_with;

    relationship();
    explicit relationship(const std::string&, const std::string&);

    void serialize(const std::string &file, int32_t pos);
    void deserialize(const std::string &file, int32_t pos);
};
#endif
