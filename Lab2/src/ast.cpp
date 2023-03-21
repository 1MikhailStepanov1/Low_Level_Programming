#include "../include/ast.h"
#include <iostream>
#include <cstring>
#include <list>

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
        case FILTER_NODE:
            return "Filter";
        case LOGICAL_OP_NODE:
            return "Logical_op";
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
    if (strcmp(str, "select") == 0) {
        return SELECT;
    } else if (strcmp(str, "delete") == 0){
        return DELETE;
    } else if (strcmp(str, "insert") == 0){
        return INSERT;
    } else if (strcmp(str, "update") == 0) {
        return UPDATE;
    } else return UNKNOWN;
}

const char* get_str_filter_from_enum(filter_operation operation){
    switch (operation) {
        case GT:
            return "GT";
        case GE:
            return "GE";
        case LT:
            return "LT";
        case LE:
            return "LE";
        case NE:
            return "NE";
        case LIKE:
            return "LIKE";
        default:
            return "unknown";
    }
}

const char* get_str_from_logic_op_type (logical_operation logic_op){
    switch (logic_op) {
        case OR:
            return "OR";
        case AND:
            return "AND";
        default:
            return "unknown";
    }
}

const char* get_str_from_sub_op_type(sub_operation sub_op){
    switch (sub_op) {
        case SET:
            return "SET";
        case ADD:
            return "ADD";
        case SUB:
            return "SUB";
        default:
            return "Unknown";
    }
}



// ---------------------------   Query Node   --------------------------- //
QueryNode::QueryNode(const char* op_type, StringConstant *class_type) {
    this->type = QUERY_NODE;
    this->oper_type = get_op_type_from_string(op_type);
    this->class_type = class_type;
}

const char* QueryNode::get_str_oper_type(){
    return get_string_from_operation_type(this->oper_type);
}

StringConstant* QueryNode::get_class_type(){
    return this->class_type;
}

Node *QueryNode::get_selection_set() {
    return this->selection_set;
}

Node *QueryNode::get_result_set() {
    return this->result_set;
}

void QueryNode::setSelectionSet(Node* sel_set) {
    this->selection_set = sel_set;
}

void QueryNode::setResultSet(Node* res_set) {
    this->result_set = res_set;
}

void QueryNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), get_string_from_operation_type(this->oper_type), depth);
    print_node_val("class_type", this->class_type->get_str_val().c_str(), depth);
    this->selection_set->print(depth+1);
    this->result_set->print(depth+1);
}

QueryNode::~QueryNode() {
    delete this->class_type;
    delete this->selection_set;
    delete this->result_set;
}

// ---------------------------   Selection Set Node   --------------------------- //
SelectionSetNode::SelectionSetNode() {
    this->type = SELECTION_SET_NODE;
    this->arguments = NULL;
    this->objects = NULL;
    this->sub_operations = NULL;
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

Node* SelectionSetNode::get_arguments() {
    return this->arguments;
}

Node* SelectionSetNode::get_objects() {
    return this->objects;
}

Node* SelectionSetNode::get_sub_operations() {
    return this->sub_operations;
}

void SelectionSetNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), "", depth);
    if (this->arguments != NULL) {
        this->arguments->print(depth + 1);
    }
    if (this->objects != NULL) {
        this->objects->print(depth+1);
    }
    if (this->sub_operations != NULL) {
        this->sub_operations->print(depth + 1);
    }
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

std::list<Node *> ResultSetNode::get_attributes() {
    return this->attributes;
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

std::list<Node*> ArgumentWrapperNode::get_attributes() {
    return this->attributes;
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

// ---------------------------   Logical Operation Node   --------------------------- //

LogicalOperationNode::LogicalOperationNode(logical_operation logic_op) {
    this->type = LOGICAL_OP_NODE;
    this->logic_op = logic_op;
}

const char* LogicalOperationNode::get_logic_op_type() {
    return get_str_from_logic_op_type(this->logic_op);
}

void LogicalOperationNode::set_attr(Node *attr) {
    this->attributes = attr;
}

Node *LogicalOperationNode::get_attr() {
    return this->attributes;
}

void LogicalOperationNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), get_str_from_logic_op_type(this->logic_op), depth);
    if (this->attributes != NULL){
        this->attributes->print(depth+1);
    }
}

