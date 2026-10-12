// parents get - height, length(rectangle)
//child 1 -find perimeter
//child 2 - find area
// parents want to print the perimeter and area of the rectangle

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
	int length,height;
	printf("Enter the Length: ");
	scanf("%d",&length);
	printf("Enter the Height: ");
	scanf("%d",&height);
	
	int p1[10],p2[10],p3[10],p4[10],pid1,pid2;
	pipe(p1);
	pipe(p2);
	pipe(p3);
	pipe(p4);
	
	pid1=fork();
	pid2=fork();
	
	if(pid1==0){
		close(p1[1]);
		close(p2[0]);
		close(p3[0]);
		close(p4[0]);
		close(p3[1]);
		close(p4[1]);
		
		int l, h;
        read(p1[0], &l, sizeof(l));
        read(p1[0], &h, sizeof(h));
        int perimeter = 2 * (l + h);
        write(p2[1], &perimeter, sizeof(perimeter));
        return 0;
	}
    
	if (pid2 == 0) {
        close(p3[1]);
        close(p4[0]);
        close(p1[0]); 
		close(p1[1]);
        close(p2[0]); 
		close(p2[1]);

        int l, h;
        read(p3[0], &l, sizeof(l));
        read(p3[0], &h, sizeof(h));
        int area = l * h;
        write(p4[1], &area, sizeof(area));
        return 0;
    }
	
	close(p1[0]);
    close(p2[1]);
    close(p3[0]);
    close(p4[1]);

    write(p1[1], &length, sizeof(length));
    write(p1[1], &height, sizeof(height));

    write(p3[1], &length, sizeof(length));
    write(p3[1], &height, sizeof(height));

    int perimeter, area;
	
    read(p2[0], &perimeter, sizeof(perimeter));
	printf("\nPerimeter of rectangle = %d", perimeter);
	
	
    read(p4[0], &area, sizeof(area)); 
    printf("\nArea of rectangle = %d\n", area);
	
	return 0;
	
}