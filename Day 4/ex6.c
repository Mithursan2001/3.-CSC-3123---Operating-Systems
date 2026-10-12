#include<stdio.h>
#include<unistd.h>
int main(){
    int v;
    v=fork();
    if(v<0){
        printf("fork failes! No chil process created");
        return -1;
    }
    if(v>0){
        printf("\nI'm Parent! My process id  is %d\n",getpid());
        printf("\nMy Parent's process id  is %d\n",getppid());
        printf("Value of v is %d\n",v);
    }
    if(v==0){
        printf("\nI'm Child! My process id  is %d\n",getpid());
        printf("\nMy Parent's process id  is %d\n",getppid());
        printf("Value of v is %d\n",v);
    }
	return 0;
}