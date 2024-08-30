/*
  Write a program to find out time taken to execute getpid system call. Use time stamp counter.
*/

#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

int main() {
    uint64_t beginningTimeStamp, endTimeStamp;

    beginningTimeStamp = __builtin_ia32_rdtsc();

    getpid();

    endTimeStamp = __builtin_ia32_rdtsc();

    uint64_t cycles = endTimeStamp - beginningTimeStamp;

    printf("Cycles taken to execute getpid system call: %llu\n", (unsigned long long)cycles);

    return 0;
}

