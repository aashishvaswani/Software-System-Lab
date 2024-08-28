//5. Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void main()
{
    while (1)
    {
        creat("file_1.txt", O_CREAT);
        creat("file_2.txt", O_CREAT);
        creat("file_3.txt", O_CREAT);
        creat("file_4.txt", O_CREAT);
        creat("file_5.txt", O_CREAT);
    }
}
