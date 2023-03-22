#ifndef LLP_AST_H
#define LLP_AST_H

#include <list>
#include <string>

void print_node_val(const char* node, const char* val, int depth);

enum node_type {
    QUERY_NODE,
    SELECTION_SET_NODE,
    RESULT_SET_NODE,
    ARGUMENT_WRAPPER_NODE,
    ARGUMENT_NODE,
    OBJECT_WRAPPER_NODE,
    OBJECT_NODE,
    FIELDS_WRAPPER_NODE,
    FIELD_NODE,
    RELATION_WRAPPER_NODE,
    RELATION_NODE,
    SUB_OPERATION_WRAPPER,
    SUB_OPERATION,
    FILTER_NODE,
    LOGICAL_OP_NODE,
    CONSTANT_NODE
};

enum sub_operation {
    SET,
    ADD,
    SUB
};

enum filter_operation{
    GT,
    GE,
    LT,
    LE,
    NE,
    LIKE
};

enum logical_operation{
    OR,
    AND
};

enum data_type {
    INT,
    FLOAT,
    STRING,
    BOOL
};

class Node{
    protected:
        node_type type;

    public:
        virtual void print(int depth) = 0;
        virtual ~Node(){};
        node_type get_node_type(){
            return this->type;
        }
};

struct NodeWrapper {
    Node* node;
};

class ConstantNode : public Node {
    private:
        data_type d_type;

    public:
        ConstantNode(data_type d_type){
            this->d_type = d_type;
            this->type = CONSTANT_NODE;
        }
        virtual std::string get_str_val(){
            return "";
        }
};

class IntConstant : public ConstantNode{
    private:
        int value;

    public:
        IntConstant(int value): ConstantNode(INT){
            this->value = value;
        }
        std::string get_str_val() override {
            return std::to_string(this->value);
        }
        void print(int depth) override{
            print_node_val("IntConstant", get_str_val().c_str(), depth);
        }
};

class FloatConstant : public ConstantNode{
    private:
        float value;

    public:
        FloatConstant(float value): ConstantNode(FLOAT){
            this->value = value;
        }
        std::string get_str_val() override {
            return std::to_string(this->value);
        }
        void print(int depth) override {
            print_node_val("FloatConstant", get_str_val().c_str(), depth);
        }
};

class StringConstant : public ConstantNode {
    private:
        const char* value;

    public:
        StringConstant(const char* value) : ConstantNode(STRING) {
            this->value = value;
        }
        std::string get_str_val() override{
            return this->value;
        }
        void print(int depth) override {
            print_node_val("StringConstant", get_str_val().c_str(), depth);
        }
    ~StringConstant() override{
//        free((void*) this->value);
    }
};

class BoolConstant : public ConstantNode{
    private:
        bool value;
    public:
        BoolConstant(bool value) : ConstantNode(BOOL){
            this->value = value;
        }
        std::string get_str_val() override{
            return this->value ? "true" : "false";
        }
        void print(int depth) override{
            print_node_val("BoolConstant", get_str_val().c_str(), depth);
        }
};

enum operation_type {
    SELECT,
    INSERT,
    DELETE,
    UPDATE,
    UNKNOWN
};

class QueryNode : public Node {
    private:
        operation_type oper_type;
        StringConstant* class_type;
        Node* selection_set = NULL;
        Node* result_set = NULL;

    public:
        QueryNode(const char* op_type, StringConstant* class_type);
        void print(int depth) override;
        const char* get_str_oper_type();
        StringConstant* get_class_type();
        Node* get_selection_set();
        Node* get_result_set();
        void setSelectionSet(Node* sel_set);
        void setResultSet(Node* res_set);
        ~QueryNode();
};

class SelectionSetNode : public Node{
    private:
        Node* arguments;
        Node* objects;
        Node* sub_operations;
    public:
        SelectionSetNode();
        void set_args(Node* args);
        void set_objs(Node* objs);
        void set_subops(Node* sub_ops);
        Node* get_arguments();
        Node* get_objects();
        Node* get_sub_operations();
        void print(int depth) override;
        ~SelectionSetNode();
};

