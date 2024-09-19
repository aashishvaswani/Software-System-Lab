/*
============================================================================
Name : 28.c
Author : Aashish Vaswani
Description : Write a program to get maximum and minimum real time priority.
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main() {
    int minPriorityForRoundRobin;
    int minPriorityForFIFO;
    int maxPriorityForFIFO;
    int maxPriorityForRoundRobin;

    minPriorityForFIFO = sched_get_priority_min(SCHED_FIFO);
    if (minPriorityForFIFO == -1) {
        perror("Error getting SCHED_FIFO minimum priority");
        exit(EXIT_FAILURE);
    }

    minPriorityForRoundRobin = sched_get_priority_min(SCHED_RR);
    if (minPriorityForRoundRobin == -1) {
        perror("Error getting SCHED_RR minimum priority");
        exit(EXIT_FAILURE);
    }

    maxPriorityForFIFO = sched_get_priority_max(SCHED_FIFO);
    if (maxPriorityForFIFO == -1) {
        perror("Error getting SCHED_FIFO maximum priority");
        exit(EXIT_FAILURE);
    }

    maxPriorityForRoundRobin = sched_get_priority_max(SCHED_RR);
    if (maxPriorityForRoundRobin == -1) {
        perror("Error getting SCHED_RR maximum priority");
        exit(EXIT_FAILURE);
    }
  
    printf("  Maximum priority(Round-Robin): %d\n", maxPriorityForRoundRobin);
    printf("  Minimum priority(Round-Robin): %d\n", minPriorityForRoundRobin);

    printf("  Maximum priority(FIFO): %d\n", maxPriorityForFIFO);
    printf("  Minimum priority(FIFO): %d\n", minPriorityForFIFO);

    return 0;
}

