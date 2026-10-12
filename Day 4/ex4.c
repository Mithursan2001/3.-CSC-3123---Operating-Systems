#include<stdio.h>
#include<unistd.h>
int main(){
	int pid,ppid;
	pid=getpid();
	ppid=getppid();
    printf("Hello!\n");
	printf("My process is %d\n",pid);
	printf("Parent process is %d\n",ppid);
	return 0;
}