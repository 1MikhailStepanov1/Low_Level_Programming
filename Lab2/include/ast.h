#ifndef LLP_AST_H
#define LLP_AST_H

#include <list>
#include <string>

enum node_type {
    OPERATION_TYPE_NODE,
    SELECTION_SET_NODE,
    CLASS_TYPE_NODE,
    ARGUMENT_NODE,
    ARGUMENT_VALUE_NODE,
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

enum operation_type {
    SELECT,
    INSERT,
    DELETE,
    UPDATE
};

class OperationTypeNode : public Node{
    private:
        operation_type type;

    public:
    OperationTypeNode(operation_type type);
    void print(int depth) override;
    ~OperationTypeNode();
};

class SelectionSetNode : public Node{
    private:
        std::list<Node*> set_nodes;

    public:
        SelectionSetNode(){
            this->type = SELECTION_SET_NODE;
        }
        void add_attr(Node* attribute);
        void print(int depth) override;
        ~SelectionSetNode();
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
#endif
