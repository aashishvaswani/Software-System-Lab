/*
============================================================================
Name : 26_print.c
Author : Aashish Vaswani
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Hello World!\n");
        return 1;
    }

    printf("Hello, %s!\n", argv[1]);
    return 0;
}

