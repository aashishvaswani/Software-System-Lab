#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <unistd.h>

struct message {
    long mtype;
    int value;
};

int main() {
    key_t key;
    int msgId;
    struct message msg;

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

    msg.mtype = 1;
    msg.value = 100;

    if (msgsnd(msgId, &msg, sizeof(msg.value), 0) == -1) {
        perror("Error sending message");
        _exit(1);
    }

    printf("Message sent successfully! You can check using ipcs -q\n");
    return 0;
}

/*
Output:

ashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ./26
aashish-vaswani@aashish-vaswani-HP-Laptop-15g-dr0xxx:~/hl2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x010400b8 0          aashish-va 700        4            1           

*/
