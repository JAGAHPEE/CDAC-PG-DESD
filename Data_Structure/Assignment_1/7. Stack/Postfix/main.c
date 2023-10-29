/*
Published by :- Sandesh Kale
Linkedin :-  https://www.linkedin.com/in/sandesh-s-kale
@github     :- JAGAHPEE
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack_function.h"


char *op;
char ip[] = "{a+b*c/f-[d*e/g]}";
int main()
{
	int l = strlen(ip);
	char sta,ch;
	std.size = l;
	int j=0;
	std.tos=-1;
	op = (char*)malloc(sizeof(char)*l);
	std.a = (int*)malloc(sizeof(int)*l);
	printf("%d",l);
	for(int i=0;i<l;i++)
	{
		ch = ip[i];
		printf("%c",ch);
		switch(ch)
		{
			case '{':
			case '(':
			case '[':
				push(ch);
				printf("%c\n",peep());
				break;
			case '}':
			case ']':
			case ')':
				while(!(peep()=='[' || peep()=='{'||peep()=='('))
				{
					op[j] = pop();
					j++;
				}
				sta = pop();
				break;
			case '-':
			case '+':
			case '*':
			case '/':
				while(!is_Empty() && (prec(ch)<=(prec(peep()))))
				{
					op[j] = pop();
					j++;
				}
				push(ch);
				break;
			default:
				op[j] = ch;
				j++;
				printf("%c\n",peep());
				break;
		}
		
		
	}
	op[j] = '\0';
	printf("\n%s",op);
}


