#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    pid_t processId = fork();

    if (processId == -1) {
        perror("Error while creating child!");
    } else if (processId == 0) {
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(10);

        if (kill(getppid(), SIGKILL) == 0) {
            printf("Successfully killed parent!\n");
            sleep(10);
            printf("Child now exiting!\n");
        } else {
            perror("Error while killing parent!");
        }
    } else {
        while (1);
    }

    return 0;
}

