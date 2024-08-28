#include <stdio.h>
#include <unistd.h>

int main() {
    
    // Create a hard link
    if (link("testfile.txt","hrdlnk") == 0) {
	printf("Hard link-hrdlnk created successfully for testfile.\n");
    } else {
	perror("Failed to create symbolic link.");
    }

    return 0;
}

