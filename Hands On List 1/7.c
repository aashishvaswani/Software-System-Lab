/*
============================================================================
Name : 7.c
Author : Aashish Vaswani
Description :Write a program to copy file1 into file2 ($cp file1 file2)
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int src_fd = open("dummy1.txt", O_RDONLY);
    if (src_fd < 0) {
        perror("Error opening source file");
        exit(1);
    }

    int dest_fd = open("dummy2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd < 0) {
        perror("Error opening/creating destination file");
        close(src_fd);
        exit(1);
    }

    char currentArray[1024];
    ssize_t contentsRead, contentsWritten;

    while ((contentsRead = read(src_fd, currentArray, sizeof(currentArray))) > 0) {
        contentsWritten = write(dest_fd, currentArray, contentsRead);
        if (contentsWritten != contentsRead) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            exit(1);
        }
    }

    if (contentsRead < 0) {
        perror("Error reading source file");
    }

    close(src_fd);
    close(dest_fd);

    return 0;
}

