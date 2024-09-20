/*
============================================================================
Name : 8c.c
Author : Aashish Vaswani
Description : Write a separate program using signal system call to catch the following signals.
c. SIGFPE
Date: 19th Sep, 2024.
============================================================================
*/


#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sigfpe_handler(int signum) {
    printf("Signal SIGFPE has been caught!\n");
    _exit(0);
}

int main() {
    if (signal(SIGFPE, sigfpe_handler) == SIG_ERR) {
        perror("Error while assigning signal handler!");
        return 1;
    }

    raise(SIGFPE);
    return 0;
}

/*

Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/8$ ./8c
Signal SIGFPE has been caught!

*/
