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

