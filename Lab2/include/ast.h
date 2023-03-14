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
    CONSTANT_NODE
};

enum sub_operation {
    SET,
    ADD,
    SUB
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
        virtual ~Node();
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
        std::string get_str_type();
        void print(int depth) override;
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
    ~StringConstant(){
        free((void*) value);
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
        const char* class_type;
        Node* selection_set;
        Node* result_set;

    public:
        QueryNode(const char* op_type, const char* class_type);
        void print(int depth) override;
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
        void print(int depth) override;
        ~SelectionSetNode();
};

class ResultSetNode : public Node {
    private:
        std::list<Node*> attributes;
    public:
        ResultSetNode();
        void add_attr(Node* attr);
        void print(int depth) override;
        ~ResultSetNode();
};

class ArgumentWrapperNode : public Node {
    private:
        std::list<Node*> attributes;
    public:
        ArgumentWrapperNode();
        void add_attr(Node* attr);
        void print(int depth) override;
        ~ArgumentWrapperNode();
};

class ArgumentNode : public Node {
    private:
        StringConstant* name;
        ConstantNode* value;
    public:
        ArgumentNode(StringConstant* name, ConstantNode* value);
        void print(int depth) override;
        ~ArgumentNode();
};

class ObjectWrapperNode : public Node {
    private:
        std::list<Node*> attributes;
    public:
        ObjectWrapperNode();
        void add_attr(Node* attr);
        void print(int depth) override;
        ~ObjectWrapperNode();
};

class ObjectNode : public Node {
    private:
        const char* node_name;
        const char* node_class;
        Node* props;
        Node* relations;
    public:
        ObjectNode(const char* node_name, const char* node_class);
        void add_props(Node* fields);
        void add_rels(Node* rels);
        void print(int depth) override;
        ~ObjectNode();
};

class FieldsWrapperNode : public Node {
    private:
        std::list<Node*> attributes;
    public:
        FieldsWrapperNode();
        void add_attr(Node* attr);
        void print(int depth) override;
        ~FieldsWrapperNode();
};

class FieldNode : public Node {
    private:
        StringConstant* name;
        ConstantNode* value;
    public:
        FieldNode(StringConstant* name, ConstantNode* value);
        void print(int depth) override;
        ~FieldNode();
};

class RelationWrapperNode : public Node {
    private:
        std::list<Node*> attributes;
    public:
        RelationWrapperNode();
        void add_attr(Node* attr);
        void print(int depth) override;
        ~RelationWrapperNode();
};

class RelationNode : public Node {
    private:
        ConstantNode* name;
    public:
        RelationNode(ConstantNode* name);
        void print(int depth) override;
        ~RelationNode();
};

class SubOperationWrapperNode : public Node {
    private:
        std::list<Node*> attributes;
    public:
        SubOperationWrapperNode();
        void add_attr(Node* attr);
        void print(int depth) override;
        ~SubOperationWrapperNode();
};

class SubOperationNode : public Node {
    private:
        node_type type;
        const char* sub_op_token;
        ConstantNode* name;
        ConstantNode* value;
    public:
        SubOperationNode(const char* sub_op_token, ConstantNode* name, ConstantNode* value);
        void print(int depth) override;
        ~SubOperationNode();
};

#endif
