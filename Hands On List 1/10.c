/*
============================================================================
Name : 10.c
Author : Aashish Vaswani
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    const char *givenFileName = "testfile.txt";
    int fileDescriptor;
    ssize_t writtenBytes;
    off_t offset;

    // 2 sets of data(each of 10 bytes) to be written in the file
    const char *dataSet1 = "Helloworld"; // 10 bytes
    const char *dataSet2 = "BadMorning"; // 10 bytes

    fileDescriptor = open(givenFileName, O_RDWR | O_CREAT, 0666);
    if (fileDescriptor == -1) {
        perror("Failed to open file");
        return 1;
    }
    printf("File descriptor value: %d\n", fileDescriptor);

    // Appending the first 10 bytes(from dataSet1)
    writtenBytes = write(fileDescriptor, dataSet1, strlen(dataSet1));
    if (writtenBytes == -1) {
        perror("Failed to write to file");
        close(fileDescriptor);
        return 1;
    }

    // Move the file pointer by 10 bytes from the current position
    offset = lseek(fileDescriptor, 10, SEEK_CUR);
    if (offset == -1) {
        perror("Failed to lseek");
        close(fileDescriptor);
        return 1;
    } else {
        printf("lseek succeeded, new offset: %ld\n", (long)offset);
    }

    // Appending the first 10 bytes(from dataSet2)
    writtenBytes = write(fileDescriptor, dataSet2, strlen(dataSet2));
    if (writtenBytes == -1) {
        perror("Failed to write to file");
        close(fileDescriptor);
        return 1;
    }

    close(fileDescriptor);
    printf("File operations completed successfully.\n");
    return 0;
}
