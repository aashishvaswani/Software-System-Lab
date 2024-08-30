/*
  Write a program to perform Record locking.
  a. Implement write lock
  b. Implement read lock
  Create three records in a file. Whenever you access a particular record, first lock it then modify/access
  to avoid race condition.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define NUM_RECORDS 3

typedef struct {
    int id;
    char name[20];
} Record;

int main() {
    Record dataEntries[NUM_RECORDS] = {
        {1, "A"},
        {2, "B"},
        {3, "C"}
    };

    int fd = open("records.dat", O_CREAT | O_RDWR, 0744);
    if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    if (write(fd, dataEntries, sizeof(dataEntries)) == -1) {
        perror("Error writing records to file");
        close(fd);
        exit(EXIT_FAILURE);
    }

    printf("Initialized %d records in file.\n", NUM_RECORDS);
    close(fd);

    return 0;
}

