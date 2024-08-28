#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

int main() {
	int count=mknod("myfifo", 0755, 0);
	if(count==0){
		printf("Fifo successfully created!\n");
	}else{
		printf("Fifo creation unsuccessful\n");
	}
	return 0;
}
