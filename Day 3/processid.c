#include<stdio.h>
#include<unistd.h>
int main(){

	printf("Hello!\n");
	fork();
	printf("My process is %d\n",getpid());
	return 0;
}