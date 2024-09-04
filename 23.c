/*
============================================================================
Name : 23.c
Author : Aashish Vaswani
Description : Write a program to create a Zombie state of the running program
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t processId;

    processId = fork();

    if (processId < 0) {
        perror("Fork failed");
        exit(1);
    } else if (processId > 0) {
        printf("Parent process (PID: %d). Child process (PID: %d) will become a zombie.\n", getpid(), processId);
        sleep(10);  // Sleep for 10 seconds while the child becomes a zombie
        printf("Parent process (PID: %d) exiting.\n", getpid());
    } else {
        printf("Child process (PID: %d) exiting.\n", getpid());
        exit(0);
    }

    return 0;
}

