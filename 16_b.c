/*
  Write a program to perform mandatory locking.
  a. Implement write lock
  b. Implement read lock
*/

#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void lockFile(int fileDescriptor, off_t offset, off_t length) {
  struct flock fileLock;
  
  fileLock.l_type = F_RDLCK;
  fileLock.l_whence = SEEK_SET;
  fileLock.l_start = offset;
  fileLock.l_len = length;
  fileLock.l_pid = getpid();
  
  if(fcntl(fileDescriptor, F_SETLKW, &fileLock) == -1) {
    perror("Unable to lock file....");
    exit(1);
  }
}

void unlockFile(int fileDescriptor, off_t offset, off_t length) {
  struct flock fileUnlock;
  
  fileUnlock.l_type = F_UNLCK;
  fileUnlock.l_start = offset;
  fileUnlock.l_whence = SEEK_SET;
  fileUnlock.l_len = length;
  fileUnlock.l_pid = getpid();
  
  if(fcntl(fileDescriptor, F_SETLK, &fileUnlock)) {
    perror("Unable to release the lock on file....");
    exit(1);
  }
}

int main() {
  const char *currFileName = "testfile.txt";
  int fileDescriptor = open(currFileName, O_RDWR);
  
  if(fileDescriptor == -1) {
    perror("Not able to access the file");
    close(fileDescriptor);
    return 1;
  }
  
  printf("Acquiring read lock....");
  lockFile(fileDescriptor, 0, 0);
  
  printf("Successfully acquired read lock. Press the enter key to unlock....");
  getchar();
  
  //Unlock the file
  printf("Read lock released....");
  unlockFile(fileDescriptor, 0, 0);
  
  return 0;
}
