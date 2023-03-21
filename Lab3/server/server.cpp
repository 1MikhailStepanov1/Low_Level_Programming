#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "../exceptions/exceptions.h"
#include "./include/Connection.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2){
        cerr << "Usage: " << argv[0] << " <port>" << endl;
        exit(1);
    }

    try {
        Connection* connection = new Connection(argv[1]);
        connection->accept_client();
//        char message[1000];
        while(1){
            request_t req = connection->receive_request();
//            memset(&message, 0, sizeof(message));
//            recv(s1, (char*) &message, sizeof(message), 0);
//            cout << "Client " << message << endl;
//            memset(&message, 0, sizeof(message));
//            string pong = "pong";
//            send(s1, pong.c_str(), strlen(pong.c_str()), 0);
        }

    } catch (ConnectionException& exception){
        cout << exception.reason() << endl;
    } catch (InvalidSchemaException& exception){
        cout << exception.reason() << endl;
    }
    return 0;
}