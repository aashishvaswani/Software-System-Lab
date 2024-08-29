/*
Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
*/

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    const char *givenFileName = "testfile.txt";
    struct stat statForGivenFile;

    // Get the file statistics
    if (stat(givenFileName, &statForGivenFile) == -1) {
        perror("Failed to get file statistics");
        return 1;
    }

    // Print the file information
    printf("File: %s\n", givenFileName);
    printf("Inode: %ld\n", (long)statForGivenFile.st_ino);
    printf("Number of hard links: %ld\n", (long)statForGivenFile.st_nlink);
    printf("UID: %d\n", statForGivenFile.st_uid);
    printf("GID: %d\n", statForGivenFile.st_gid);
    printf("Size: %ld bytes\n", (long)statForGivenFile.st_size);
    printf("Block size: %ld bytes\n", (long)statForGivenFile.st_blksize);
    printf("Number of blocks: %ld\n", (long)statForGivenFile.st_blocks);

    // Convert time to human-readable format
    char fileLastAccessedTime[20], fileLastModifiedTime[20], fileLastChangedTime[20];
    strftime(fileLastAccessedTime, sizeof(fileLastAccessedTime), "%Y-%m-%d %H:%M:%S", localtime(&statForGivenFile.st_atime));
    strftime(fileLastModifiedTime, sizeof(fileLastModifiedTime), "%Y-%m-%d %H:%M:%S", localtime(&statForGivenFile.st_mtime));
    strftime(fileLastChangedTime, sizeof(fileLastChangedTime), "%Y-%m-%d %H:%M:%S", localtime(&statForGivenFile.st_ctime));

    printf("Time of last access: %s\n", fileLastAccessedTime);
    printf("Time of last modification: %s\n", fileLastModifiedTime);
    printf("Time of last change: %s\n", fileLastChangedTime);

    return 0;
}

