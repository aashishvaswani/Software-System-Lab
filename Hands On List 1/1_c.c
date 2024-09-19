/*
============================================================================
Name : 1_c.c
Author : Aashish Vaswani
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)
Date: 28th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main() {
	int count=mknod("myfifo", 0755, 0);
	if(count==0){
		printf("Fifo successfully created!\n");
	}else{
		printf("Fifo creation unsuccessful\n");
	}
	return 0;
}
