#include <iostream>
#include "../../Lab2/include/ast.h"
#include "../../Lab2/lexer.h"
#include "../../Lab2/parser.h"
#include "../exceptions/exceptions.h"
#include "../common/request_schema.hxx"
#include "./include/XMLFormatter.h"
#include "./include/Connection.h"

using namespace std;

int parseInput(string &query, NodeWrapper &nodeWrapper) {
    yy_scan_string(query.c_str());
    int code = yyparse(nodeWrapper);
    yylex_destroy();
    return code;
}

static void print_node(node_t n){
    string tab1 = "  ";
    string tab2 = "    ";
    cout << tab1 << "Node (Name: " << n.node_name() << " Class: " << n.node_class() << ")" << endl;
    if (!n.field().empty()) {
        for (auto field: n.field()) {
            if (field.value().present()) {
                cout << tab2 << "Field (Name: " << field.type() << " Value: " << field.value() << ")" << endl;
            } else if (field.node().present()) {
                cout << tab2 << "Field:" << endl;
                print_node(field.node().get());
            }
        }
    }
    if (!n.relation().empty()) {
        for (auto rel: n.relation()){
            if (rel.value().present()){
                cout << tab2 << "Relation (Name: " << rel.type() << " Value: " << rel.value() << ")" << endl;
            } else if (rel.node().present()){
                cout << tab1 << "Relation:" << endl;
                print_node(rel.node().get());
            }
        }
    }
}

void print_response(response_t resp){
    cout << "-----------------------------------" << endl;
    cout << "------------RESPONSE---------------" << endl;
    cout << "Status: " << resp.status() << endl;
    cout << "Message: " << resp.message() << endl;
    cout << "Is finished: " << resp.isFinished() << endl;
    if (resp.body().present()) {
        cout << "Body: " << endl;
        for (auto node : resp.body().get().node()){
            print_node(node);
        }
    }
    cout << "-----------------------------------" << endl;
}

int main(int argc, char *argv[]) {

    if (argc != 3){
        cerr << "Usage: " << argv[0] << " <host> <port>" << endl;
    }

    try {
        char* server_ip = argv[1];

        Connection connection;
        connection.open_connection(server_ip, argv[2]);


        while (1) {
            string buf;
            string line;
            while (getline(cin, line)) {
                buf.append(line);
                if (line.find(';') != string::npos) {
                    NodeWrapper nodeWrapper;
                    int code = parseInput(buf, nodeWrapper);
                    if (code) {
                        cout << "ret_code: " << code << endl;
                    } else {
                        nodeWrapper.node->print(0);
                        cout << "-----------------" << endl;
                        request_t req = convert_to_XML_format(nodeWrapper);
                        connection.send_request(req);
                        delete nodeWrapper.node;
                    }
                    buf.clear();
                    cout << "-----------------" << endl;
                    response_t resp = connection.receive_response();
                    print_response(resp);
                }
            }
        }
    } catch (IOException &exception) {
        cout << exception.reason() << endl;
    } catch (ConnectionException& exception){
        cout << exception.reason() << endl;
        exit(1);
    }
    return 0;
}