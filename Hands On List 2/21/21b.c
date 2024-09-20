/*
============================================================================
Name : 21b.c
Author : Aashish Vaswani
Description : Write two programs so that both can communicate by FIFO -Use two way communications.
Date: 20th Sep, 2024.
============================================================================
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

char *pipeA = "./pipeA";
char *pipeB = "./pipeB";

void setup_pipes() {
    if (mkfifo(pipeA, 0666) == -1 && errno != EEXIST) {
        perror("Error creating pipeA");
    }
    if (mkfifo(pipeB, 0666) == -1 && errno != EEXIST) {
        perror("Error creating pipeB");
    }
}

int main() {
    int writeFd, readFd;
    char buffer[100];
    
    setup_pipes();
    
    readFd = open(pipeA, O_RDONLY);
    writeFd = open(pipeB, O_WRONLY);

    if (writeFd == -1 || readFd == -1) {
        perror("Error opening pipes");
        return 1;
    }

    read(readFd, buffer, sizeof(buffer));
    printf("Received: %s\n", buffer);

    write(writeFd, "Message from B to A", 19);
    close(readFd);
    close(writeFd);

    return 0;
}


/*

Output:
Terminal 1:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/21$ ./21a
Received: Message from B to A

Terminal 2:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/21$ ./21b
Received: Message from A to B


*/
