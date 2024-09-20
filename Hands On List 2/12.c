/*
============================================================================
Name : 12.c
Author : Aashish Vaswani
Description : Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
Date: 19th Sep, 2024.
============================================================================
*/

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


/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./12
Child PID: 13559
Parent PID: 13558
Successfully killed parent!
Killed
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ Child now exiting!

*/
