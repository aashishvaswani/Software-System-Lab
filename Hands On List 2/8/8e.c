/*
============================================================================
Name : 8e.c
Author : Aashish Vaswani
Description : Write a separate program using signal system call to catch the following signals.
e. SIGALRM (use setitimer system call)
Date: 19th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void functionHandler(int signum) {
    printf("Caught SIGALRM (Alarm Signal using setitimer())\n");
    _exit(0);
}

int main() {
    struct itimerval timer;

    signal(SIGALRM, functionHandler);

    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);
    while(1);

    return 0;
}


/*

Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/8$ ./8e
Caught SIGALRM (Alarm Signal using setitimer())

*/
