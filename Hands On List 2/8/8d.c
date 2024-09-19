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

