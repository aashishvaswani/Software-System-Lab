/*
============================================================================
Name : 20b.c
Author : Aashish Vaswani
Description : Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 20th Sep, 2024.
============================================================================
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char *fifoPath = "./20-fifo";
    char buffer[100];
    mkfifo(fifoPath, 0666);

    int fd = open(fifoPath, O_RDONLY);
    if (fd == -1) {
        perror("Unable to open FIFO for reading");
        return 1;
    }

    int bytesRead = read(fd, buffer, sizeof(buffer));
    printf("Received: %s\n", buffer);

    close(fd);
    return 0;
}


/*

Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/20$ ./20a

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/20$ ./20b
Received: Hello from program 20a!

*/
