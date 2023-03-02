#include "../include/relationship.h"

relationship::relationship(){}

relationship::relationship(const std::string& name, const std::string& related_with) {
    this->name = name;
    this->related_with = related_with;
}