LogicalOperationNode::~LogicalOperationNode() {
    delete this->attributes;
}

// ---------------------------   Filter Node   --------------------------- //

FilterNode::FilterNode(filter_operation filter_flag) {
    this->type = FILTER_NODE;
    this->filter_flag = filter_flag;
}

void FilterNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), get_str_filter_from_enum(this->filter_flag), depth);
}


// ---------------------------   Argument Node   --------------------------- //
ArgumentNode::ArgumentNode(StringConstant *name, ConstantNode *value) {
    this->type = ARGUMENT_NODE;
    this->name = name;
    this->value = value;
}

void ArgumentNode::set_filter(Node *filterNode) {
    this->filerNode = filterNode;
}

StringConstant *ArgumentNode::get_name() {
    return this->name;
}

ConstantNode *ArgumentNode::get_value() {
    return this->value;
}

void ArgumentNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), this->name->get_str_val().c_str(), depth);
    print_node_val("Argument_value", this->value->get_str_val().c_str(), depth+1);
    if (this->filerNode != NULL){
        this->filerNode->print(depth+1);
    }
}

ArgumentNode::~ArgumentNode() {
    delete this->filerNode;
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

std::list<Node*> ObjectWrapperNode::get_attributes() {
    return this->attributes;
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
ObjectNode::ObjectNode(StringConstant* node_name) {
    this->type = OBJECT_NODE;
    this->node_name = node_name;
}

void ObjectNode::add_props(Node* fields) {
    this->props = fields;
}

void ObjectNode::add_rels(Node *rels) {
    this->relations = rels;
}

Node *ObjectNode::get_props() {
    return this->props;
}

Node *ObjectNode::get_rels() {
    return this->relations;
}

StringConstant *ObjectNode::get_node_name() {
    return this->node_name;
}

void ObjectNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), "", depth);
    print_node_val("Name", this->node_name->get_str_val().c_str(), depth + 1);
    if (this->props != NULL) {
        this->props->print(depth + 1);
    }
    if (this->relations != NULL) {
        this->relations->print(depth + 1);
    }
}

ObjectNode::~ObjectNode() {
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

std::list<Node *> FieldsWrapperNode::get_attributes() {
    return this->attributes;
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

StringConstant *FieldNode::get_name() {
    return this->name;
}

ConstantNode *FieldNode::get_value() {
    return this->value;
}

void FieldNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), this->name->get_str_val().c_str(), depth);
    print_node_val("Value", this->value->get_str_val().c_str(), depth+1);
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

std::list<Node *> RelationWrapperNode::get_attributes() {
    return this->attributes;
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
RelationNode::RelationNode(ConstantNode *name, StringConstant* value) {
    this->type = RELATION_NODE;
    this->name = name;
    this->value = value;
}

ConstantNode *RelationNode::get_name() {
    return this->name;
}

StringConstant *RelationNode::get_value() {
    return this->value;
}

void RelationNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), this->name->get_str_val().c_str(), depth);
    print_node_val("Value", this->value->get_str_val().c_str(), depth+1);
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

std::list<Node *> SubOperationWrapperNode::get_attributes() {
    return this->attributes;
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
SubOperationNode::SubOperationNode(sub_operation sub_op_token, ConstantNode *name, ConstantNode *value) {
    this->type = SUB_OPERATION;
    this->sub_op_token = sub_op_token;
    this->name = name;
    this->value = value;
}

const char *SubOperationNode::get_sub_op() {
    return get_str_from_sub_op_type(this->sub_op_token);
}

ConstantNode *SubOperationNode::get_name() {
    return this->name;
}

ConstantNode *SubOperationNode::get_value() {
    return this->value;
}

void SubOperationNode::print(int depth) {
    print_node_val(get_string_from_node_type(this->type), get_str_from_sub_op_type(this->sub_op_token), depth);
    print_node_val("Name", this->name->get_str_val().c_str(), depth+1);
    print_node_val("Value", this->value->get_str_val().c_str(), depth+1);
}

SubOperationNode::~SubOperationNode() {
    delete this->name;
    delete this->value;
}
