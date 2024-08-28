//3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    int fileDescriptorValue = creat("testfile.txt", 0644);

    if (fileDescriptorValue == -1) {
        perror("creat");
        return 1;
    }

    printf("File descriptor value: %d\n", fileDescriptorValue);
    close(fileDescriptorValue);

    return 0;
}
