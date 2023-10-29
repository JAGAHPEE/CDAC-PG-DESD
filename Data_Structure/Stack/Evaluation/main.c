/*
Published by :- Sandesh Kale
Linkedin :-  https://www.linkedin.com/in/sandesh-s-kale
@github     :- JAGAHPEE
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack_function.h"
char op[] = "142*4/+56*3/-";
int main()
{
	int l;
	char sta,ch;
	int i=0;
	l = strlen(op);
	std.tos=-1;
	
	std.a = (int*)malloc(sizeof(int)*l);
	
	printf("%d",l);
	std.size = l;
	int a,b;
	for(i=0;i<l;i++)
	{
		ch = op[i];
		switch(ch)
		{
			case '+':
				b = pop();
				a = pop();
				printf("\n %d + %d = %d ",a,b,a+b);
				push(a+b);
				break;
			case '-':
				b = pop();
				a = pop();
				printf("\n %d - %d = %d ",a,b,a-b);
				push(a-b);
				break;
			case '*':
				b = pop();
				a = pop();
				printf("\n %d * %d = %d ",a,b,a*b);
				push(a*b);
				break;
			case '/':
				b = pop();
				a = pop();
				printf("\n %d // %d = %d ",a,b,a/b);
				push(a/b);
				break;
			default:
				push(atoi(&ch));
				break;		
		}
	}
	int result = pop();
	printf("Result = %d",result);
}


/*
Published by :- Sandesh Kale
Linkedin :-  https://www.linkedin.com/in/sandesh-s-kale
@github     :- JAGAHPEE
*/