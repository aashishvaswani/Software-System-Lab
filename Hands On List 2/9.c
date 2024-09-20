/*
============================================================================
Name : 9.c
Author : Aashish Vaswani
Description : Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
Date: 19th Sep, 2024.
============================================================================
*/


#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_reset(int signalId) {
    printf("\nResetting SIGINT to default action.\n");
    signal(SIGINT, SIG_DFL);
}

int main() {
    signal(SIGINT, SIG_IGN);
    printf("SIGINT is ignored. Press Ctrl+C.\n");
    sleep(5);

    signal(SIGINT, handle_reset);
    printf("\nSIGINT is now reset. Press Ctrl+C again.\n");

    while (1) {
        sleep(1);
    }

    return 0;
}


/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./9
SIGINT is ignored. Press Ctrl+C.
^C^C
SIGINT is now reset. Press Ctrl+C again.
^C
Resetting SIGINT to default action.
^C

*/
