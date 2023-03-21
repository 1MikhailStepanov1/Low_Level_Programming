#include <iostream>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include "../../Lab2/include/ast.h"
#include "../../Lab2/lexer.h"
#include "../../Lab2/parser.h"
#include "../exceptions/exceptions.h"
#include "../common/request_schema.hxx"
#include "./include/XMLFormatter.h"

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
    int s0 = socket(AF_INET, SOCK_STREAM, 0);

    try {
        char* server_ip = argv[1];
        int port = atoi(argv[2]);
        if (s0 < 0){
            throw new ConnectionException(strerror(errno));
            exit(1);
        }

        struct sockaddr_in server;
        bzero(&server, sizeof (server));

        struct hostent* host = gethostbyname(server_ip);
        if (host == NULL){
            throw new ConnectionException(strerror(errno));
            exit(1);
        }

        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        // Print a resolved address of server (the first IP of the host)
        cout << "server address = " << (host->h_addr_list[0][0] & 0xff) << "." <<
                  (host->h_addr_list[0][1] & 0xff) << "." <<
                  (host->h_addr_list[0][2] & 0xff) << "." <<
                  (host->h_addr_list[0][3] & 0xff) << ", port " <<
                  static_cast<int>(port) << endl;

        memmove(&(server.sin_addr.s_addr), host->h_addr_list[0], 4);

        int res = connect(s0, (struct sockaddr*) &server, sizeof (server));
        if (res < 0){
            throw new ConnectionException(strerror(errno));
            exit(1);
        }
        cout << "Connected" << endl;

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
                        xml_schema::namespace_infomap map;
                        map[""].name = "";
                        map[""].schema = "form.xsd";
                        std::ostringstream oss;
                        request(oss, req, map);
                        cout << oss.str() << endl;
                        delete nodeWrapper.node;
                    }
                    buf.clear();
                    cout << "-----------------" << endl;

                    int res_code = 0;
                    char message[1000];
                    string ping = "ping";
                    res_code = send(s0, ping.c_str(), strlen(ping.c_str()), 0);
                    if (res_code < 0){
                        throw new ConnectionException(strerror(errno));
                        exit(1);
                    }
                    memset(&message, 0, sizeof(message));
                    res_code = recv(s0, (char*) &message, sizeof(message), 0);
                    cout << "Message from server " << message << endl;
                }
            }
        }
    } catch (IOException &exception) {
        cout << exception.reason() << endl;
    } catch (ConnectionException& exception){
        cout << exception.reason() << endl;
        close(s0);
    }
    return 0;
}