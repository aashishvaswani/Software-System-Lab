#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void handle_signal(int sig) {
    printf("Caught signal: %d\n", sig);
}

int main() {
    pid_t pid = getpid();
    printf("Process ID: %d\n", pid);

    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    if (sigaction(SIGSTOP, &sa, NULL) == -1) {
        perror("Unable to catch SIGSTOP");
    }

    while (1);

    return 0;
}

