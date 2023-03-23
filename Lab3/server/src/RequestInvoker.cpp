#include "../include/RequestInvoker.h"
#include <vector>

RequestInvoker::RequestInvoker(struct database db) {
    this->db = db;
    this->db.create();
}

struct parsed_field {
    int place; // empty - 0, props - 1, relations - 2
    std::string name;
};

struct parsed_field parse_field(std::string field) {
    size_t pos = field.find('.');
    struct parsed_field result = {0, field};
    if (pos != std::string::npos) {
        std::string first_part = field.substr(0, pos);
        std::string second_part = field.substr(pos + 1);
        result.name = second_part;
        if (strcmp(first_part.c_str(), "props") == 0) {
            result.place = 1;
        } else result.place = 2;
    }
    return result;
}

void parse_logic_op(std::vector <node> &nodes, logical_condition_t logic_op) {
    if (logic_op.condition().present()) {
        parse_logic_op(nodes, logic_op.condition()->logical_operation());
    } else {
        std::vector <node> temp;
        temp.assign(nodes.begin(), nodes.end());
        if (strcmp(logic_op.logical_operation().c_str(), "OR") == 0) {
            for (int i = 0; i < nodes.size(); i++) {
                bool res = 0;
                for (auto arg: logic_op.field()) {
                    struct parsed_field temp = parse_field(arg.type());
                    if (temp.place == 0) {
                        if (strcmp(temp.name.c_str(), "id") == 0) {
                            int id = stoi(arg.value());
                            if (nodes[i].id == id) res += 1;
                        }
                        if (strcmp(temp.name.c_str(), "node_name") == 0) {
                            std::string node_name = arg.value();
                            if (strcmp(nodes[i].node_name.c_str(), node_name.c_str()) == 0) res += 1;
                        }
                    }

                    if (temp.place == 1) {
                        for (auto prop: nodes[i].props) {
                            if (strcmp(prop.first.c_str(), temp.name.c_str()) == 0) {
                                if (strcmp(prop.second.get_value().c_str(), arg.value().c_str()) == 0) res += 1;
                            }
                        }
                    }

                    if (temp.place == 2) {
                        for (auto rel: nodes[i].relations) {
                            if (strcmp(rel.first.c_str(), temp.name.c_str()) == 0) {
                                if (strcmp(rel.second.related_with.c_str(), arg.value().c_str()) == 0) res += 1;
                            }
                        }
                    }
                }
                if (!res) {
                    for (std::vector<node>::iterator it = temp.begin(); it != temp.end(); ++it) {
                        if (it->id == nodes[i].id) {
                            temp.erase(it);
                        }
                    }
                }
            }
        }
        if (strcmp(logic_op.logical_operation().c_str(), "and") == 0) {
            for (int i = 0; i < nodes.size(); i++) {
                bool res = 1;
                for (auto arg: logic_op.field()) {
                    struct parsed_field temp = parse_field(arg.type());
                    if (temp.place == 0) {
                        if (strcmp(temp.name.c_str(), "id") == 0) {
                            int id = stoi(arg.value());
                            if (nodes[i].id != id) res = 0;
                        }
                        if (strcmp(temp.name.c_str(), "node_name") == 0) {
                            std::string node_name = arg.value();
                            if (strcmp(nodes[i].node_name.c_str(), node_name.c_str()) != 0) res = 0;
                        }
                    }

                    if (temp.place == 1) {
                        for (auto prop: nodes[i].props) {
                            if (strcmp(prop.first.c_str(), temp.name.c_str()) == 0) {
                                if (strcmp(prop.second.get_value().c_str(), arg.value().c_str()) != 0) res = 0;
                            }
                        }
                    }

                    if (temp.place == 2) {
                        for (auto rel: nodes[i].relations) {
                            if (strcmp(rel.first.c_str(), temp.name.c_str()) == 0) {
                                if (strcmp(rel.second.related_with.c_str(), arg.value().c_str()) != 0) res = 0;
                            }
                        }
                    }
                }
                if (!res) {
                    for (std::vector<node>::iterator it = temp.begin(); it != temp.end(); ++it) {
                        if (it->id == nodes[i].id) {
                            temp.erase(it);
                        }
                    }
                }
            }
        }
        nodes = temp;
    }
}

