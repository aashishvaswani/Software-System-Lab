/*
============================================================================
Name : 3.c
Author : Aashish Vaswani
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call.
Date: 28th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fileDescriptorValue = creat("testfile.txt", 0644);

    if (fileDescriptorValue == -1) {
        perror("creat");
        return 1;
    }

    printf("File descriptor value: %d\n", fileDescriptorValue);
    close(fileDescriptorValue);

    return 0;
}
