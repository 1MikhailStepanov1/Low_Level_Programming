#include "../include/RequestInvoker.h"
#include <vector>

RequestInvoker::RequestInvoker(std::string file) {
    db = database(file);
    db.create();
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

void parse_logic_op(vector <node> *nodes, logical_condition_t logic_op) {
    if (logic_op.condition().present()) {
        parse_logic_op(nodes, logic_op.condition()->logical_operation());
    } else {
        if (strcmp(logic_op.logical_operation().c_str(), "OR") == 0) {
            for (node n: nodes) {
                bool res = 0;
                for (auto arg: logic_op.field()) {
                    struct parsed_field temp = parse_field(arg.type());
                    if (temp.place == 0) {
                        if (strcmp(temp.name.c_str(), "id") == 0) {
                            int id = atoi(arg.value());
                            if (n.id == id) res += 1
                        }
                        if (strcmp(temp.name.c_str(), "node_name") == 0) {
                            std::string node_name = arg.value();
                            if (strcmp(n.node_name.c_str(), node_name.c_str()) == 0) res += 1;
                        }
                    }

                    if (temp.place == 1) {
                        for (auto prop: n.props) {
                            if (strcmp(prop.first, temp.name) == 0) {
                                if (strcmp(prop.second.get_value().c_str(), arg.value().c_str()) == 0) res += 1;
                            }
                        }
                    }

                    if (temp.place == 2) {
                        for (auto rel: n.relations) {
                            if (strcmp(rel.first, temp.name) == 0) {
                                if (strcmp(rel.second.related_with.c_str(), arg.value().c_str()) == 0) res += 1;
                            }
                        }
                    }
                }
                if (!res) {
                    nodes->erase(nodes->at(n));
                }
            }
        }
        if (strcmp(logic_op.logical_operation().c_str(), "and") == 0) {
            for (node n: nodes) {
                bool res = 1;
                for (auto arg: logic_op.field()) {
                    struct parsed_field temp = parse_field(arg.type());
                    if (temp.place == 0) {
                        if (strcmp(temp.name.c_str(), "id") == 0) {
                            int id = atoi(arg.value());
                            if (n.id != id) res = 0;
                        }
                        if (strcmp(temp.name.c_str(), "node_name") == 0) {
                            std::string node_name = arg.value();
                            if (strcmp(n.node_name.c_str(), node_name.c_str()) != 0) res = 0;
                        }
                    }

                    if (temp.place == 1) {
                        for (auto prop: n.props) {
                            if (strcmp(prop.first, temp.name) == 0) {
                                if (strcmp(prop.second.get_value().c_str(), arg.value().c_str()) != 0) res = 0;
                            }
                        }
                    }

                    if (temp.place == 2) {
                        for (auto rel: n.relations) {
                            if (strcmp(rel.first, temp.name) == 0) {
                                if (strcmp(rel.second.related_with.c_str(), arg.value().c_str()) != 0) res = 0;
                            }
                        }
                    }
                }
                if (!res) {
                    nodes->erase(nodes->at(n));
                }
            }
        }
    }
}

vector <node> get_query_by_sel_set(struct database db, std::string node_class, selection_set_t selection_set) {
    vector <node> result;
    if (selection_set.null_content()) {
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
                        auto temp = cur.props.find(arg.type());
                        if (temp != cur.props.end()) {
                            if (strcmp(temp->second.get_value(), arg.value()) == 0) {
                                result.push_back(n);
                            }
                        }
                    }
                }
            }
            if (!con.logic_op().empty()) {
                for (auto logic_op: con.logic_op()) {
                    parse_logic_op(&result, logic_op);
                }
            }
        }
    }
    return result;
}


static body_t get_query_by_result_set(vector <node> *nodes, result_set_t result_set) {
    body_t result;
    if (result_set.null_content()) {
        for (node cur: nodes) {
            node_t n = node_t(cur.node_name, cur.node_class);
            for (auto prop: cur.props) {
                filling_t field = filling_t(prop.first.c_str(), prop.second.get_value().c_str());
                n.field().push_back(field);
            }
            for (auto rel: cur.relations) {
                filling_t relation = filling_t(rel.first.c_str(), rel.second.related_with.c_str());
                n.field().push_back(relation);
            }
        }
    } else {
        for (auto field: result_set.field()) {
            struct parsed_field temp = parse_field(field);
            for (node cur: nodes) {
                node_t n = node_t(cur.node_name, cur.node_class);
                if (temp.place == 0) {
                    if (strcmp(temp.name.c_str(), "id") == 0) {
                        filling_t field = filling_t("id", std::to_string(cur.id));
                    }
                }

                if (temp.place == 1) {
                    for (auto prop: cur.props) {
                        if (strcmp(prop.first.c_str(), temp.name.c_str()) == 0) {
                            filling_t field = filling_t(prop.first.c_str(), prop.second.get_value().c_str());
                            n.field().push_back(field);
                        }
                    }
                }

                if (temp.place == 2) {
                    for (auto rel: cur.relations) {
                        if (strcmp(rel.first.c_str(), temp.name.c_str()) == 0) {
                            filling_t relation = filling_t(rel.first.c_str(), rel.second.related_with.c_str());
                            n.field().push_back(relation);
                        }
                    }
                }
            }
        }
    }
    return result;
}
}

response_t RequestInvoker::parse_and_execute_query(request_t request) {
    if (strcmp(request.query_type(), "Select") == 0) {
        vector <node> nodes = get_query_by_sel_set(this->db, request.class_type(), request.selection_set());
        body_t answer = get_query_by_result_set(&nodes, request.result_set());
        response_t resp = response_t(200, "Select done.", 1);
        resp.body().set(answer);
        return resp;
    }
}

void RequestInvoker::close_db() {
    this->db.save()
}