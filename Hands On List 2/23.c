/*
============================================================================
Name : 23.c
Author : Aashish Vaswani
Description : Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
Date: 20th Sep, 2024.
============================================================================
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    long maxOpenFiles;
    int pipeFD[2];
    long pipeSize;

    maxOpenFiles = sysconf(_SC_OPEN_MAX);
    if (maxOpenFiles == -1) {
        perror("Error getting maximum open files");
        return 1;
    }
    printf("Maximum number of open files per process: %ld\n", maxOpenFiles);

    if (pipe(pipeFD) == -1) {
        perror("Error creating pipe");
        return 1;
    }

    pipeSize = fpathconf(pipeFD[0], _PC_PIPE_BUF);
    if (pipeSize == -1) {
        perror("Error getting pipe size");
        return 1;
    }
    printf("Size of pipe (circular buffer): %ld bytes\n", pipeSize);

    close(pipeFD[0]);
    close(pipeFD[1]);

    return 0;
}


/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./23
Maximum number of open files per process: 1024
Size of pipe (circular buffer): 4096 bytes

*/
