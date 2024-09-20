/*
============================================================================
Name : 34a-server.c
Author : Aashish Vaswani
Description : Write a program to create a concurrent server.
a. use fork
b. use pthread_create
Date: 20th Sep, 2024.
============================================================================
*/


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int sockfd, connfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);

    bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    listen(sockfd, 5);

    while (1) {
        clilen = sizeof(cliaddr);
        connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &clilen);
        if (fork() == 0) {
            char buff[1024];
            int bytes_read = read(connfd, buff, sizeof(buff) - 1);
            buff[bytes_read] = '\0';  // Add null terminator after reading
            printf("Client: %s\n", buff);
            write(connfd, "Hello from server", 17);
            close(connfd);
            exit(0);
        }
        close(connfd);
    }
    return 0;
}

/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/34$ ./34a-server 
Client: Hello from client

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/34$ ./34a-client 
Server: Hello from server

*/
