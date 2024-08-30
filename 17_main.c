/*
  Write a program to simulate online ticket reservation. Implement write lock.
  Write a program to open a file, store a ticket number and exit. Write a separate program, to
  open the file, implement write lock, read the ticket number, increment the number and print
  the new ticket number then close the file.
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

struct {
    int ticket_no;
} db;

int main() {
  struct flock fileLock;
  
  fileLock.l_type = F_WRLCK;
  fileLock.l_whence = SEEK_SET;
  fileLock.l_start = 0;
  fileLock.l_len = 0;
  fileLock.l_pid = getpid(); 
  
  int fileDescriptor;
  fileDescriptor = open("db", O_RDWR);
  
  printf("Just before entering the critical section.....");
  fcntl(fileDescriptor, F_SETLKW, &fileLock);
  printf("Inside the critical section....");
  
  read(fileDescriptor, &db, sizeof(db));
  printf("Current ticket number : %d\n", db.ticket_no);
  
  db.ticket_no++;
  
  lseek(fileDescriptor, 0, SEEK_SET);
  write(fileDescriptor, &db, sizeof(db));
  
  printf("Press enter to unlock\n");
  getchar();
  
  fileLock.l_type = F_UNLCK;
  fcntl(fileDescriptor, F_SETLK, &fileLock);
  
  printf("Exited critical section\n");
  return 0;
}
