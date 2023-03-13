#ifndef LLP_AST_H
#define LLP_AST_H

#include <list>
#include <string>

void print_node_val(const char* node, std::basic_string<char> val, int depth);

enum node_type {
    OPERATION_TYPE_NODE,
    SELECTION_SET_NODE,
    RESULT_SET_NODE,
    CLASS_TYPE_NODE,
    ARGUMENT_NODE,
    FIELD_NODE,
    SUB_OPERATION_NODE,
    CONSTANT_NODE
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

enum operation_type {
    SELECT,
    INSERT,
    DELETE,
    UPDATE
};

class OperationTypeNode : public Node{
    private:
        operation_type op_type;

    public:
        OperationTypeNode(operation_type op_type);
        void print(int depth) override;
        ~OperationTypeNode();
};

class SelectionSetNode : public Node{
    private:
        std::list<Node*> set_nodes;

    public:
        SelectionSetNode() {
            this->type = SELECTION_SET_NODE;
        };
        void add_attr(Node* attribute);
        void print(int depth) override;
        ~SelectionSetNode();
};

class ResultSetNode : public Node{
    private:
        std::list<Node*> res_nodes;
    public:
        ResultSetNode(){
            this->type = RESULT_SET_NODE;
        };
        void add_attr(Node* attribute);
        void print(int depth) override;
        ~ResultSetNode();
};

enum data_type {
    INT,
    FLOAT,
    STRING,
    BOOL
};

class ConstantNode : public Node{
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

class ArgumentNode : public Node{
    private:
        ConstantNode* value;
        const char* name;
    public:
        ArgumentNode(const char* name, ConstantNode* value);
        void print(int depth) override;
        ~ArgumentNode();
};

class ClassTypeNode : public Node{
    private:
        const char* value;
    public:
        ClassTypeNode(const char* value);
        void print(int depth) override;
        ~ClassTypeNode();
};

class FieldNode : public Node{
    private:
        const char* name;
    public:
        FieldNode(const char* name);
        void print(int depth) override;
        ~FieldNode();
};

enum sub_operation {
    SET,
    ADD,
    SUB
};

class SubOperationNode : public Node{
    private:
        sub_operation sub_op_type;
    public:
        SubOperationNode(sub_operation sub_op);
        void print(int depth) override;
        ~SubOperationNode();
};

class ReferenceNode : public Node {
    private:
    public:
        ReferenceNode();
        ~ReferenceNode();
};

#endif
