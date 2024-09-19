/*
============================================================================
Name : 14.c
Author : Aashish Vaswani
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>

void identifyFileType(const char *filePath) {
  struct stat fileStat;
  
  if(stat(filePath, &fileStat)) {
    printf("Error extracting the file type\n");
    exit(EXIT_FAILURE);
  }
  
 if(S_ISREG(fileStat.st_mode)) {
  printf("This is a regular file\n");
 } else if(S_ISDIR(fileStat.st_mode)) {
  printf("This is a directory\n");
 } else if(S_ISLNK(fileStat.st_mode)) {
  printf("This is a symbolic link\n");
 } else if(S_ISCHR(fileStat.st_mode)) {
  printf("This is a character device\n");
 } else if(S_ISBLK(fileStat.st_mode)) {
  printf("This is a block device\n");
 } else if(S_ISFIFO(fileStat.st_mode)){
  printf("The file is a FIFO\n");
 } else if(S_ISSOCK(fileStat.st_mode)) {
  printf("The file is a socket\n");
 }
 else{
  printf("The file type cannot be recognized");
 }
}

int main(int argc, char *argv[1]) {
  if(argc!=2) {
    printf("Usage : <file_path>\n");
    return 1;
  }
  
  identifyFileType(argv[1]);
  return 0;
}
