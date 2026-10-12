#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int p1[2], p2[2];
    int rv1, rv2, childid;

    rv1 = pipe(p1);
    rv2 = pipe(p2);

    if (rv1 == -1 || rv2 == -1) {
        printf("Pipe creation failed\n");
        return -1;
    }

    childid = fork();

    if (childid < 0) {
        printf("Fork failed\n");
        return -1;
    }

    if (childid == 0) {
        close(p1[1]);
        close(p2[0]);

        int nums[2];
        read(p1[0], nums, sizeof(nums));

        int sum = nums[0] + nums[1];
        write(p2[1], &sum, sizeof(sum));

        close(p1[0]);
        close(p2[1]);
    } else {
        close(p1[0]);
        close(p2[1]);

        int nums[2];
        printf("Enter two integers: ");
        scanf("%d %d", &nums[0], &nums[1]);

        write(p1[1], nums, sizeof(nums));

        int sum;
        read(p2[0], &sum, sizeof(sum));

        printf("Sum received from child: %d\n", sum);

        close(p1[1]);
        close(p2[0]);
    }

    return 0;
}
