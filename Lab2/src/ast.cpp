#include "../include/ast.h"
#include <iostream>
#include <vector>
#include <map>

void print_node_val(const char* node, const char* val, int depth){
    for (int i = 0; i < depth; i++){
        std::cout << "  ";
    }
    std::cout << node << ": " << val << std::endl;
}

const char* get_string_from_node_type(node_type type){
    switch (type) {
        case QUERY_NODE:
            return "Query";
        case SELECTION_SET_NODE:
            return "SelectionSet";
        case RESULT_SET_NODE:
            return "ResultSet";
        case ARGUMENT_WRAPPER_NODE:
            return "Arguments";
        case ARGUMENT_NODE:
            return "Argument";
        case OBJECT_WRAPPER_NODE:
            return "Objects";
        case OBJECT_NODE:
            return "Object";
        case FIELDS_WRAPPER_NODE:
            return "Fields";
        case FIELD_NODE:
            return "Field";
        case RELATION_WRAPPER_NODE:
            return "Relations";
        case RELATION_NODE:
            return "Relation";
        case SUB_OPERATION_WRAPPER:
            return "SubOperations";
        case SUB_OPERATION:
            return "Sub_Operation";
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

operation_type get_op_type_from_string(const char* str){
    if (str == "select") {
        return SELECT;
    } else if (str == "delete"){
        return DELETE;
    } else if (str == "insert"){
        return INSERT;
    } else if (str == "update") {
        return UPDATE;
    } else return UNKNOWN;
}



// ---------------------------   Query Node   --------------------------- //
QueryNode::QueryNode(const char* op_type, const char *class_type) {
    this->type = QUERY_NODE;
    this->oper_type = get_op_type_from_string(op_type);
    this->class_type = class_type;
}

void QueryNode::setSelectionSet(Node* sel_set) {
    this->selection_set = sel_set;
}

void QueryNode::setResultSet(Node* res_set) {
    this->result_set = res_set;
}

void QueryNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), get_string_from_operation_type(this->oper_type), depth);
    print_node_val("class_type", this->class_type, depth);
    this->selection_set->print(depth+1);
    this->result_set->print(depth+1);
}

QueryNode::~QueryNode() {
    free((void*) class_type);
    delete this->selection_set;
    delete this->result_set;
}

// ---------------------------   Selection Set Node   --------------------------- //
SelectionSetNode::SelectionSetNode() {
    this->type = SELECTION_SET_NODE;
}

void SelectionSetNode::set_args(Node * args) {
    this->arguments = args;
}

void SelectionSetNode::set_objs(Node * objs) {
    this->objects = objs;
}

void SelectionSetNode::set_subops(Node * sub_ops) {
    this->sub_operations = sub_ops;
}

void SelectionSetNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), "", depth);
    this->arguments->print(depth+1);
    this->objects->print(depth+1);
    this->sub_operations->print(depth+1);
}

SelectionSetNode::~SelectionSetNode() {
    delete this->arguments;
    delete this->objects;
    delete this->sub_operations;
}

// ---------------------------   Result Set Node   --------------------------- //
ResultSetNode::ResultSetNode() {
    this->type = RESULT_SET_NODE;
}

void ResultSetNode::add_attr(Node *attr) {
    this->attributes.push_back(attr);
}

void ResultSetNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), "", depth);
    for (auto n : attributes){
        n->print(depth+1);
    }
}

ResultSetNode::~ResultSetNode() {
    for (auto n : attributes){
        delete n;
    }
}

// ---------------------------   Argument Wrapper Node   --------------------------- //
ArgumentWrapperNode::ArgumentWrapperNode() {
    this->type = ARGUMENT_WRAPPER_NODE;
}

void ArgumentWrapperNode::add_attr(Node *attr) {
    this->attributes.push_back(attr);
}

void ArgumentWrapperNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), "", depth);
    for (auto n : this->attributes){
        n->print(depth+1);
    }
}

ArgumentWrapperNode::~ArgumentWrapperNode() {
    for (auto n : this->attributes){
        delete n;
    }
}

// ---------------------------   Argument Node   --------------------------- //
ArgumentNode::ArgumentNode(StringConstant *name, ConstantNode *value) {
    this->type = ARGUMENT_NODE;
    this->name = name;
    this->value = value;
}

void ArgumentNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), this->name->get_str_val().c_str(), depth);
    print_node_val("Argument_value", this->value->get_str_val().c_str(), depth);
}

