/*
============================================================================
Name : 8.c
Author : Aashish Vaswani
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    FILE *currentFile = fopen("dummy1.txt", "r");  // Opening the file in read-only mode
    if (currentFile == NULL) {
        perror("Error opening file");
        exit(1);
    }

    char *currLine = NULL;
    size_t length = 0;
    ssize_t contentRead;

    // Read and print each line from the file
    while ((contentRead = getline(&currLine, &length, currentFile)) != -1) {
        printf("%s", currLine);
    }

    free(currLine);
    fclose(currentFile);

    return 0;
}

