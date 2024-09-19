#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_sigint(int signalId) {
    printf("\nCaught signal SIGINT (%d)\n", signalId);
    _exit(0);
}

int main() {
    struct sigaction sigintAction;
    sigintAction.sa_handler = handle_sigint;
    sigintAction.sa_flags = 0;

    if (sigaction(SIGINT, &sigintAction, NULL) == -1) {
        perror("Error setting SIGINT handler");
        return 1;
    }

    while (1) {
        sleep(1);
    }

    return 0;
}

