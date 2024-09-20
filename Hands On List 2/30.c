/*
============================================================================
Name : 30.c
Author : Aashish Vaswani
Description : Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
Date: 20th Sep, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    key_t key;
    int shmId;
    ssize_t shmSize = 20;
    char *shmPtr, *readOnlyShmPtr;

    key = ftok(".", 1);
    if (key == -1) {
        perror("Error generating key");
        _exit(1);
    }

    shmId = shmget(key, shmSize, IPC_CREAT | 0700);
    if (shmId == -1) {
        perror("Error creating shared memory");
        _exit(1);
    }

    shmPtr = shmat(shmId, NULL, 0);
    if (shmPtr == (char *)-1) {
        perror("Error attaching shared memory");
        _exit(1);
    }

    printf("Press enter to write data to shared memory...\n");
    getchar();
    sprintf(shmPtr, "Hello, World!");

    printf("Press enter to read data from shared memory...\n");
    getchar();
    printf("Data from shared memory: %s\n", shmPtr);

    readOnlyShmPtr = shmat(shmId, NULL, SHM_RDONLY);
    if (readOnlyShmPtr == (char *)-1) {
        perror("Error attaching shared memory in read-only mode");
        _exit(1);
    }

    printf("Press enter to read from read-only memory...\n");
    getchar();
    printf("Data from shared memory (read-only): %s\n", readOnlyShmPtr);

    printf("Detaching shared memory...\n");
    shmdt(shmPtr);
    shmdt(readOnlyShmPtr);

    printf("Press enter to remove shared memory...\n");
    getchar();
    shmctl(shmId, IPC_RMID, NULL);

    return 0;
}


/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./30
Press enter to write data to shared memory...

Press enter to read data from shared memory...

Data from shared memory: Hello, World!
Press enter to read from read-only memory...

Data from shared memory (read-only): Hello, World!
Detaching shared memory...
Press enter to remove shared memory...

*/
