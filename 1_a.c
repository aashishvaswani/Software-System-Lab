/*
============================================================================
Name : 1_a.c
Author : Aashish Vaswani
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 28th Aug, 2024.
============================================================================
*/

#include <unistd.h>  // For symlink
#include <stdio.h>

int main() {
   
    // Attempt to create a symbolic link
    if (symlink("testfile.txt", "sftlnk") == 0) {
        printf("Symbolic link sftlnk created pointing to testfile.\n");
    } else {
        perror("Failed to create symbolic link");
    }

    return 0;
}
