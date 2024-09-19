#include <unistd.h>
#include <stdio.h>

int main() {
    int pipeEnds[2];
    pipe(pipeEnds);

    if (fork() == 0) {
        // Child process: execute wc
        close(pipeEnds[1]); 
        close(STDIN_FILENO);
        dup(pipeEnds[0]);
        close(pipeEnds[0]);
        execlp("wc", "wc", NULL);
    } else {
        // Parent process: execute ls -l
        close(pipeEnds[0]); 
        close(STDOUT_FILENO);
        dup(pipeEnds[1]);
        close(pipeEnds[1]);
        execlp("ls", "ls", "-l", NULL);
    }

    return 0;
}

