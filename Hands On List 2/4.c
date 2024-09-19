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

