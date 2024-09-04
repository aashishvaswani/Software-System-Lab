/*
============================================================================
Name : 18_main.c
Author : Aashish Vaswani
Description : Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition
Date: 31st Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    int id;
    char name[20];
} Record;

void lock_record(int fd, int record_num, int lock_type) {
    struct flock fileLock;

    fileLock.l_type = lock_type;
    fileLock.l_whence = SEEK_SET;
    fileLock.l_start = (record_num - 1) * sizeof(Record);
    fileLock.l_len = sizeof(Record);
    fcntl(fd, F_SETLKW, &fileLock);
}

void unlock_record(int fd, int record_num) {
    struct flock fileLock;

    fileLock.l_type = F_UNLCK;
    fileLock.l_whence = SEEK_SET;
    fileLock.l_start = (record_num - 1) * sizeof(Record);
    fileLock.l_len = sizeof(Record);
    fcntl(fd, F_SETLK, &fileLock);
}

void read_record(int fd, int record_num, Record *record) {
    lock_record(fd, record_num, F_RDLCK);

    lseek(fd, (record_num - 1) * sizeof(Record), SEEK_SET);
    read(fd, record, sizeof(Record));
    unlock_record(fd, record_num);
}

void write_record(int fd, int record_num, Record *record) {
    lock_record(fd, record_num, F_WRLCK);

    lseek(fd, (record_num - 1) * sizeof(Record), SEEK_SET);
    if (write(fd, record, sizeof(Record)) == -1) {
        perror("Error writing record");
        exit(EXIT_FAILURE);
    }

    unlock_record(fd, record_num);
}

int main() {
    int fd = open("records.dat", O_RDWR);

    Record record;
    printf("Reading record 2....\n");
    read_record(fd, 2, &record);
    printf("Record %d: %s\n", record.id, record.name);

    printf("Modifying record 3....\n");
    read_record(fd, 3, &record);
    strcpy(record.name, "D");
    write_record(fd, 3, &record);
    printf("Record %d modified.\n", record.id);

    printf("Reading modified record 3....\n");
    read_record(fd, 3, &record);
    printf("Record %d: %s\n", record.id, record.name);

    close(fd);

    return 0;
}

