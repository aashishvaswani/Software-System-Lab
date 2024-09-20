/*
============================================================================
Name : 1c.c
Author : Aashish Vaswani
Description : Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
Date: 19th Sep, 2024.
============================================================================
*/

#include <sys/time.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void timer_handler(int signum) {
    printf("Timer expired!\n");
    exit(0);
}

int main() {
    int flag = 1;
    int timerStatus;
    struct itimerval timer;

    signal(SIGPROF, timer_handler);

    if (flag == 1) {
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 10;
        timer.it_value.tv_usec = 0;
    } else if (flag == 2) {
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = 0;
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = 10000;
    }

    timerStatus = setitimer(ITIMER_PROF, &timer, NULL);
    if (timerStatus == -1) {
        perror("Error while setting the interval timer");
        return 1;
    }
    
    while (1);

    return 0;
}


/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/1$ ./1c
Timer expired!
*/
