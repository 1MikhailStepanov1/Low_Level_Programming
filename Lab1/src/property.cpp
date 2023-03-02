#include "../include/property.h"

property::property(const int32_t v) {
    this->tag = INT;
    this->int_val = v;
}

property::property(const bool v) {
    this->tag = BOOL;
    this->bool_val = v;
}

property::property(const float v) {
    this->tag = FLOAT;
    this->float_val = v;
}

property::property(const char* v) {
    this->tag = STRING;
    this->string_val = v;
}

property::type property::get_type() {
    return tag;
}

int32_t property::get_int() {
    return int_val;
}

bool property::get_bool() {
    return bool_val;
}

float property::get_float() {
    return float_val;
}

std::string property::get_string() {
    return string_val;
}

property::property() {

}
