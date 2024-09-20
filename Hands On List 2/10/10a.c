/*
============================================================================
Name : 10a.c
Author : Aashish Vaswani
Description : Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
Date: 19th Sep, 2024.
============================================================================
*/

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_sigsegv(int signalId) {
    printf("Caught signal SIGSEGV (%d)\n", signalId);
    _exit(0);
}

int main() {
    struct sigaction sigsegvAction;
    sigsegvAction.sa_handler = handle_sigsegv;
    sigsegvAction.sa_flags = 0;

    if (sigaction(SIGSEGV, &sigsegvAction, NULL) == -1) {
        perror("Error setting SIGSEGV handler");
        return 1;
    }

    raise(SIGSEGV);

    return 0;
}


/*

Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/10$ ./10a
Caught signal SIGSEGV (11)

*/