class ResultSetNode : public Node {
    private:
        std::list<Node*> attributes;
    public:
        ResultSetNode();
        void add_attr(Node* attr);
        std::list<Node*> get_attributes();
        void print(int depth) override;
        ~ResultSetNode();
};

class ArgumentWrapperNode : public Node {
    private:
        std::list<Node*> attributes;
    public:
        ArgumentWrapperNode();
        void add_attr(Node* attr);
        std::list<Node*> get_attributes();
        void print(int depth) override;
        ~ArgumentWrapperNode();
};

class LogicalOperationNode : public Node {
private:
    logical_operation logic_op;
    Node* attributes = NULL;
public:
    LogicalOperationNode(logical_operation logic_op);
    const char* get_logic_op_type();
    void set_attr(Node* attr);
    Node* get_attr();
    void print(int depth) override;
    ~LogicalOperationNode();
};

class FilterNode : public Node {
    private:
        filter_operation filter_flag;
    public:
        FilterNode(filter_operation filter_flag);
        void print(int depth) override;
};

class ArgumentNode : public Node {
    private:
        StringConstant* name;
        ConstantNode* value;
        Node* filerNode = NULL;
    public:
        ArgumentNode(StringConstant* name, ConstantNode* value);
        void set_filter(Node* filterNode);
        StringConstant* get_name();
        ConstantNode* get_value();
        void print(int depth) override;
        ~ArgumentNode();
};

class ObjectWrapperNode : public Node {
    private:
        std::list<Node*> attributes;
    public:
        ObjectWrapperNode();
        void add_attr(Node* attr);
        std::list<Node*> get_attributes();
        void print(int depth) override;
        ~ObjectWrapperNode();
};

class ObjectNode : public Node {
    private:
        StringConstant* node_name;
        Node* props = NULL;
        Node* relations = NULL;
    public:
        ObjectNode(StringConstant* node_name);
        void add_props(Node* fields);
        void add_rels(Node* rels);
        Node* get_props();
        Node* get_rels();
        StringConstant* get_node_name();
        void print(int depth) override;
        ~ObjectNode();
};

class FieldsWrapperNode : public Node {
    private:
        std::list<Node*> attributes;
    public:
        FieldsWrapperNode();
        void add_attr(Node* attr);
        std::list<Node*> get_attributes();
        void print(int depth) override;
        ~FieldsWrapperNode();
};

class FieldNode : public Node {
    private:
        StringConstant* name;
        ConstantNode* value;
    public:
        FieldNode(StringConstant* name, ConstantNode* value);
        StringConstant* get_name();
        ConstantNode* get_value();
        void print(int depth) override;
        ~FieldNode();
};

class RelationWrapperNode : public Node {
    private:
        std::list<Node*> attributes;
    public:
        RelationWrapperNode();
        void add_attr(Node* attr);
        std::list<Node*> get_attributes();
        void print(int depth) override;
        ~RelationWrapperNode();
};

class RelationNode : public Node {
    private:
        ConstantNode* name;
        StringConstant* value;
    public:
        RelationNode(ConstantNode* name, StringConstant* value);
        ConstantNode* get_name();
        StringConstant* get_value();
        void print(int depth) override;
        ~RelationNode();
};

class SubOperationWrapperNode : public Node {
    private:
        std::list<Node*> attributes;
    public:
        SubOperationWrapperNode();
        void add_attr(Node* attr);
        std::list<Node*> get_attributes();
        void print(int depth) override;
        ~SubOperationWrapperNode();
};

class SubOperationNode : public Node {
    private:
        node_type type;
        sub_operation sub_op_token;
        ConstantNode* name;
        ConstantNode* value;
    public:
        SubOperationNode(sub_operation sub_op_token, ConstantNode* name, ConstantNode* value);
        const char* get_sub_op();
        ConstantNode* get_name();
        ConstantNode* get_value();
        void print(int depth) override;
        ~SubOperationNode();
};

#endif
