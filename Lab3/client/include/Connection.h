#pragma once

#ifndef LOW_LEVEL_PROGRAMMING_CONNECTION_CLIENT_H
#define LOW_LEVEL_PROGRAMMING_CONNECTION_CLIENT_H

#include "../../common/request_schema.hxx"
#include "../../common/response_schema.hxx"
#include "../../exceptions/exceptions.h"
#include <netinet/ip.h>
#include <netinet/in.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <iostream>

#define BUFFER_SIZE 1024*50

class Connection {
    private:
        xml_schema::namespace_infomap map;
        xml_schema::properties properties;
    public:
        int sock;
        struct sockaddr_in local;
        char buf[BUFFER_SIZE];

        Connection();
        void open_connection(const char* ip, const char* port);
        void close_connection();
        void send_request(request_t req);
        response_t receive_response();
};

#endif
