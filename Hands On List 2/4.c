/*
============================================================================
Name : 4.c
Author : Aashish Vaswani
Description : Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.
Date: 19th Sep, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <x86intrin.h>

int main() {
    unsigned long long start, end;
    int i;

    start = __rdtsc();

    for (i = 0; i < 100; i++) {
        getppid();
    }

    end = __rdtsc();

    printf("Time taken for 100 getppid() calls: %llu clock cycles\n", end - start);
    
    return 0;
}


/*
Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./4
Time taken for 100 getppid() calls: 476494 clock cycles
*/
