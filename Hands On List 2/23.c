#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
    long maxOpenFiles;
    int pipeFD[2];
    long pipeSize;

    maxOpenFiles = sysconf(_SC_OPEN_MAX);
    if (maxOpenFiles == -1) {
        perror("Error getting maximum open files");
        return 1;
    }
    printf("Maximum number of open files per process: %ld\n", maxOpenFiles);

    if (pipe(pipeFD) == -1) {
        perror("Error creating pipe");
        return 1;
    }

    pipeSize = fpathconf(pipeFD[0], _PC_PIPE_BUF);
    if (pipeSize == -1) {
        perror("Error getting pipe size");
        return 1;
    }
    printf("Size of pipe (circular buffer): %ld bytes\n", pipeSize);

    close(pipeFD[0]);
    close(pipeFD[1]);

    return 0;
}

