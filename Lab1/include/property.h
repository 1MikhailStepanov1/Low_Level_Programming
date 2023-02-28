#ifndef LLP_PROPERTY_H
#define LLP_PROPERTY_H

#include <cereal/archives/binary.hpp>
#include <cereal/types/string.hpp>

struct property { //field

    enum type {INT, BOOL, FLOAT, STRING};
private:
    type t;
    int32_t int_value;
    bool bool_value;
    float float_value;
    std::string string_value;

public:
    property();
    property(const int32_t v);
    property(const bool v);
    property(const float v);
    property(const char* v);

    type get_type();
    int32_t get_int();
    float get_float();
    bool get_bool();
    std::string get_string();

    template <class Archive>
    void load(Archive& archive){
        archive(t);
        switch (t) {
            case INT: archive(int_value);
            case BOOL: archive(bool_value);
            case FLOAT: archive(float_value);
            case STRING: archive(string_value);
        }
    }

    template <class Archive>
    void save(Archive& archive){
        archive(t);
        switch (t) {
            case INT: archive(int_value);
            case BOOL: archive(bool_value);
            case FLOAT: archive(float_value);
            case STRING: archive(string_value);
        }
    }

    template <>
    void save<cereal::BinaryOutputArchive>(cereal::BinaryOutputArchive  &archive) const {
        archive(t);
        switch (t) {
            case INT: archive(int_value);
            case BOOL: archive(bool_value);
            case FLOAT: archive(float_value);
            case STRING: archive(string_value);
        }
    }

    template <>
    void load<cereal::BinaryInputArchive>(cereal::BinaryInputArchive& archive) {
        archive(t);
        switch (t) {
            case INT: archive(int_value);
            case BOOL: archive(bool_value);
            case FLOAT: archive(float_value);
            case STRING: archive(string_value);
        }
    }

};

#endif
