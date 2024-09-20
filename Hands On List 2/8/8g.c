/*
============================================================================
Name : 8g.c
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

void handle_prof(int sig) {
    printf("Signal SIGPROF has been caught!\n");
    _exit(0);
}

int main() {
    struct itimerval timer;

    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    if (setitimer(ITIMER_PROF, &timer, NULL) == -1) {
        perror("Error while setting the profiling timer!");
        return 1;
    }

    if (signal(SIGPROF, handle_prof) == SIG_ERR) {
        perror("Error while setting the signal handler!");
        return 1;
    }

    while (1);

    return 0;
}


/*

Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/8$ ./8g
Signal SIGPROF has been caught!

*/
