#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int pipeEnds[2];
    char writeData[] = "Hello, Pipe!";
    char readData[20];

    pipe(pipeEnds);

    write(pipeEnds[1], writeData, strlen(writeData) + 1);
    read(pipeEnds[0], readData, sizeof(readData));

    printf("Read from pipe: %s\n", readData);

    close(pipeEnds[0]);
    close(pipeEnds[1]);

    return 0;
}

