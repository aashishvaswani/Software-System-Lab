#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handle_sigsegv(int signalId) {
    printf("Caught signal SIGSEGV (%d)\n", signalId);
    _exit(0);
}

int main() {
    struct sigaction sigsegvAction;
    sigsegvAction.sa_handler = handle_sigsegv;
    sigsegvAction.sa_flags = 0;

    if (sigaction(SIGSEGV, &sigsegvAction, NULL) == -1) {
        perror("Error setting SIGSEGV handler");
        return 1;
    }

    raise(SIGSEGV);

    return 0;
}

