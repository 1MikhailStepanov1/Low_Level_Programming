#include "../include/XMLFormatter.h"

logical_condition_t form_logical_condition(LogicalOperationNode* logic_node){
    logical_condition_t logical_condition = logical_condition_t(logic_node->get_logic_op_type());

    ArgumentWrapperNode* arg_wrap = (ArgumentWrapperNode*) logic_node->get_attr();
    for (auto n : arg_wrap->get_attributes()){
        if (n->get_node_type() == ARGUMENT_NODE){
            ArgumentNode* arg = (ArgumentNode*) n;
            constant_t c = constant_t(arg->get_name()->get_str_val(), arg->get_value()->get_str_val());
            logical_condition.field().push_back(c);
        }
        if (n->get_node_type() == LOGICAL_OP_NODE){
            logical_condition.condition(form_logical_condition((LogicalOperationNode*) n));
        }
    }
    return logical_condition;
}

selection_set_t form_selection_set(SelectionSetNode* selectionSetNode){
    selection_set_t selection_set = selection_set_t();

    ArgumentWrapperNode* argument_wrapper = (ArgumentWrapperNode*) selectionSetNode->get_arguments();
    ObjectWrapperNode* object_wrapper = (ObjectWrapperNode*) selectionSetNode->get_objects();
    SubOperationWrapperNode* sub_ops_wrapper = (SubOperationWrapperNode*) selectionSetNode->get_sub_operations();

    if (argument_wrapper != NULL) {
        argument_t args = argument_t();
        std::list <Node*> arg_list = argument_wrapper->get_attributes();
        for (auto node: arg_list) {
            if (node->get_node_type() == LOGICAL_OP_NODE) {
                LogicalOperationNode *logic_node = (LogicalOperationNode *) node;
                args.logic_op().push_back(form_logical_condition(logic_node));
            }
            if (node->get_node_type() == ARGUMENT_NODE) {
                ArgumentNode *argumentNode = (ArgumentNode *) node;
                constant_t argument = constant_t(argumentNode->get_name()->get_str_val(),
                                                 argumentNode->get_value()->get_str_val());
                args.field().push_back(argument);
            }
        }
        selection_set.argument().push_back(args);
    }

    if (object_wrapper != NULL){
        std::list<Node*> obj_list = object_wrapper->get_attributes();
        for (auto o : obj_list){
            ObjectNode* obj_node = (ObjectNode*) o;
            object_t obj = object_t(obj_node->get_node_name()->get_str_val());

            if (obj_node->get_props() != NULL) {
                FieldsWrapperNode *fields_wrapper = (FieldsWrapperNode *) obj_node->get_props();
                for (auto f: fields_wrapper->get_attributes()) {
                    FieldNode *field_node = (FieldNode *) f;
                    constant_t field = constant_t(field_node->get_name()->get_str_val(),
                                                  field_node->get_value()->get_str_val());
                    obj.field().push_back(field);
                }
            }
            if (obj_node->get_rels() != NULL){
                RelationWrapperNode* relations_wrapper = (RelationWrapperNode*) obj_node->get_rels();
                for (auto r : relations_wrapper->get_attributes()){
                    RelationNode* relation_node = (RelationNode*) r;
                    constant_t relation = constant_t(relation_node->get_name()->get_str_val(),
                                                     relation_node->get_value()->get_str_val());
                    obj.relation().push_back(relation);
                }
            }
            selection_set.object().push_back(obj);
        }
    }

    if (sub_ops_wrapper != NULL){
        std::list<Node*> sub_ops_list = sub_ops_wrapper->get_attributes();
        for (auto sub : sub_ops_list){
            SubOperationNode* sub_op_node = (SubOperationNode*) sub;
            constant_t field = constant_t(sub_op_node->get_name()->get_str_val(), sub_op_node->get_value()->get_str_val());
            sub_operation_t sub_op = sub_operation_t(sub_op_node->get_sub_op(), field);
            selection_set.sub_operations().push_back(sub_op);
        }
    }
    return selection_set;
}

result_set_t form_result_set(ResultSetNode* resultSetNode){
    result_set_t result_set = result_set_t();
    for (auto n : resultSetNode->get_attributes()){
        StringConstant* constant = (StringConstant*) n;
        result_set.field().push_back(constant->get_str_val());
    }
    return result_set;
}

request_t convert_to_XML_format(NodeWrapper& nodeWrapper){
    QueryNode* node = (QueryNode*)nodeWrapper.node;

    selection_set_t selection_set = form_selection_set((SelectionSetNode*)node->get_selection_set());
    result_set_t result_set = form_result_set((ResultSetNode*) node->get_result_set());
    request_t request = request_t(node->get_str_oper_type(), node->get_class_type()->get_str_val(), selection_set, result_set);
    return request;
}