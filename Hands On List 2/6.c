/*
============================================================================
Name : 6.c
Author : Aashish Vaswani
Description : Write a simple program to create three threads.
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *sampleFunction(void *data)
{
    printf("Running in thread: %lu\n", pthread_self());
}

int main() {
    pthread_t threadArray[3];
    int threadCounter[3];

    for (int i = 0; i < 3; i++) {
        threadCounter[i] = i + 1;
        if (pthread_create(&threadArray[i], NULL, sampleFunction, &threadCounter[i]) != 0) {
            perror("Error creating thread");
            return 1;
        }
    }

    pthread_exit(NULL);
}

/*
Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./6
Running in thread: 140161511847616
Running in thread: 140161503454912
Running in thread: 140161495062208
*/
