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

//                    char message[10000];
//                    string ping = "ping";
//                    int res_code = send(s0, ping.c_str(), strlen(ping.c_str()), 0);
//                    if (res_code < 0){
//                        throw new ConnectionException(strerror(errno));
//                        exit(1);
//                    }
//                    cout << "Message send" << endl;
//                    memset(&message, 0, sizeof(message));
//                    res_code = recv(s0, (char*) &message, sizeof(message), 0);
//                    cout << "Message from server " << message << endl;
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