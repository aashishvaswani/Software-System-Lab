/*
============================================================================
Name : 28.c
Author : Aashish Vaswani
Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
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

    printf("Key: %d\n", key);
    printf("Message Queue Identifier: %d\n\n", msgId);

    if (msgctl(msgId, IPC_STAT, &info) == -1) {
        perror("Error getting message queue info");
        _exit(1);
    }

    printf("Press enter to change the permissions!\n");
    getchar();

    info.msg_perm.mode = 0777;

    if (msgctl(msgId, IPC_SET, &info) == -1) {
        perror("Error changing message queue permissions");
        _exit(1);
    }

    printf("Permissions changed to 0777.\n");

    return 0;
}


/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./28
Key: 17039544
Message Queue Identifier: 0

Press enter to change the permissions!

Permissions changed to 0777.

*/
