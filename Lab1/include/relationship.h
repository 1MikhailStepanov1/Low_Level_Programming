#ifndef LLP_RELATIONSHIP_H
#define LLP_RELATIONSHIP_H

#include "../include/util.h"
#include <fstream>
#include <iostream>
#include <cinttypes>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cassert>

#include <cereal/archives/binary.hpp>
#include <cereal/types/unordered_map.hpp>
#include <cereal/types/unordered_set.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>

struct relationship { //relationship
    std::string name;
    std::string related_with;

    relationship();
    explicit relationship(const std::string&, const std::string&);

    template <class Archive>
    void load(Archive& ar) {
        ar(name);
        ar(related_with);
    }

    template <class Archive>
    void save(Archive& ar) const {
        ar(name);
        ar(related_with);
    }

    template <>
    void save<cereal::BinaryOutputArchive>(cereal::BinaryOutputArchive& ar) const {
        ar(name);
        ar(related_with);
    }

    template <>
    void load<cereal::BinaryInputArchive>(cereal::BinaryInputArchive& ar) {
        ar(name);
        ar(related_with);
    }
};
#endif
