/*
============================================================================
Name : 7.c
Author : Aashish Vaswani
Description : Write a simple program to print the created thread ids.
Date: 19th Sep, 2024.
============================================================================
*/

#include <pthread.h>
#include <stdio.h>

void* sampleFunction()
{
    printf("Running in thread with thread ID: %lu\n", pthread_self());
}

void main()
{
    pthread_t threadID;

    if(pthread_create(&threadID, NULL, sampleFunction, NULL))
        perror("Error while creating thread");

    pthread_exit(NULL);
}

/*
Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./7
Running in thread with thread ID: 140108317587136
*/
