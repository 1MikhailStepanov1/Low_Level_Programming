#include "../include/ast.h"
#include <iostream>

void print_node_val(const char* node, std::basic_string<char> val, int depth){
    for (int i = 0; i < depth; i++){
        std::cout << "    ";
    }
    std::cout << node << ": " << val << std::endl;
}

const char* get_string_from_node_type(node_type type){
    switch (type) {
        case OPERATION_TYPE_NODE:
            return "Operation_type";
        case SELECTION_SET_NODE:
            return "Selection_set";
        case CLASS_TYPE_NODE:
            return "Class_type";
        case ARGUMENT_NODE:
            return "Argument";
        case FIELD_NODE:
            return "Field";
        case SUB_OPERATION_NODE:
            return "Sub_operation";
        case CONSTANT_NODE:
            return "Constant";
        default:
            return "unknown";
    }
}

const char* get_string_from_operation_type(operation_type type){
    switch (type) {
        case SELECT:
            return "Select";
        case INSERT:
            return "Insert";
        case DELETE:
            return "Delete";
        case UPDATE:
            return "Update";
        default:
            return "unknown";
    }
}

//-----------------   Operation type node   -----------------//

OperationTypeNode::OperationTypeNode(operation_type op_type) {
    this->op_type = op_type;
    this->type = OPERATION_TYPE_NODE;
}

void OperationTypeNode::print(int depth) {
    print_node_val("Operation_type", get_string_from_operation_type(this->op_type), depth);
}

//-----------------   Argument node   -----------------//

ArgumentNode::ArgumentNode(const char *name, ConstantNode *value) {
    this->name = name;
    this->value = value;
    this->type = ARGUMENT_NODE;
}

void ArgumentNode::print(int depth) {
    print_node_val("Argument", this->name, depth);
    print_node_val("Argument_value", this->value->get_str_val(), depth+1);
}

ArgumentNode::~ArgumentNode(){
    delete this->name;
    delete this->value;
}