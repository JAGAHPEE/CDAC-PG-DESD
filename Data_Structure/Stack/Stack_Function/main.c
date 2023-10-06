/* Owner :- Sandesh Kale  */
#include<stdio.h>
#include"stack_function.h"
#include<stdlib.h>

int main()
{
	int opt;
	int n;
	std.tos=-1;
	printf("\nEnter the Size of array:");
	scanf("%d",&std.size);
	std.a = (int *)malloc(std.size*sizeof(int));	
	while(1)
	{
		
		printf("\nPress 1 to PUSH\n");
		printf("Press 2 to POP\n");
		printf("Press 3 to PEEP\n");
		printf("Press 4 to DISPLAY\n");
		printf("Enter Option: ");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				printf("\nEnter value to Insert: ");
				scanf("%d",&n);
				push(n);
				break;
			case 2:
				n = pop();
				if(n>=0)
				{
					printf("\nElement deleted: %d\n\n",n);	
				}
				break;
			case 3:
				n = peep();
				if(n>=0)
				{
					printf("\nElement at the top of the stack: %d\n\n",n);
				}
/* Owner :- Sandesh Kale  */
				break;
			case 4:
				display();
				break;
			default:
				printf("Invalid Options--\n");
				break;
		}	
	}
}
