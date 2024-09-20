/*
============================================================================
Name : 8f.c
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


#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void functionHandler(int sig) {
    printf("Signal SIGVTALRM has been caught!\n");
    _exit(0);
}

int main() {
    struct itimerval timer;

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1) {
        perror("Error while setting the virtual timer!");
        return 1;
    }

    if (signal(SIGVTALRM, functionHandler) == SIG_ERR) {
        perror("Error while setting the signal handler!");
        return 1;
    }

    while (1);

    return 0;
}


/*

Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/8$ ./8f
Signal SIGVTALRM has been caught!

*/
