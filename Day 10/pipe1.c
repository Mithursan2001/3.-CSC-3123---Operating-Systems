//Two way Communication
#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main(){
	char msg1[25],msg2[25],msg3[25];
	int p1[2],p2[2],pid;
	pipe(p1);
	pipe(p2);
	
	pid=fork();
	if(pid==0){
		close(p1[1]);
		close(p2[0]);
		write(p2[1],"hello dad",25);
		sleep(1);
		read(p1[0],msg2,25);
		printf("%s\n",msg2);
		write(p2[1],"I am fine dad",25);
	}
	
	else{
		close(p1[0]);
		close(p2[1]);
		read(p2[0],msg1,25);
		printf("%s\n",msg1);
		write(p1[1],"hello baby how are you?",25);
		sleep(1);
		read(p2[0],msg3,25);
		printf("%s\n",msg3);
	}
	return 0;
}