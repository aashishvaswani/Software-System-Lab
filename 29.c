/*
============================================================================
Name : 29.c
Author : Aashish Vaswani
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,SCHED_RR)
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <errno.h>

void printPolicy(int policy) {
    if (policy == SCHED_OTHER) {
        printf("Current scheduling policy: SCHED_OTHER\n");
    } else if (policy == SCHED_FIFO) {
        printf("Current scheduling policy: SCHED_FIFO\n");
    } else if (policy == SCHED_RR) {
        printf("Current scheduling policy: SCHED_RR\n");
    } else {
        printf("Unknown scheduling policy\n");
    }
}

int main() {
    struct sched_param schedParam;
    int currentPolicy;
    
    currentPolicy = sched_getscheduler(0);
    if (currentPolicy == -1) {
        perror("Error getting the current scheduling policy");
        exit(EXIT_FAILURE);
    }
    
    printPolicy(currentPolicy);

    schedParam.sched_priority = 10;

    if (sched_setscheduler(0, SCHED_FIFO, &schedParam) == -1) {
        perror("Error setting SCHED_FIFO policy");
        exit(EXIT_FAILURE);
    }

    currentPolicy = sched_getscheduler(0);
    if (currentPolicy == -1) {
        perror("Error getting scheduling policy");
        exit(EXIT_FAILURE);
    }
    
    printPolicy(currentPolicy);

    schedParam.sched_priority = 15;

    if (sched_setscheduler(0, SCHED_RR, &schedParam) == -1) {
        perror("Error setting SCHED_RR policy");
        exit(EXIT_FAILURE);
    }

    currentPolicy = sched_getscheduler(0);
    if (currentPolicy == -1) {
        perror("Error getting scheduling policy");
        exit(EXIT_FAILURE);
    }
    
    printPolicy(currentPolicy);

    return 0;
}

