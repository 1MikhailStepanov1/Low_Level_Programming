#ifndef LLP_PROPERTY_H
#define LLP_PROPERTY_H

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

struct property { //field

    enum type {INT, BOOL, FLOAT, STRING};

private:
    type tag;
    int32_t int_val;
    bool bool_val{};
    float float_val{};
    std::string string_val;

public:
    property();
    explicit property(const int32_t v);
    explicit property(const bool v);
    explicit property(const float v);
    explicit property(const char* v);

    type get_type();
    int32_t get_int();
    bool get_bool();
    float get_float();
    std::string get_string();
    std::string get_value();

    template <class Archive>
    void load(Archive& ar) {
        ar(tag);
        switch (tag) {
            case INT: ar(int_val);
            case BOOL: ar(bool_val);
            case FLOAT: ar(float_val);
            case STRING: ar(string_val);
        }
    }

    template <class Archive>
    void save(Archive& ar) const {
        ar(tag);
        switch (tag) {
            case INT: ar(int_val);
            case BOOL: ar(bool_val);
            case FLOAT: ar(float_val);
            case STRING: ar(string_val);
        }
    }

    template <>
    void save<cereal::BinaryOutputArchive>(cereal::BinaryOutputArchive& ar) const {
        ar(tag);
        switch (tag) {
            case INT: ar(int_val);
            case BOOL: ar(bool_val);
            case FLOAT: ar(float_val);
            case STRING: ar(string_val);
        }
    }

    template <>
    void load<cereal::BinaryInputArchive>(cereal::BinaryInputArchive& ar) {
        ar(tag);
        switch (tag) {
            case INT: ar(int_val);
            case BOOL: ar(bool_val);
            case FLOAT: ar(float_val);
            case STRING: ar(string_val);
        }
    }

};

#endif
