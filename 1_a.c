#include <unistd.h>  // For symlink
#include <stdio.h>

int main() {
   
    // Attempt to create a symbolic link
    if (symlink("testfile.txt", "sftlnk") == 0) {
        printf("Symbolic link sftlnk created pointing to testfile.\n");
    } else {
        perror("Failed to create symbolic link");
    }

    return 0;
}
