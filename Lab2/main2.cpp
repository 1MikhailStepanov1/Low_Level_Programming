#include <iostream>
#include <string>
#include "../Lab2/include/ast.h"
#include "parser.h"
#include "lexer.h"
using namespace std;

int parseInput(string& query, NodeWrapper& nodeWrapper){
    yy_scan_string(query.c_str());
    int code = yyparse(nodeWrapper);
    yylex_destroy();
    return code;
}

int main(int argc, char** argv){
//    yydebug = 1;
    string buf;
    string line;
    while(getline(cin, line)){
        buf.append(line);
        cout << buf << endl;
        if (line.find(';') != string::npos) {
            NodeWrapper nodeWrapper;
            int code = parseInput(buf, nodeWrapper);
            if (code) {
                cout << "ret_code: " << code << endl;
            } else {
                nodeWrapper.node->print(0);
                delete nodeWrapper.node;
            }
            buf.clear();
            std::cout << "-----------------" << endl;
        }
    }
    return 0;
}