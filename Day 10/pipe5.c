/* write a program c to create process with four child process and 
do each of the following operations.  read three subjects marks 
from user in the parent process and sends them to child process 
over a pipe. child process should find the grade based on the 
criteria given in table 1 and pass it to the parent process over 
a pipe finally parent process displays the grade. each process 
should print their process id's sleep and wakup status. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

char getGrade(float avg) {
		if (avg > 74) 
			return 'A';
		else if (avg > 60) 
			return 'B';
		else if (avg > 45) 
			return 'C';
		else if (avg > 34) 
			return 'D';
		else 
			return 'E';
	}
	
int main() {
    int i;
    int p1[2], p2[2];
    pid_t pid;

    for (i = 1; i <= 4; i++) {
        pipe(p1);
        pipe(p2);

        pid = fork();

        if (pid == 0) {
            close(p1[1]);
            close(p2[0]);
            printf("Child %d (PID=%d) sleeping...\n", i, getpid());
            sleep(1);
            printf("Child %d (PID=%d) woke up!\n", i, getpid());
            int marks[3];
            read(p1[0], marks, sizeof(marks));
            float avg = (marks[0] + marks[1] + marks[2]) / 3.0;
            char grade = getGrade(avg);
            write(p2[1], &grade, sizeof(grade));
            close(p1[0]);80
            close(p2[1]);
            exit(0);
        } else {
            close(p1[0]);
            close(p2[1]);
            int marks[3];
            printf("\nEnter 3 marks for Child %d: ", i);
            scanf("%d %d %d", &marks[0], &marks[1], &marks[2]);
            printf("Parent (PID=%d) sleeping...\n", getpid());
            sleep(1);
            printf("Parent (PID=%d) woke up!\n", getpid());
            write(p1[1], marks, sizeof(marks));
            char grade;
            read(p2[0], &grade, sizeof(grade));
            printf("Parent received grade '%c' from Child %d (PID=%d)\n", grade, i, pid);
            close(p1[1]);
            close(p2[0]);
            wait(NULL);
        }
    }

    printf("\nAll child processes completed.\n");
    return 0;
}

