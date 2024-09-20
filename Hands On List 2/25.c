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

