/*
============================================================================
Name : 13b.c
Author : Aashish Vaswani
Description : Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
Date: 19th Sep, 2024.
============================================================================
*/

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
