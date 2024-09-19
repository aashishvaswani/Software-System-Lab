/*
============================================================================
Name : 1_b.c
Author : Aashish Vaswani
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 28th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    
    // Create a hard link
    if (link("testfile.txt","hrdlnk") == 0) {
	printf("Hard link-hrdlnk created successfully for testfile.\n");
    } else {
	perror("Failed to create symbolic link.");
    }

    return 0;
}

