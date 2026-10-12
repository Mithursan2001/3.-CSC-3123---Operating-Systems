#include<stdio.h>
#include<unistd.h>
int main(){
	int B,C,D,E,F,G;
    B=fork();
	
	if(B==0){
        printf("B pid is %d ppid is %d\n",getpid(),getppid());
		G=fork();
		if(G==0){
			printf("G pid is %d ppid is %d\n",getpid(),getppid());
		}
    }
	
	else{
		printf("A pid is %d ppid is %d\n",getpid(),getppid());
		C=fork();
		if(C==0){
			printf("C pid is %d ppid is %d\n",getpid(),getppid());
			D=fork();
			if(D==0){
				printf("D pid is %d ppid is %d\n",getpid(),getppid());
			}
			else{
				E=fork();
				if(E==0){
					printf("E pid is %d ppid is %d\n",getpid(),getppid());
					F=fork();
					if(F==0){
						printf("F pid is %d ppid is %d\n",getpid(),getppid());
					}
				}
			}
		}
	}		
	return 0;
}