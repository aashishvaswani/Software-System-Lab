/*
============================================================================
Name : 31a.c
Author : Aashish Vaswani
Description : Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
Date: 20th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <unistd.h>

int main() {
    key_t key;
    int semId;
    struct sembuf operation;

    key = ftok(".", 1);
    if (key == -1) {
        perror("Error generating key");
        _exit(1);
    }

    semId = semget(key, 1, IPC_CREAT | 0700);
    if (semId == -1) {
        perror("Error creating semaphore");
        _exit(1);
    }

    if (semctl(semId, 0, SETVAL, 1) == -1) {
        perror("Error initializing semaphore");
        _exit(1);
    }

    printf("Binary semaphore created and initialized to 1.\n");

    return 0;
}


/*

Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/31$ ./31a
Binary semaphore created and initialized to 1.

*/
