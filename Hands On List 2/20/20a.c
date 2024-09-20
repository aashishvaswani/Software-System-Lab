#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char *fifoPath = "./20-fifo";
    char message[] = "Hello from program 20a!";
    mkfifo(fifoPath, 0666);

    int fd = open(fifoPath, O_WRONLY);
    if (fd == -1) {
        perror("Unable to open FIFO for writing");
        return 1;
    }

    write(fd, message, sizeof(message));
    close(fd);

    return 0;
}

