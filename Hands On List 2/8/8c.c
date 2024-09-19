#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sigfpe_handler(int signum) {
    printf("Signal SIGFPE has been caught!\n");
    _exit(0);
}

int main() {
    if (signal(SIGFPE, sigfpe_handler) == SIG_ERR) {
        perror("Error while assigning signal handler!");
        return 1;
    }

    raise(SIGFPE);
    return 0;
}

