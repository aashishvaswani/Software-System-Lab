//2. Write a simple program to execute in an infinite loop at the background. Go to /proc directory and identify all the process related information in the corresponding proc directory.
#include<stdio.h>

int main() {
	// ps aux | grep <name> -> to find process id for process having name - <name>
	//cat /proc/[PID]/status  -> to check status of process having process ID-'PID'
	while(1);
	return 1;
}
