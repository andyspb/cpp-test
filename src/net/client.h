/*
 * client.h
 *
 *  Created on: Jan 2, 2017
 *      Author: andy
 */

#ifndef SRC_NET_CLIENT_H_
#define SRC_NET_CLIENT_H_


//
// A simple Internet client application.
// It connects to a remote server,
// receives a "Hello" message from a server,
// sends the line "Thanks! Bye-bye..." to a server,
// and terminates.
//
// Usage:
//          client [IP_address_of_server [port_of_server]]
//      where IP_address_of_server is either IP number of server
//      or a symbolic Internet name, default is "localhost";
//      port_of_server is a port number, default is 1234.
//

#ifdef __linux__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

namespace client {

const int PORT = 8888;
const char* HOST = "localhost";

static void usage();

TEST_RESULT test() {
    // Create a socket
    int socket_ = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_ < 0) {
        perror("CLIENT: Cannot create a socket"); exit(1);
    }

    // Fill in the address of server
    struct sockaddr_in peeraddr;
    int peeraddr_len;
    memset(&peeraddr, 0, sizeof(peeraddr));
    const char* peerHost = HOST;

    // Resolve the server address (convert from symbolic name to IP number)
    struct hostent *host = gethostbyname(peerHost);
    if (host == NULL) {
        perror("CLIENT: Cannot define host address"); exit(1);
    }
    peeraddr.sin_family = AF_INET;
    short peerPort = PORT;
    peeraddr.sin_port = htons(peerPort);

    // Print a resolved address of server (the first IP of the host)
    printf(
        "CLIENT: peer addr = %d.%d.%d.%d, port %d\n",
        host->h_addr_list[0][0] & 0xff,
        host->h_addr_list[0][1] & 0xff,
        host->h_addr_list[0][2] & 0xff,
        host->h_addr_list[0][3] & 0xff,
        (int) peerPort
    );

    // Write resolved IP address of a server to the address structure
    memmove(&(peeraddr.sin_addr.s_addr), host->h_addr_list[0], 4);

    // Connect to a remote server
    int res = connect(socket_, (struct sockaddr*) &peeraddr, sizeof(peeraddr));
    if (res < 0) {
        perror("CLIENT: Cannot connect"); exit(1);
    }
    printf("CLIENT: Connected. Reading a server message.\n");

    char buffer[1024];
    res = read(socket_, buffer, 1024);
    if (res < 0) {
        perror("CLIENT: Read error");
        exit(1);
    }
    printf("CLIENT: Received:\n%s", buffer);

    write(socket_, "Thanks! Bye-bye...\r\n", 20);

    close(socket_);
    return 0;
}

static void usage() {
    LOG(INFO)
        << "CLIENT: simple Internet client application.\n"
        << "Usage:\n"
        << "         client [IP_address_of_server [port_of_server]]\n"
        << "     where IP_address_of_server is either IP number of server\n"
        << "     or a symbolic Internet name, default is \"localhost\";\n"
        << "     port_of_server is a port number, default is 8888.\n"
        << "The client connects to a server which address is given in a\n"
        << "command line, receives a message from a server, sends the message\n"
        << "\"Thanks! Bye-bye...\", and terminates.\n";
}

}  // namespace client

#endif

#endif /* SRC_NET_CLIENT_H_ */
