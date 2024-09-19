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
