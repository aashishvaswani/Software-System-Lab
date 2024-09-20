/*
============================================================================
Name : 33a.c
Author : Aashish Vaswani
Description : Write a program to communicate between two machines using socket.
Date: 20th Sep, 2024.
============================================================================
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char dataReceivedFromServer[100];
    ssize_t n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Connection to server failed");
        exit(EXIT_FAILURE);
    }

    n = read(sockfd, dataReceivedFromServer, sizeof(dataReceivedFromServer));
    if (n < 0) {
        perror("Reading from socket failed");
    } else {
        printf("Message from server: %s\n", dataReceivedFromServer);
    }

    write(sockfd, "Hello from client!", 18);

    close(sockfd);
    return 0;
}

/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/33$ ./33a
Message from server: Hello from server!

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/33$ ./33b
Message from client: Hello from client!

*/

