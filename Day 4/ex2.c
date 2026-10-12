#include<stdio.h>
#include<unistd.h>
int main(){

	int pid;
	pid=getpid();
	printf("My process is %d\n",pid);
	return 0;
}