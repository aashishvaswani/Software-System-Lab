/*
============================================================================
Name : 17b.c
Author : Aashish Vaswani
Description : Write a program to execute ls -l | wc.
b. use dup2
Date: 19th Sep, 2024.
============================================================================
*/

#include <unistd.h>
#include <stdio.h>

int main() {
    int pipeEnds[2];
    pipe(pipeEnds);

    if (fork() == 0) {
        // Child process: execute wc
        close(pipeEnds[1]); 
        dup2(pipeEnds[0], STDIN_FILENO); 
        close(pipeEnds[0]);
        execlp("wc", "wc", NULL);
    } else {
        // Parent process: execute ls -l
        close(pipeEnds[0]); 
        dup2(pipeEnds[1], STDOUT_FILENO); 
        close(pipeEnds[1]);
        execlp("ls", "ls", "-l", NULL);
    }

    return 0;
}


/*

Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/17$ ./17b
      7      56     423

*/
