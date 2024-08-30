/*
  Write a program, call fork and print the parent and child process id.
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t processId;

    processId = fork();

    if (processId < 0) {
        // Fork failed
        perror("Fork failed");
        return 1;
    } else if (processId == 0) {
        // Child process
        printf("This is the Child process. PID: %d\n", getpid());
        printf("Parent of Child process. Parent PID: %d\n", getppid());
    } else {
        // Parent process
        printf("This is the Parent process. PID: %d\n", getpid());
        printf("Child process ID: %d\n", processId);
    }

    return 0;
}

