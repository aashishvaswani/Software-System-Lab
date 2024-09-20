/*
============================================================================
Name : 33b.c
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
    int sockfd, newsockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;
    char dataReceivedFromClient[100];
    ssize_t n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8080);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    listen(sockfd, 2);

    len = sizeof(cliaddr);
    newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len);
    if (newsockfd < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    write(newsockfd, "Hello from server!", 18);

    n = read(newsockfd, dataReceivedFromClient, sizeof(dataReceivedFromClient));
    if (n > 0) {
        printf("Message from client: %s\n", dataReceivedFromClient);
    }

    close(newsockfd);
    close(sockfd);
    return 0;
}

/*
Output:
Terminal 1:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/33$ ./33a
Message from server: Hello from server!

Terminal 2:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/33$ ./33b
Message from client: Hello from client!

*/
