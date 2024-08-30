/*
  Write a program, open a file, call fork, and then write to the file by both the child as well as the
  parent processes. Check output of the file.
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int fileDescriptor;
    pid_t processId;

    fileDescriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fileDescriptor< 0) {
        perror("Failed to open file");
        exit(1);
    }

    processId = fork();

    if (processId < 0) {
        perror("Fork failed");
        close(fileDescriptor);
        exit(1);
    } else if (processId == 0) {
        const char *child_message = "This is the Child process writing.\n";
        write(fileDescriptor, child_message, strlen(child_message));
    } else {
        const char *parent_message = "This is the Parent process writing.\n";
        write(fileDescriptor, parent_message, strlen(parent_message));
    }
    close(fileDescriptor);

    return 0;
}

