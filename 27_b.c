/*
============================================================================
Name : 27_b.c
Author : Aashish Vaswani
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date: 31st Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    printf("Executing ls -Rl using execlp\n");
    execlp("ls", "ls", "-Rl", NULL);
    perror("Error");
    return 0;
}