std::vector <node> get_nodes_by_sel_set(struct database db, std::string node_class, selection_set_t selection_set) {
    std::vector <node> result;
    if (selection_set.argument().empty()) {
        for (auto id: db.information.node_classes.at(node_class)) {
            node cur = db.get_node_by_id(id);
            result.push_back(cur);
        }
    } else {
        for (auto con: selection_set.argument()) {
            if (!con.field().empty()) {
                for (auto id: db.information.node_classes.at(node_class)) {
                    node cur = db.get_node_by_id(id);
                    for (auto arg: con.field()) {
                        struct parsed_field temp = parse_field(arg.type());
                        if (temp.place == 0) {
                            if (strcmp(temp.name.c_str(), "id") == 0) {
                                int id = atoi(arg.value().c_str());
                                if (cur.id == id) result.push_back(cur);
                            }
                            if (strcmp(temp.name.c_str(), "node_name") == 0) {
                                std::string node_name = arg.value().substr(1, arg.value().size() - 2);
                                if (strcmp(cur.node_name.c_str(), node_name.c_str()) == 0) {
                                    {
                                        bool temp_b = false;
                                        for (node res_n: result) {
                                            if (res_n.id == cur.id) {
                                                temp_b = true;
                                            }
                                        }
                                        if (!temp_b) {
                                            result.push_back(cur);
                                        } else continue;
                                    }
                                }
                            }

                            if (temp.place == 1) {
                                for (auto prop: cur.props) {
                                    if (strcmp(prop.first.c_str(), temp.name.c_str()) == 0) {
                                        if (strcmp(prop.second.get_value().c_str(), arg.value().c_str()) == 0) {
                                            bool temp_b = false;
                                            for (node res_n: result) {
                                                if (res_n.id == cur.id) {
                                                    temp_b = true;
                                                }
                                            }
                                            if (!temp_b) {
                                                result.push_back(cur);
                                            } else continue;
                                        }
                                    }
                                }
                            }

                            if (temp.place == 2) {
                                for (auto rel: cur.relations) {
                                    if (strcmp(rel.first.c_str(), temp.name.c_str()) == 0) {
                                        if (strcmp(rel.second.related_with.c_str(), arg.value().c_str()) == 0) {
                                            bool temp_b = false;
                                            for (node res_n: result) {
                                                if (res_n.id == cur.id) {
                                                    temp_b = true;
                                                }
                                            }
                                            if (!temp_b) {
                                                result.push_back(cur);
                                            } else continue;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!con.logic_op().empty()) {
                for (auto logic_op: con.logic_op()) {
                    parse_logic_op(result, logic_op);
                }
            }
        }
    }
    return result;
}

property convert_value_from_srt(std::string input) {
    int resi = atoi(input.c_str());
    float resf = atof(input.c_str());
    if (resi != 0 && resf != 0) {
        if (resi != resf) {
            return property(resf);
        } else {
            return property(resi);
        }
    }
    std::string sym1 = input.substr(0, 1);
    std::string sym2 = "\"";
    if (strcmp(sym1.c_str(), sym2.c_str()) == 0) {
        return property(input.c_str());
    } else {
        if (strcmp(input.c_str(), "true") == 0) {
            return property(true);
        } else return property(false);
    }
}

std::vector <node> get_nodes_by_insert(struct database db, std::string node_class, selection_set_t selection_set) {
    if (selection_set.object().empty()) {
        throw new IncorrectRequestException("Body of request is empty");
    } else {
        std::vector <node> result;
        for (auto obj: selection_set.object()) {
            node n = node(obj.obj_name(), node_class);
            if (!obj.field().empty()) {
                for (auto field: obj.field()) {
                    property prop = convert_value_from_srt(field.value());
                    n.add_prop(field.type(), prop);
                }
            }
            if (!obj.relation().empty()) {
                for (auto relation: obj.relation()) {
                    relationship rel = relationship(obj.obj_name(), relation.value());
                    n.add_relationship(relation.type(), rel);
                }
            }
            result.push_back(n);
        }
        return result;
    }
}


static body_t get_query_by_result_set(struct database db, std::vector <node> *nodes, request_t request) {
    body_t result;
    if (request.result_set() == NULL) {
        for (node cur: *nodes) {
            node_t n = node_t(cur.node_name, cur.node_class);
            for (auto prop: cur.props) {
                filling_t field = filling_t(prop.first.c_str());
                field.value().set(prop.second.get_value().c_str());
                n.field().push_back(field);
            }
            for (auto rel: cur.relations) {
                filling_t relation = filling_t(rel.first.c_str());
                relation.value().set(rel.second.related_with.c_str());
                n.relation().push_back(relation);
            }
            result.node().push_back(n);
        }
    } else {
        result_set_t result_set = request.result_set().get();
        for (node cur: *nodes) {
            node_t n = node_t(cur.node_name, cur.node_class);
            for (auto field: result_set.field()) {
                struct parsed_field temp = parse_field(field);
                if (temp.place == 0) {
                    if (strcmp(temp.name.c_str(), "id") == 0) {
                        filling_t field = filling_t("id");
                        field.value().set(std::to_string(cur.id));
                        n.field().push_back(field);
                    }
                }

                if (temp.place == 1) {
                    for (auto prop: cur.props) {
                        if (strcmp(prop.first.c_str(), temp.name.c_str()) == 0) {
                            filling_t field = filling_t(prop.first.c_str());
                            field.value().set(prop.second.get_value().c_str());
                            n.field().push_back(field);
                        }
                    }
                }

                if (temp.place == 2) {
                    for (auto rel: cur.relations) {
                        if (strcmp(rel.first.c_str(), temp.name.c_str()) == 0) {
                            std::string join_name = rel.second.related_with.substr(1, rel.second.related_with.size()-2);
                            node join = db.get_node_by_name(join_name);
                            node_t join_node = node_t(join.node_name, join.node_class);
                            for (auto prop : join.props){
                                filling_t join_prop = filling_t(prop.first);
                                join_prop.value().set(prop.second.get_value());
                                join_node.field().push_back(join_prop);
                            }
                            for (auto rel : join.relations){
                                filling_t join_rel = filling_t(rel.first);
                                join_rel.value().set(rel.second.related_with);
                                join_node.relation().push_back(join_rel);
                            }
                            filling_t relation = filling_t(rel.first.c_str());
                            relation.node().set(join_node);
                            n.relation().push_back(relation);
                        }
                    }
                }
            }
            result.node().push_back(n);
        }
    }
    return result;
}

static void update_nodes(struct database db, std::vector <node> *nodes, request_t request){
    if (!request.selection_set()->sub_operations().empty()){
        for (node n : *nodes) {
            node prev_n = n;
            for (auto sub_op: request.selection_set()->sub_operations()) {
                if (strcmp(sub_op.sub_op_type().c_str(), "SET")==0){
                    struct parsed_field temp = parse_field(sub_op.field().type());
                    if (temp.place == 0){
                        if (strcmp(temp.name.c_str(), "id")==0){
                            n.id = atoi(sub_op.field().value().c_str());
                        }
                        if (strcmp(temp.name.c_str(), "node_name") == 0){
                            n.node_name = temp.name;
                        }
                    }
                    if (temp.place == 1){
                        for (auto prop : n.props){
                            if (strcmp(prop.first.c_str(), temp.name.c_str()) == 0){
                                property new_prop = property(sub_op.field().value().c_str());
                                n.update_prop(prop.first, new_prop);
                            }
                        }
                    }
                    if (temp.place == 2){
                        for (auto rel : n.relations){
                            if (strcmp(rel.first.c_str(), temp.name.c_str()) == 0){
                                relationship relation = relationship(rel.second.name, sub_op.field().value());
                                n.update_relationship(rel.first, relation);
                            }
                        }
                    }
                }
                if (strcmp(sub_op.sub_op_type().c_str(), "SUB") == 0){
                    struct parsed_field temp = parse_field(sub_op.field().type());
                    if (temp.place == 0){
                        if (strcmp(temp.name.c_str(), "id")==0){
                            n.id = n.id - atoi(sub_op.field().value().c_str());
                        }
                    }
                    if (temp.place == 1){
                        for (auto prop : n.props){
                            if (strcmp(prop.first.c_str(), temp.name.c_str()) == 0){
                                property new_prop = property(prop.second.get_int() - stoi(sub_op.field().value()));
                                n.update_prop(prop.first, new_prop);
                            }
                        }
                    }
                }
                if (strcmp(sub_op.sub_op_type().c_str(), "ADD") == 0){
                    struct parsed_field temp = parse_field(sub_op.field().type());
                    if (temp.place == 0){
                        if (strcmp(temp.name.c_str(), "id")==0){
                            n.id = n.id + atoi(sub_op.field().value().c_str());
                        }
                    }
                    if (temp.place == 1){
                        for (auto prop : n.props){
                            if (strcmp(prop.first.c_str(), temp.name.c_str()) == 0){
                                property new_prop = property(prop.second.get_int() + stoi(sub_op.field().value()));
                                n.update_prop(prop.first, new_prop);
                            }
                        }
                    }
                }
            }
            db.update_node(prev_n.node_name, n);
        }
    }
}

response_t RequestInvoker::parse_and_execute_query(request_t request) {
    response_t resp = response_t(200, "", 1);
    if (strcmp(request.query_type().c_str(), "Select") == 0) {
        std::vector <node> nodes = get_nodes_by_sel_set(this->db, request.class_type(), request.selection_set().get());
        std::cout << nodes.size() << std::endl;
        body_t answer = get_query_by_result_set(this->db, &nodes, request);
        resp.body().set(answer);
        resp.message().append("Select done.");
    }
    if (strcmp(request.query_type().c_str(), "Insert") == 0) {
        std::vector <node> nodes = get_nodes_by_insert(this->db, request.class_type(), request.selection_set().get());
        std::vector <node> add_nodes;
        for (node n: nodes) {
            this->db.add_node(n);
            add_nodes.push_back(this->db.get_node_by_name(n.node_name));
        }
        body_t answer = get_query_by_result_set(this->db,&add_nodes, request);
        resp.body().set(answer);
        resp.message().append("Insert done.");
    }
    if (strcmp(request.query_type().c_str(), "Delete") == 0) {
        std::vector <node> nodes = get_nodes_by_sel_set(this->db, request.class_type(), request.selection_set().get());
        std::vector <node> add_nodes;
        for (node n: nodes) {
            add_nodes.push_back(this->db.get_node_by_name(n.node_name));
            this->db.delete_node(n.node_name);
        }
        body_t answer = get_query_by_result_set(this->db, &add_nodes, request);
        resp.body().set(answer);
        resp.message().append("Delete done.");
    }
    if (strcmp(request.query_type().c_str(), "Update") == 0){
        std::vector<node> nodes = get_nodes_by_sel_set(this->db, request.class_type(), request.selection_set().get());
        update_nodes(this->db, &nodes, request);
        body_t answer = get_query_by_result_set(this->db, &nodes, request);
        resp.body().set(answer);
        resp.message().append("Update done.");
    }
    return resp;
}

void RequestInvoker::close_db() {
    this->db.save();
}