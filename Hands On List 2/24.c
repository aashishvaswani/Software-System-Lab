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
        perror("Error creating message queue");
        _exit(1);
    }

    printf("Key: %d\n", key);
    printf("Message Queue ID: %d\n", msgId);

    return 0;
}

/*
Output:

aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./24
Key: 17039544
Message Queue ID: 0
*/
