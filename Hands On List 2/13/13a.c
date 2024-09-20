/*
============================================================================
Name : 13a.c
Author : Aashish Vaswani
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 19th Sep, 2024.
============================================================================
*/


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


/*

Output:

Terminal 1:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/13$ ./13a
Process ID: 13715
Unable to catch SIGSTOP: Invalid argument

[1]+  Stopped                 ./13a

Terminal 2:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/13$ ./13b
Enter the PID of the first program: 13715
Sent SIGSTOP signal to process with PID 13715

*/
