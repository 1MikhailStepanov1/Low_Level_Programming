#include "../include/property.h"

property::property(const int32_t v) {
    this->t = INT;
    this->int_value = v;
}

property::property(const bool v) {
    this->t = BOOL;
    this->bool_value = v;
}

property::property(const float v) {
    this->t = FLOAT;
    this->float_value = v;
}

property::property(const char* v) {
    this->t = STRING;
    this->string_value = v;
}

property::type property::get_type() {
    return t;
}

int32_t property::get_int() {
    return int_value;
}

bool property::get_bool() {
    return bool_value;
}

float property::get_float() {
    return float_value;
}

std::string property::get_string() {
    return string_value;
}
