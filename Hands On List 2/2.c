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
