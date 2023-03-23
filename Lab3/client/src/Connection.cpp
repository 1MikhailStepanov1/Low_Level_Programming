#include "../include/Connection.h"

Connection::Connection() {
    map[""].name = "";
    map[""].schema = "request_schema.xsd";
    properties.no_namespace_schema_location("./Lab3/response_schema.xsd");
    this->sock = -1;
}

void Connection::open_connection(const char *ip, const char *port) {
    close_connection();
    int p = atoi(port);

    this->sock = socket(AF_INET, SOCK_STREAM, 0);
    if (this->sock < 0){
        throw new ConnectionException(strerror(errno));
    }

    struct sockaddr_in server;
    bzero(&server, sizeof (server));

    struct hostent* host = gethostbyname(ip);
    if (host == NULL){
        throw new ConnectionException(strerror(errno));
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(p);
    std::cout << "server address = " << (host->h_addr_list[0][0] & 0xff) << "." <<
         (host->h_addr_list[0][1] & 0xff) << "." <<
         (host->h_addr_list[0][2] & 0xff) << "." <<
         (host->h_addr_list[0][3] & 0xff) << ", port " <<
         static_cast<int>(p) << std::endl;

    memmove(&(server.sin_addr.s_addr), host->h_addr_list[0], 4);

    int res = connect(this->sock, (struct sockaddr*) &server, sizeof (server));
    if (res < 0){
        throw new ConnectionException(strerror(errno));
    }
    std::cout << "Connected" << std::endl;
}

void Connection::close_connection() {
    if (this->sock > 0){
        close(this->sock);
    }
    this->sock = -1;
}

void Connection::send_request(request_t req) {
    std::ostringstream oss;
    request(oss, req, map);
    std::cout << oss.str() << std::endl;
    if (write(this->sock, oss.str().c_str(), oss.str().length()) < 0){
        throw new ConnectionException(strerror(errno));
    }
}

response_t Connection::receive_response() {
    memset(&buf, 0, BUFFER_SIZE);
    int bytes_read = recv(sock, buf, BUFFER_SIZE, 0);
    if (bytes_read < 0){
        std::cout << "PISYA receive request" << std::endl;
        throw new ConnectionException("Error with receiving data");
    }
    std::cout << "Received " << bytes_read << " bytes from client " << sock << std::endl;
    buf[bytes_read] = 0;
    std::istringstream iss(buf);
    try {
        return *response(iss, 0, this->properties);
    }catch (const xml_schema::exception& e) {
        std::ostringstream oss;
        oss << e;
        throw InvalidSchemaException(oss.str());
    }
}