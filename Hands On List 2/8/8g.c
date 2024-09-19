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

