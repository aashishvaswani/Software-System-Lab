#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>

int main() {
    struct rlimit limit;

    if (getrlimit(RLIMIT_CORE, &limit) == -1) {
        perror("Error getting RLIMIT_CORE");
        return 1;
    }
    
    printf("Max size of a core file - \n");
    printf("Soft Limit: %ld bytes\n", limit.rlim_cur);
    if (limit.rlim_max == RLIM_INFINITY)	
        printf("Hard Limit: Infinite\n");
    else
        printf("Hard Limit: %ld bytes\n", limit.rlim_max);

    limit.rlim_cur = 4096;

    if (setrlimit(RLIMIT_CORE, &limit) == -1) {
        perror("Error setting RLIMIT_CORE");
        return 1;
    }

    if (getrlimit(RLIMIT_CORE, &limit) == -1) {
        perror("Error getting updated RLIMIT_CORE");
        return 1;
    }

    printf("\nMax size of a core file - \n");
    printf("Soft Limit: %ld bytes\n", limit.rlim_cur);
    if (limit.rlim_max == RLIM_INFINITY)
        printf("Hard Limit: Infinite\n");
    else
        printf("Hard Limit: %ld bytes\n", limit.rlim_max);
        
    return 0;
}

