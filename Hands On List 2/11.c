/*
============================================================================
Name : 11.c
Author : Aashish Vaswani
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
Date: 19th Sep, 2024.
============================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_sigint(int signalId) {
    printf("\nResetting SIGINT to default action.\n");
    struct sigaction sigintAction;
    sigintAction.sa_handler = SIG_DFL;
    sigemptyset(&sigintAction.sa_mask);
    sigintAction.sa_flags = 0;
    sigaction(SIGINT, &sigintAction, NULL);
}

int main() {
    struct sigaction sigintAction;

    sigintAction.sa_handler = SIG_IGN;
    sigemptyset(&sigintAction.sa_mask);
    sigintAction.sa_flags = 0;
    sigaction(SIGINT, &sigintAction, NULL);

    printf("SIGINT signal is ignored. Press Ctrl+C.\n");
    sleep(5);

    sigintAction.sa_handler = handle_sigint;
    sigemptyset(&sigintAction.sa_mask);
    sigintAction.sa_flags = 0;
    sigaction(SIGINT, &sigintAction, NULL);

    printf("\nSIGINT signal will now be reset to default. Press Ctrl+C again.\n");

    while (1) {
        sleep(1);
    }

    return 0;
}


/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./11
SIGINT signal is ignored. Press Ctrl+C.
^C^C
SIGINT signal will now be reset to default. Press Ctrl+C again.
^C
Resetting SIGINT to default action.
^C

*/
