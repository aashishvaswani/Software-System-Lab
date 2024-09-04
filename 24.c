/*
============================================================================
Name : 24.c
Author : Aashish Vaswani
Description : Write a program to create an orphan process.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t processId;

    processId = fork();

    if (processId < 0) {
        perror("Fork failed");
        exit(1);
    } else if (processId > 0) {
        printf("Parent process (with PID: %d) is exiting the execution.\n", getpid());
        exit(0);
    } else {
        sleep(5);  // Sleep for 5 seconds to ensure the parent process exits first
        printf("Child process (PID: %d) is now an orphan. Adopted by isnit process (PID: %d).\n", getpid(), getppid());
    }

    return 0;
}

