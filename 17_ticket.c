/*
============================================================================
Name : 17_ticket.c
Author : Aashish Vaswani
Description : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 31st Aug, 2024.
============================================================================
*/


#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
  int fileDescriptor;
  struct {
    int ticket_no;
  } db;
  
  db.ticket_no = 10;
  fileDescriptor = open("db", O_CREAT | O_RDWR, 0744);
  write(fileDescriptor, &db, sizeof(db));
  close(fileDescriptor);
  
  fileDescriptor = open("db", O_RDONLY);
  read(fileDescriptor, &db, sizeof(db));
  printf("Ticket no : %d\n" , db.ticket_no);
  close(fileDescriptor);
}
