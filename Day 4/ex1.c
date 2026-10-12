#include<stdio.h>
#include<unistd.h>
int main(){
	printf("Hello!\n");
	fork();
	printf("Good Morning!\n");
	fork();
	printf("You're Welcome!\n");
	return 0;
}