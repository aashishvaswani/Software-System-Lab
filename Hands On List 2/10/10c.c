#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_fpe(int signalId) {
    printf("Caught signal SIGFPE (%d)\n", signalId);
    _exit(0);
}

int main() {
    struct sigaction sigfpeAction;
    sigfpeAction.sa_handler = handle_fpe;
    sigfpeAction.sa_flags = 0;

    if (sigaction(SIGFPE, &sigfpeAction, NULL) == -1) {
        perror("Error setting SIGFPE handler");
        return 1;
    }

    raise(SIGFPE);

    return 0;
}

