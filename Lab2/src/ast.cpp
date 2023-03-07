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

const char* get_string_from_sub_oper_type(sub_operation type){
    switch (type) {
        case SET:
            return "set";
        case ADD:
            return "add";
        case SUB:
            return "sub";
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

//-----------------   Selection set node   -----------------//

void SelectionSetNode::add_attr(Node *attribute) {
    this->set_nodes.push_back(attribute);
}

void SelectionSetNode::print(int depth) {
    print_node_val("Selection_set", "", depth);
    for (auto n : this->set_nodes){
        n->print(depth+1);
    }
}

SelectionSetNode::~SelectionSetNode(){
    for (auto n : this->set_nodes){
        delete n;
    }
}

//-----------------   Result set node   -----------------//

void ResultSetNode::add_attr(Node *attribute) {
    this->res_nodes.push_back(attribute);
}

void ResultSetNode::print(int depth) {
    print_node_val("Selection_set", "", depth);
    for (auto n : this->res_nodes){
        n->print(depth+1);
    }
}

ResultSetNode::~ResultSetNode(){
    for (auto n : this->res_nodes){
        delete n;
    }
}

//-----------------   Class type node   -----------------//

ClassTypeNode::ClassTypeNode(const char *value) {
    this->value = value;
    this->type = CLASS_TYPE_NODE;
}

void ClassTypeNode::print(int depth) {
    print_node_val("Class_type", this->value, depth);
}

ClassTypeNode::~ClassTypeNode(){
    delete this->value;
}

//-----------------   Field node   -----------------//

FieldNode::FieldNode(const char *name) {
    this->name = name;
    this->type = FIELD_NODE;
}

void FieldNode::print(int depth) {
    print_node_val("Field", this->name, depth);
}

FieldNode::~FieldNode(){
    delete this->name;
}

//-----------------   Sub operation node   -----------------//

SubOperationNode::SubOperationNode(sub_operation sub_op) {
    this->sub_op_type = sub_op;
    this->type = SUB_OPERATION_NODE;
}

void SubOperationNode::print(int depth) {
    print_node_val("Sub_operation", get_string_from_sub_oper_type(this->sub_op_type), depth);
}
