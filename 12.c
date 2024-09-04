/*
============================================================================
Name : 12.c
Author : Aashish Vaswani
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
  const char *fileName = "testfile.txt";
  int fileDescriptorValue = open(fileName, O_WRONLY);
  
  if(fileDescriptorValue<0) {
    perror("Error opening the file!");
    return 1;
  }
  
  int currentStatus = fcntl(fileDescriptorValue, F_GETFL);
  
  if(currentStatus < 0) {
    perror("Error fetching the status of the file!");
    close(fileDescriptorValue);
    return 1;
  }
  
  switch(currentStatus & O_ACCMODE) {
    case O_RDONLY : 
      printf("The file is accessed in Read-only mode!\n");
      break;
      
    case O_WRONLY : 
      printf("The file is accessed in Write-only mode!\n");
      break;
      
    case O_RDWR : 
      printf("The file is accessed in Read-Write mode!\n");
      break;
      
    default : 
      printf("The file is being accessed in an unknown mode!\n");
  }
  
  close(fileDescriptorValue);
  return 0;
}
