//function
1)Write a program in C to create process with four child process and do each of the following operations:
	a) Read three subjects marks from user in the parent process and sends 	them to child process over a pipe.

	b) Child process should find the grade based on the criteria given in 	table 1 and pass it to the parent process over a pipe.

	c) Finally parent process displays the grade.
	   Each process should print their Process ID's, sleep and wakeup status.

			Table 1: Grading
		Average		Grade
   	   100>=average>74	 A
   	   74>=average>60	 B	
   	   60>=average>45	 C
   	   45>=average>34	 D
   	   34>=average>00	 E

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
char grade(int);
int main(){
        int p1[2], p2[2], pid;
        pipe(p1);
        pipe(p2);

        pid=fork();
        if(pid==0){
		printf("I am child.My process id is %d\n",getpid());

                sleep(1);
                int cm1, cm2, cm3, ca;
                char ans;
                close(p1[1]);
                close(p2[0]);


                read(p1[0], &cm1, sizeof(cm1));
                read(p1[0], &cm2, sizeof(cm2));
                read(p1[0], &cm3, sizeof(cm3));

                ca=(cm1+cm2+cm3)/3;

                ans=grade(ca);

                write(p2[1],&ans,sizeof(ans));

        }

        else{
		printf("I am parent. My process id is %d\n",getpid());

                int pm1, pm2, pm3;
                char pans;
                close(p1[0]);
                close(p2[1]);

                printf("Enter the marks1 :");
                scanf("%d", &pm1);

                printf("Enter the marks2 :");
                scanf("%d", &pm2);

                printf("Enter the marks3 :");
                scanf("%d", &pm3);

                write(p1[1], &pm1, sizeof(pm1));
                write(p1[1], &pm2, sizeof(pm2));
                write(p1[1], &pm3, sizeof(pm3));

                sleep(1);


                read(p2[0],&pans,sizeof(pans));
                printf("Grade is= %c\n",pans);
        }

        return 0;
                   }

char grade(int a)
{
        char grade;
        if(a<=100 && a>0){
			if(a>74)
				grade='A';
			else if(a>60)
				grade='B';
			else if(a>45)
				grade='C';
			else if(a>34)
				grade='D';
			else
				grade='E';
			}
		else
            printf("wrong input");

        return grade;
}
