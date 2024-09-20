/*
============================================================================
Name : 2.c
Author : Aashish Vaswani
Description : Write a program to print the system resource limits. Use getrlimit system call.
Date: 19th Sep, 2024.
============================================================================
*/


#include <stdio.h>
#include <sys/resource.h>
#include <unistd.h>

void print_limit(int resource, const char *resource_name) {
    struct rlimit limit;
    
    if (getrlimit(resource, &limit) == 0) {
        printf("%s limits: \n", resource_name);
        printf("  Soft limit: %lu\n", (unsigned long) limit.rlim_cur);
        printf("  Hard limit: %lu\n\n", (unsigned long) limit.rlim_max);
    } else {
        perror("Error getting resource limit");
    }
}	

int main() {
    print_limit(RLIMIT_CPU, "CPU time");
    print_limit(RLIMIT_FSIZE, "File size");
    print_limit(RLIMIT_DATA, "Data segment size");
    print_limit(RLIMIT_STACK, "Stack size");
    print_limit(RLIMIT_CORE, "Core file size");
    print_limit(RLIMIT_RSS, "Resident set size");
    print_limit(RLIMIT_NPROC, "Number of processes");
    print_limit(RLIMIT_NOFILE, "Number of open files");
    print_limit(RLIMIT_MEMLOCK, "Locked memory size");
    print_limit(RLIMIT_AS, "Address space size");
    print_limit(RLIMIT_LOCKS, "File locks");

    return 0;
}


/*
Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./2
CPU time limits: 
  Soft limit: 18446744073709551615
  Hard limit: 18446744073709551615

File size limits: 
  Soft limit: 18446744073709551615
  Hard limit: 18446744073709551615

Data segment size limits: 
  Soft limit: 18446744073709551615
  Hard limit: 18446744073709551615

Stack size limits: 
  Soft limit: 8388608
  Hard limit: 18446744073709551615

Core file size limits: 
  Soft limit: 0
  Hard limit: 18446744073709551615

Resident set size limits: 
  Soft limit: 18446744073709551615
  Hard limit: 18446744073709551615

Number of processes limits: 
  Soft limit: 63287
  Hard limit: 63287

Number of open files limits: 
  Soft limit: 1024
  Hard limit: 1048576

Locked memory size limits: 
  Soft limit: 2083397632
  Hard limit: 2083397632

Address space size limits: 
  Soft limit: 18446744073709551615
  Hard limit: 18446744073709551615

File locks limits: 
  Soft limit: 18446744073709551615
  Hard limit: 18446744073709551615

*/
