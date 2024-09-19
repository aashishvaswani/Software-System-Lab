#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>

int main() {
    pid_t processId;
    int pipeEnds[2];
    char parentMessage[] = "Hello World!";
    char childMessage[50];

    if (pipe(pipeEnds) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    processId = fork();

    if (processId == -1) {
        perror("Fork failed");
        return 1;
    }

    if (processId == 0) {
        close(pipeEnds[1]);
        read(pipeEnds[0], childMessage, sizeof(childMessage));
        printf("Data from parent: %s\n", childMessage);
        close(pipeEnds[0]);
    } else {
        close(pipeEnds[0]);
        write(pipeEnds[1], parentMessage, strlen(parentMessage) + 1);
        close(pipeEnds[1]);
    }

    return 0;
}

