#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>

struct msgbuf {
    long mtype;
    int someNumber;
};

int main() {
    key_t key;
    int msgId;
    ssize_t messageSize;
    struct msgbuf data;

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

    data.mtype = 1;

    messageSize = msgrcv(msgId, &data, sizeof(data.someNumber), data.mtype, IPC_NOWAIT);
    if (messageSize == -1) {
        perror("Error receiving message with IPC_NOWAIT");
        _exit(1);
    }

    printf("Received number: %d\n", data.someNumber);

    return 0;
}


/*
Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/27$ ./27b
Received number: 100
*/
