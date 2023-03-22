#pragma once

#ifndef LOW_LEVEL_PROGRAMMING_CONNECTION_SERVER_H
#define LOW_LEVEL_PROGRAMMING_CONNECTION_SERVER_H

#include "../../common/request_schema.hxx"
#include "../../common/response_schema.hxx"
#include "../../exceptions/exceptions.h"
#include <iostream>
#include <netinet/ip.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024*50

class Connection{
    private:
        xml_schema::namespace_infomap map;
        xml_schema::properties properties;
        int sock0;
        int sock1;
        struct sockaddr_in local;
        char buf[BUFFER_SIZE];
    public:
        Connection(const char* port);
        void accept_client();
        void close_connection();
        request_t receive_request();
        void send_response(response_t resp);
};

#endif