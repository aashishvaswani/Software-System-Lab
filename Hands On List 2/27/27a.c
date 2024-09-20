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
    struct msgbuf data;

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

    data.mtype = 1;
    data.someNumber = 100;

    if (msgsnd(msgId, &data, sizeof(data.someNumber), 0) == -1) {
        perror("Error sending message");
        _exit(1);
    }

    printf("Message sent!\n");

    return 0;
}

/*
Output:
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2/27$ ./27a
Message sent!
*/
