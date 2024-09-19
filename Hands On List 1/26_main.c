/*
============================================================================
Name : 26_main.c
Author : Aashish Vaswani
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *executable = "./26_print";
    char *arg1 = "Aashish";
    //char *args[] = {executable, NULL}; // Executing the program without passing any arguments 
    char *args[] = {executable, arg1, NULL};

    execv(executable, args);

    return EXIT_SUCCESS;
}

