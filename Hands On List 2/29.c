/*
============================================================================
Name : 29.c
Author : Aashish Vaswani
Description : Write a program to remove the message queue.
Date: 20th Sep, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>

int main() {
    key_t key;
    int msgId;

    key = ftok(".", 1);
    if (key == -1) {
        perror("Error generating key");
        _exit(1);
    }

    msgId = msgget(key, IPC_CREAT | 0700);
    if (msgId == -1) {
        perror("Error getting message queue");
        _exit(1);
    }

    printf("Key: %d\n", key);
    printf("Message Queue Identifier: %d\n\n", msgId);

    if (msgctl(msgId, IPC_RMID, NULL) == -1) {
        perror("Error removing message queue");
        _exit(1);
    }

    printf("Message queue removed successfully.\n");

    return 0;
}

/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./29
Key: 17039544
Message Queue Identifier: 0

Message queue removed successfully.

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x0104041a 1          aashish-va 700        0            0           

*/
