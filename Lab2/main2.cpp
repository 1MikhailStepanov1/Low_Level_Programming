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
    string buf;
    string line;
    while(getline(cin, line)){
        buf.append(line);
        buf.append("\n");
        NodeWrapper nodeWrapper;
        int code = parseInput(buf, nodeWrapper);
        if (code){
            std::cout << "ret_code: " << code << std::endl;
        } else {
            nodeWrapper.node->print(0);
            delete nodeWrapper.node;
        }
        buf.clear();
        std::cout << "-----------------" << endl;
    }
    return 0;
}