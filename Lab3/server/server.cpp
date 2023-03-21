#include <iostream>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "../exceptions/exceptions.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc != 2){
        cerr << "Usage: " << argv[0] << " <port>" << endl;
        exit(1);
    }

    int port = atoi(argv[1]);
    int s0 = socket(AF_INET, SOCK_STREAM, 0);

    try {
        if (s0 < 0){
            throw new ConnectionException(strerror(errno));
            exit(1);
        }

        struct sockaddr_in myaddr;
        memset(&myaddr, 0, sizeof(struct sockaddr_in));
        myaddr.sin_family = AF_INET;
        myaddr.sin_port = htons(port);
        myaddr.sin_addr.s_addr = htonl(INADDR_ANY);

        int res = bind(s0, (struct sockaddr*) &myaddr, sizeof(myaddr));
        if (res < 0){
            throw new ConnectionException(strerror(errno));
            exit(1);
        }

        struct linger linger_opt = {1, 0};
        setsockopt(s0, SOL_SOCKET, SO_LINGER, &linger_opt, sizeof(linger_opt));

        res = listen(s0, 1);
        if (res < 0){
            throw new ConnectionException(strerror(errno));
            exit(1);
        }
        struct sockaddr_in peeraddr;
        socklen_t peeraddr_len;
        int s1 = accept(s0, (struct sockaddr*) &peeraddr, &peeraddr_len);
        if (s1 < 0){
            throw new ConnectionException(strerror(errno));
            exit(1);
        }
        std::cout << "Connection from IP "
                  << ( ( ntohl(peeraddr.sin_addr.s_addr) >> 24) & 0xff ) << "."  // High byte of address
                  << ( ( ntohl(peeraddr.sin_addr.s_addr) >> 16) & 0xff ) << "."
                  << ( ( ntohl(peeraddr.sin_addr.s_addr) >> 8) & 0xff )  << "."
                  <<   ( ntohl(peeraddr.sin_addr.s_addr) & 0xff ) << ", port "   // Low byte of addr
                  << ntohs(peeraddr.sin_port) << endl;
        char message[1000];
        while(1){
            memset(&message, 0, sizeof(message));
            recv(s1, (char*) &message, sizeof(message), 0);
            cout << "Client " << message << endl;
            memset(&message, 0, sizeof(message));
            string pong = "pong";
            send(s1, pong.c_str(), strlen(pong.c_str()), 0);
        }

    } catch (ConnectionException& exception){
        cout << exception.reason() << endl;
        close(s0);
    }
    close(s0);
    return 0;
}