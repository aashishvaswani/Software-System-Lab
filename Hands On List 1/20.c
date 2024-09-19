/*
============================================================================
Name : 20.c
Author : Aashish Vaswani
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main() {
    pid_t processId;
    int currentPriority;

    processId = getpid();
    
    currentPriority = getpriority(PRIO_PROCESS, processId);
    printf("Current Priority (Nice value) of PID %d: %d\n", processId, currentPriority);

    if (nice(5) == -1) {
        perror("Failed to set new priority");
        exit(EXIT_FAILURE);
    }

    currentPriority = getpriority(PRIO_PROCESS, processId);
    printf("New Priority (Nice value) of PID %d: %d\n", processId, currentPriority);

    return 0;
}

