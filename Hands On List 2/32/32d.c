/*
============================================================================
Name : 32c.c
Author : Aashish Vaswani
Description : Write a program to implement semaphore to protect any critical section.
d. remove the created semaphore
Date: 20th Sep, 2024.
============================================================================
*/


#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    key_t semKey = ftok(".", 400);
    int semId = semget(semKey, 1, IPC_CREAT | 0700);

    printf("Press enter to delete the semaphore...\n");
    getchar();

    semctl(semId, 0, IPC_RMID);
    printf("Semaphore deleted.\n");

    return 0;
}


/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/32$ ./32c
Press enter to delete the semaphore...

Semaphore deleted.

*/
