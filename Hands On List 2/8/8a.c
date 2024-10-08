/*
============================================================================
Name : 8a.c
Author : Aashish Vaswani
Description : Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
Date: 19th Sep, 2024.
============================================================================
*/


#include <signal.h> 
#include <stdio.h>
#include <unistd.h>

void callback()
{
    printf("Signal SIGSEGV has been caught!\n");
    _exit(0);
}

void main()
{
    __sighandler_t signalStatus;

    signalStatus = signal(SIGSEGV, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while assigning signal handler!");
    else
        raise(SIGSEGV);
}

/*

Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/8$ ./8a
Signal SIGSEGV has been caught!

*/
