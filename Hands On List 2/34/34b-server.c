/*
============================================================================
Name : 34b-server.c
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
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *handle_connection(void *connfd_ptr) {
    int connfd = *(int*)connfd_ptr;
    free(connfd_ptr);
    char buff[1024];
    read(connfd, buff, sizeof(buff));
    printf("Client: %s\n", buff);
    write(connfd, "Hello from server", 17);
    close(connfd);
    return NULL;
}

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
        pthread_t thread;
        int *connfd_ptr = malloc(sizeof(int));
        *connfd_ptr = connfd;
        pthread_create(&thread, NULL, handle_connection, connfd_ptr);
    }
    return 0;
}


/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/34$ gcc -o 34b-server 34b-server.c -lpthread
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/34$ ./34b-server 
Client: Hello from client

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/34$ ./34b-client 
Server: Hello from server

*/
