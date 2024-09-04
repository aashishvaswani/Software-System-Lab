/*
============================================================================
Name : 13.c
Author : Aashish Vaswani
Description :Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/select.h>

int main() {
  struct timeval timeVal;
  timeVal.tv_sec = 10;
  timeVal.tv_usec = 0;
  
  fd_set readFileDescriptor;
  int returnValue;
  
  FD_ZERO(&readFileDescriptor);
  FD_SET(STDIN_FILENO, &readFileDescriptor);
  
  returnValue = select(1, &readFileDescriptor, NULL, NULL, &timeVal);
  
  if(returnValue == -1) {
    perror("error from select()\n");
    return 1;
  } else if(returnValue) {
    printf("Content is ready\n");
  }
  else {
    printf("Content not ready\n");
  }
  
  return 0;
}
