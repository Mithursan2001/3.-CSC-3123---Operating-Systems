#include <stdio.h>
#include <unistd.h>

int main() {
    int p1[2], p2[2], pid;
    int n1, n2, sum;
    pipe(p1);
    pipe(p2);

    pid = fork();

    if (pid == 0) {
        close(p1[1]);
        close(p2[0]);

        read(p1[0], &n1, 4);
        read(p1[0], &n2, 4);

        sum = n1 + n2;

        write(p2[1], &sum, 4);
    } 
    else {
        close(p1[0]);
        close(p2[1]);

        printf("Enter two integers: ");
        scanf("%d %d", &n1, &n2);

        write(p1[1], &n1, 4);
        write(p1[1], &n2, 4);

        read(p2[0], &sum, 4);

        printf("Sum received from child: %d\n", sum);
    }

    return 0;
}

#include <stdio.h>
#include <unistd.h>

int main() {
    int p1[2], p2[2], pid;
    int nums[2], sum;

    pipe(p1);
    pipe(p2);

    pid = fork();

    if (pid == 0) {
        close(p1[1]);
        close(p2[0]);

        read(p1[0], nums, sizeof(nums));
        sum = nums[0] + nums[1];
        write(p2[1], &sum, sizeof(sum));
    } 
    else {
        close(p1[0]);
        close(p2[1]);

        printf("Enter 1st integers: ");
        scanf("%d", &nums[0]);
		
		printf("Enter 2nd integers: ");
        scanf("%d",&nums[1]);

        write(p1[1], nums, sizeof(nums));
        read(p2[0], &sum, sizeof(sum));

        printf("Sum received from child: %d\n", sum);
    }

    return 0;
}
