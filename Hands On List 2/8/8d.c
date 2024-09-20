/*
============================================================================
Name : 8d.c
Author : Aashish Vaswani
Description : Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
Date: 19th Sep, 2024.
============================================================================
*/


#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handle_alarm(int sig) {
    printf("Signal SIGALRM has been caught!\n");
    _exit(0);
}

int main() {
    alarm(3);

    if (signal(SIGALRM, handle_alarm) == SIG_ERR) {
        perror("Error setting signal handler!");
        return 1;
    }

    while (1);

    return 0;
}

/*

Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/8$ ./8d
Signal SIGALRM has been caught!

*/
