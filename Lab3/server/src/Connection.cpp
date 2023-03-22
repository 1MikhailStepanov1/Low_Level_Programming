#include "../include/Connection.h"

Connection::Connection(const char *port) {
    int p = atoi(port);

    map[""].name = "";
    map[""].schema = "resp_schema.xsd";
    properties.no_namespace_schema_location("./Lab3/request_schema.xsd");

    sock0 = socket(AF_INET, SOCK_STREAM, 0);
    if (sock0 < 0){
        std::cout << "PISYA constructor1" << std::endl;
        throw new ConnectionException("PISYA constructor1");
    }

    memset(&local, 0, sizeof(struct sockaddr_in));
    this->local.sin_family = AF_INET;
    this->local.sin_port = htons(p);
    this->local.sin_addr.s_addr = htonl(INADDR_ANY);

    int res = bind(sock0, (struct sockaddr*) &local, sizeof(local));
    if (res < 0){
        std::cout << "PISYA constructor2" << std::endl;
        throw new ConnectionException("PISYA constructor2");
    }

    struct linger linger_opt = {1, 0};
    setsockopt(sock0, SOL_SOCKET, SO_LINGER, &linger_opt, sizeof(linger_opt));

    res = listen(sock0, 1);
    if (res < 0){
        std::cout << "PISYA constructor3" << std::endl;
        throw new ConnectionException("PISYA constructor3");
    }
}

void Connection::accept_client() {
    std::cout << "Socket base " << this->sock0 << std::endl;
    this->sock1 = accept(this->sock0, NULL, NULL);
    if (this->sock1 < 0){
        throw new ConnectionException("PISYA accept client");
    }
    std::cout << "Connection from IP "
         << ( ( ntohl(this->local.sin_addr.s_addr) >> 24) & 0xff ) << "."  // High byte of address
         << ( ( ntohl(this->local.sin_addr.s_addr) >> 16) & 0xff ) << "."
         << ( ( ntohl(this->local.sin_addr.s_addr) >> 8) & 0xff )  << "."
         <<   ( ntohl(this->local.sin_addr.s_addr) & 0xff ) << ", port "   // Low byte of addr
         << ntohs(this->local.sin_port) << std::endl;
}

void Connection::close_connection() {
    close(this->sock0);
    close(this->sock1);
}

request_t Connection::receive_request() {
    memset(&buf, 0, BUFFER_SIZE);
    int bytes_read = read(sock1, buf, BUFFER_SIZE);

    if (bytes_read < 0){
        std::cout << "PISYA receive request" << std::endl;
        throw new ConnectionException("Error with receiving data");
    }
    std::cout << "Received " << bytes_read << " bytes from client " << sock1 << " BUFFER " << std::endl;
    std::cout << buf << std::endl;
    buf[bytes_read] = 0;
    std::istringstream iss(buf);
    return *request(iss, 0, this->properties);
}

void Connection::send_response(response_t resp) {
    std::ostringstream oss;
    response(oss, resp, map);
    std::cout << oss.str() << std::endl;
}