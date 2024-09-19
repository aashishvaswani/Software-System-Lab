/*
============================================================================
Name : 6.c
Author : Aashish Vaswani
Description : rite a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 28th Aug, 2024.
============================================================================
*/

#include <unistd.h>

int main() {
    char currentArray[1024];
    ssize_t contentsRead;

    // Read from STDIN (file descriptor 0)
    while ((contentsRead = read(0, currentArray, sizeof(currentArray))) > 0) {
        //Write to STDOUT (file descriptor 1)
        write(1, currentArray, contentsRead);
    }

    return 0;
}