ArgumentNode::~ArgumentNode() {
    delete this->name;
    delete this->value;
}

// ---------------------------   Object Wrapper Node   --------------------------- //
ObjectWrapperNode::ObjectWrapperNode() {
    this->type = OBJECT_WRAPPER_NODE;
}

void ObjectWrapperNode::add_attr(Node *attr) {
    this->attributes.push_back(attr);
}

void ObjectWrapperNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), "", depth);
    for (auto n : attributes){
        n->print(depth+1);
    }
}

ObjectWrapperNode::~ObjectWrapperNode() {
    for (auto n : attributes){
        delete n;
    }
}

// ---------------------------   Object Node   --------------------------- //
ObjectNode::ObjectNode(const char* node_name, const char* node_class) {
    this->type = OBJECT_NODE;
    this->node_name = node_name;
    this->node_class = node_class;
}

void ObjectNode::add_props(Node* fields) {
    this->props = fields;
}

void ObjectNode::add_rels(Node *rels) {
    this->relations = rels;
}

void ObjectNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), "", depth);
    print_node_val("Name", this->node_name, depth+1);
    print_node_val("Class", this->node_class, depth+1);
    props->print(depth+1);
    relations->print(depth+1);
}

ObjectNode::~ObjectNode() {
    free((void*) this->node_name);
    free((void*) this->node_class);
    delete this->props;
    delete this->relations;
}

// ---------------------------   Fields Wrapper Node   --------------------------- //
FieldsWrapperNode::FieldsWrapperNode() {
    this->type = FIELDS_WRAPPER_NODE;
}

void FieldsWrapperNode::add_attr(Node *attr) {
    this->attributes.push_back(attr);
}

void FieldsWrapperNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), "", depth);
    for (auto n : this->attributes){
        n->print(depth+1);
    }
}

FieldsWrapperNode::~FieldsWrapperNode() {
    for (auto n : this->attributes){
        delete n;
    }
}

// ---------------------------   Field Node   --------------------------- //
FieldNode::FieldNode(StringConstant *name, ConstantNode *value) {
    this->type = FIELD_NODE;
    this->name = name;
    this->value = value;
}

void FieldNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), this->name->get_str_val().c_str(), depth);
    print_node_val("Value", this->value->get_str_val().c_str(), depth);
}

FieldNode::~FieldNode() {
    delete this->name;
    delete this->value;
}

// ---------------------------   Relation Wrapper Node   --------------------------- //
RelationWrapperNode::RelationWrapperNode() {
    this->type = RELATION_WRAPPER_NODE;
}

void RelationWrapperNode::add_attr(Node *attr) {
    this->attributes.push_back(attr);
}

void RelationWrapperNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), "", depth);
    for (auto n : this->attributes){
        n->print(depth+1);
    }
}

RelationWrapperNode::~RelationWrapperNode() {
    for (auto n : this->attributes){
        delete n;
    }
}

// ---------------------------   Relation Node   --------------------------- //
RelationNode::RelationNode(ConstantNode *name) {
    this->type = RELATION_NODE;
    this->name = name;
}

void RelationNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), this->name->get_str_val().c_str(), depth);
}

RelationNode::~RelationNode() {
    delete this->name;
}

// ---------------------------   SubOperation Wrapper Node   --------------------------- //
SubOperationWrapperNode::SubOperationWrapperNode() {
    this->type = SUB_OPERATION_WRAPPER;
}

void SubOperationWrapperNode::add_attr(Node *attr) {
    this->attributes.push_back(attr);
}

void SubOperationWrapperNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), "", depth);
    for (auto n : this->attributes){
        n->print(depth+1);
    }
}

SubOperationWrapperNode::~SubOperationWrapperNode() {
    for (auto n : this->attributes){
        delete n;
    }
}

// ---------------------------   SubOperation Node   --------------------------- //
SubOperationNode::SubOperationNode(const char *sub_op_token, ConstantNode *name, ConstantNode *value) {
    this->type = SUB_OPERATION;
    this->sub_op_token = sub_op_token;
    this->name = name;
    this->value = value;
}

void SubOperationNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), this->sub_op_token, depth);
    print_node_val("Name", this->name->get_str_val().c_str(), depth+1);
    print_node_val("Value", this->value->get_str_val().c_str(), depth+1);
}

SubOperationNode::~SubOperationNode() {
    free((void*) sub_op_token);
    delete this->name;
    delete this->value;
}
