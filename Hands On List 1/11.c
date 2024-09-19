/*
============================================================================
Name : 11.c
Author : Aashish Vaswani
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *filename = "testfile.txt";
    int fileDescriptor, duplicatefileDescriptor, duplicate2fileDescriptor, fileControlfileDescriptor;
    ssize_t totalBytes;

    fileDescriptor = open(filename, O_RDWR | O_CREAT | O_APPEND, 0666);
    if (fileDescriptor == -1) {
        perror("Failed to open file");
        return 1;
    }

    duplicatefileDescriptor = dup(fileDescriptor);
    if (duplicatefileDescriptor == -1) {
        perror("Failed to duplicate file descriptor with dup");
        close(fileDescriptor);
        return 1;
    }

    totalBytes = write(fileDescriptor, "Original fileDescriptor\n", strlen("Original fileDescriptor\n"));
    if (totalBytes == -1) {
        perror("Failed to write to file with original fileDescriptor");
        close(fileDescriptor);
        close(duplicatefileDescriptor);
        return 1;
    }

    totalBytes = write(duplicatefileDescriptor, "Dup fileDescriptor\n", strlen("Dup fileDescriptor\n"));
    if (totalBytes == -1) {
        perror("Failed to write to file with dup fileDescriptor");
        close(fileDescriptor);
        close(duplicatefileDescriptor);
        return 1;
    }

    duplicate2fileDescriptor = dup2(fileDescriptor, 100); // Duplicating into file descriptor 100
    if (duplicate2fileDescriptor == -1) {
        perror("Failed to duplicate file descriptor with dup2");
        close(fileDescriptor);
        close(duplicatefileDescriptor);
        return 1;
    }

    totalBytes = write(duplicate2fileDescriptor, "Dup2 fileDescriptor\n", strlen("Dup2 fileDescriptor\n"));
    if (totalBytes == -1) {
        perror("Failed to write to file with dup2 fileDescriptor");
        close(fileDescriptor);
        close(duplicatefileDescriptor);
        close(duplicate2fileDescriptor);
        return 1;
    }

    fileControlfileDescriptor = fcntl(fileDescriptor, F_DUPFD, 0);
    if (fileControlfileDescriptor == -1) {
        perror("Failed to duplicate file descriptor with fcntl");
        close(fileDescriptor);
        close(duplicatefileDescriptor);
        close(duplicate2fileDescriptor);
        return 1;
    }

    totalBytes = write(fileControlfileDescriptor, "Fcntl fileDescriptor\n", strlen("Fcntl fileDescriptor\n"));
    if (totalBytes == -1) {
        perror("Failed to write to file with fcntl fileDescriptor");
        close(fileDescriptor);
        close(duplicatefileDescriptor);
        close(duplicate2fileDescriptor);
        close(fileControlfileDescriptor);
        return 1;
    }

    close(fileDescriptor);
    close(duplicatefileDescriptor);
    close(duplicate2fileDescriptor);
    close(fileControlfileDescriptor);

    printf("File operations completed successfully.\n");
    return 0;
}

