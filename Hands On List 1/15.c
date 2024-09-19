/*
============================================================================
Name : 15.c
Author : Aashish Vaswani
Description : . Write a program to display the environmental variable of the user (use environ)
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>

extern char **environ;

int main() {
    int i = 0;
    char *currentEnvironmentVariable;

    // Loop through the environment variables and print each one
    while ((currentEnvironmentVariable = environ[i]) != NULL) {
        printf("%s\n", currentEnvironmentVariable);
        i++;
    }

    return 0;
}

