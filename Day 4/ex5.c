#include<stdio.h>
#include<unistd.h>
int main(){
	fork();
	fork();
	printf("My process id  is %d and parent process id is %d\n",getpid(),getppid());
	return 0;
}
