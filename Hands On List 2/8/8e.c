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

