/*
============================================================================
Name : 25.c
Author : Aashish Vaswani
Description : Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
Date: 20th Sep, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

int main() {
    key_t key;
    int msgId;
    struct msqid_ds info;

    key = ftok(".", 1);
    if (key == -1) {
        perror("Error generating key");
        _exit(1);
    }

    msgId = msgget(key, IPC_CREAT | 0700);
    if (msgId == -1) {
        perror("Error creating message queue");
        _exit(1);
    }

    if (msgctl(msgId, IPC_STAT, &info) == -1) {
        perror("Error getting message queue info");
        _exit(1);
    }

    printf("Access Permission: %o\n", info.msg_perm.mode);
    printf("UID: %d\n", info.msg_perm.uid);
    printf("GID: %d\n", info.msg_perm.gid);
    printf("Time of last message sent: %ld\n", info.msg_stime);
    printf("Time of last message received: %ld\n", info.msg_rtime);
    printf("Time of last change: %ld\n", info.msg_ctime);
    printf("Size of queue: %lu bytes\n", info.__msg_cbytes);
    printf("Number of messages in queue: %lu\n", info.msg_qnum);
    printf("Max number of bytes: %lu\n", info.msg_qbytes);
    printf("PID of last msgsnd: %d\n", info.msg_lspid);
    printf("PID of last msgrcv: %d\n", info.msg_lrpid);

    return 0;
}


/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./25
Access Permission: 700
UID: 1000
GID: 1000
Time of last message sent: 0
Time of last message received: 0
Time of last change: 1726832263
Size of queue: 0 bytes
Number of messages in queue: 0
Max number of bytes: 16384
PID of last msgsnd: 0
PID of last msgrcv: 0

*/
