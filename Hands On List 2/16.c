#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
    int pipe1[2], pipe2[2];
    pid_t pid;
    char msgFromParent[] = "Hello from Parent!";
    char msgFromChild[] = "Hello from Child!";
    char buffer[50];

    pipe(pipe1);
    pipe(pipe2);

    pid = fork();

    if (pid == 0) {
        close(pipe1[1]);
        close(pipe2[0]);

        read(pipe1[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);

        write(pipe2[1], msgFromChild, strlen(msgFromChild) + 1);

        close(pipe1[0]);
        close(pipe2[1]);
    } else {
        close(pipe1[0]);
        close(pipe2[1]);

        write(pipe1[1], msgFromParent, strlen(msgFromParent) + 1);

        read(pipe2[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);

        close(pipe1[1]);
        close(pipe2[0]);
    }

    return 0;
}

