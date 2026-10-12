//function
//The parent process read 2 integers through keyboard and sent them to the child using pipe.Child process read them,finds the sum
//and sends the sum to the parent using another pipe.parent process reads the sum and display it.

#include <stdio.h>
#include <unistd.h>

void parentProcess(int p1[], int p2[]);
void childProcess(int p1[], int p2[]);

int main() {
    int p1[2], p2[2], pid;

    pipe(p1);
    pipe(p2);
    pid = fork();

    if (pid == 0)
        childProcess(p1, p2);
    else
        parentProcess(p1, p2);

    return 0;
}

void parentProcess(int p1[], int p2[]) {
    int pa, pb, ps;
    close(p1[0]);
    close(p2[1]);

    printf("Enter the first number: ");
    scanf("%d", &pa);
    printf("Enter the second number: ");
    scanf("%d", &pb);

    write(p1[1], &pa, sizeof(pa));
    write(p1[1], &pb, sizeof(pb));

    sleep(1);
    read(p2[0], &ps, sizeof(ps));
    printf("Sum = %d\n", ps);
}

void childProcess(int p1[], int p2[]) {
    int ca, cb, cs;
    sleep(1);
    close(p1[1]);
    close(p2[0]);

    read(p1[0], &ca, sizeof(ca));
    read(p1[0], &cb, sizeof(cb));

    cs = ca + cb;
    write(p2[1], &cs, sizeof(cs));
}
