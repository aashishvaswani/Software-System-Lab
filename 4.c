/*
============================================================================
Name : 4.c
Author : Aashish Vaswani
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 28th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    // Try to open the file with read and write mode, without O_EXCL flag
    int fileDescriptorValue = open("testfile.txt", O_RDWR);
    
    if (fileDescriptorValue == -1) {
        perror("open without O_EXCL");
    } else {
        printf("File opened successfully without O_EXCL, file descriptor: %d\n", fileDescriptorValue);
        close(fileDescriptorValue);
    }

    // Try to open the file with O_EXCL flag
    fileDescriptorValue = open("testfile.txt", O_RDWR | O_CREAT | O_EXCL, 0644);
    
    if (fileDescriptorValue == -1) {
        perror("open with O_EXCL");
    } else {
        printf("File opened successfully with O_EXCL, file descriptor: %d\n", fileDescriptorValue);
        close(fileDescriptorValue);
    }

    return 0;
}
