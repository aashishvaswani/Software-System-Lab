#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    char *fifoPath = "./20-fifo";
    char buffer[100];
    mkfifo(fifoPath, 0666);

    int fd = open(fifoPath, O_RDONLY);
    if (fd == -1) {
        perror("Unable to open FIFO for reading");
        return 1;
    }

    int bytesRead = read(fd, buffer, sizeof(buffer));
    printf("Received: %s\n", buffer);

    close(fd);
    return 0;
}

