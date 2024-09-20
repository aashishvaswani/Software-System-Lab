/*
============================================================================
Name : 34a-client.c
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

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(8080);

    connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    write(sockfd, "Hello from client", 17);
    char buff[1024];
    read(sockfd, buff, sizeof(buff));
    printf("Server: %s\n", buff);
    close(sockfd);

    return 0;
}


/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/34$ ./34a-server 
Client: Hello from client

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/34$ ./34a-client 
Server: Hello from server

*/
