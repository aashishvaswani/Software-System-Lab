#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;
    printf("Enter the PID of the first program: ");
    scanf("%d", &pid);

    if (kill(pid, SIGSTOP) == 0) {
        printf("Sent SIGSTOP signal to process with PID %d\n", pid);
    } else {
        perror("Error sending SIGSTOP signal");
    }

    return 0;
}

