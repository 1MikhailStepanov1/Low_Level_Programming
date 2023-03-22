#include <iostream>
#include <stdlib.h>
#include <sstream>
#include "../exceptions/exceptions.h"
#include "./include/Connection.h"
#include "./include/RequestInvoker.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2){
        cerr << "Usage: " << argv[0] << " <port>" << endl;
        exit(1);
    }

    try {
        Connection* connection = new Connection(argv[1]);
        connection->accept_client();
        struct database db = database("../file.data");
        RequestInvoker* invoker = new RequestInvoker(db);
        while(1){
            request_t req = connection->receive_request();
            response_t resp = invoker->parse_and_execute_query(req);
            connection->send_response(resp);
        }

    } catch (ConnectionException& exception){
        cout << exception.reason() << endl;
    } catch (InvalidSchemaException& exception){
        cout << exception.reason() << endl;
    }
    return 0;
}