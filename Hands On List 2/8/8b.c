/*
============================================================================
Name : 8b.c
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
#include <stdio.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("\nSignal SIGINT has been caught!\n");
    _exit(0);
}

int main() {
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("Error while assigning signal handler!");
        return 1;
    }

    while(1);//Ctrl+C
    return 0;
}

/*

Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/8$ ./8b
^C
Signal SIGINT has been caught!

*/
