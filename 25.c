/*
============================================================================
Name : 25.c
Author : Aashish Vaswani
Description : Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int status;
    pid_t child1, child2, child3;

    child1 = fork();
    if (child1 == 0) {
        printf("First child process: PID = %d\n", getpid());
        sleep(2);
        exit(10);
    } else if (child1 < 0) {
        perror("Error creating first child");
        exit(1);
    }

    child2 = fork();
    if (child2 == 0) {
        printf("Second child process: PID = %d\n", getpid());
        sleep(4);
        exit(20);
    } else if (child2 < 0) {
        perror("Error creating second child");
        exit(1);
    }

    child3 = fork();
    if (child3 == 0) {
        printf("Third child process: PID = %d\n", getpid());
        sleep(6);
        exit(30);
    } else if (child3 < 0) {
        perror("Error creating third child");
        exit(1);
    }

    printf("Parent process: Waiting for the second child (PID = %d)...\n", child2);
    pid_t waited_pid = waitpid(child2, &status, 0);

    if (waited_pid == -1) {
        perror("Error during waitpid");
    } else if (WIFEXITED(status)) {
        printf("Parent process: Second child (PID = %d) terminated with status %d\n", waited_pid, WEXITSTATUS(status));
    } else {
        printf("Parent process: Second child (PID = %d) did not terminate normally\n", waited_pid);
    }

    int status1, status3;
    waitpid(child1, &status1, 0);
    waitpid(child3, &status3, 0);

    if (WIFEXITED(status1)) {
        printf("Parent process: First child (PID = %d) finished with status %d\n", child1, WEXITSTATUS(status1));
    } else {
        printf("Parent process: First child (PID = %d) did not terminate normally\n", child1);
    }

    if (WIFEXITED(status3)) {
        printf("Parent process: Third child (PID = %d) finished with status %d\n", child3, WEXITSTATUS(status3));
    } else {
        printf("Parent process: Third child (PID = %d) did not terminate normally\n", child3);
    }

    printf("Parent process: All child processes have finished.\n");
    return 0;
}

