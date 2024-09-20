/*
============================================================================
Name : 10b.c
Author : Aashish Vaswani
Description : Write a separate program using sigaction system call to catch the following signals.
b. SIGINT
Date: 19th Sep, 2024.
============================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_sigint(int signalId) {
    printf("\nCaught signal SIGINT (%d)\n", signalId);
    _exit(0);
}

int main() {
    struct sigaction sigintAction;
    sigintAction.sa_handler = handle_sigint;
    sigintAction.sa_flags = 0;

    if (sigaction(SIGINT, &sigintAction, NULL) == -1) {
        perror("Error setting SIGINT handler");
        return 1;
    }

    while (1) {
        sleep(1);
    }

    return 0;
}


/*

Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/10$ ./10b
^C
Caught signal SIGINT (2)


*/
