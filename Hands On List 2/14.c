/*
============================================================================
Name : 14.c
Author : Aashish Vaswani
Description : Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipeEnds[2];
    char writeData[] = "Hello, Pipe!";
    char readData[20];

    pipe(pipeEnds);

    write(pipeEnds[1], writeData, strlen(writeData) + 1);
    read(pipeEnds[0], readData, sizeof(readData));

    printf("Read from pipe: %s\n", readData);

    close(pipeEnds[0]);
    close(pipeEnds[1]);

    return 0;
}


/*

Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./14
Read from pipe: Hello, Pipe!

*/
