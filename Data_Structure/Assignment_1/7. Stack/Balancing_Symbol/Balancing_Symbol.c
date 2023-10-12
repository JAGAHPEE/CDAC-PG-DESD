#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
	int *a;
	int size;
	int tos;
}std;

void display();
void push(int);
int pop();
int peep();
int is_Empty();
int is_Full();
char str[] = "{a+b*a/f-[d*e/g]}";

int l;
int main()
{	std.size = strlen(str);
	std.a = (int *)malloc(std.size*sizeof(int));
	//printf("%s",str);
	int i,a,flag=0;
	int ch;
	std.tos=-1;
	l = strlen(str);
	//printf("%d",l);
	for(i=0;str[i]!='\0';i++)
	{
		ch =str[i];
		switch(ch) 
		{
			case '[':
				 push(ch);
				 printf("\n");
				 display();
				 break;
			case '{':
				 push(ch);
				 printf("\n");
				 display();
				 break;
			case ']':
				if(ch==']' && peep() =='[')
				{
					a = pop();
					display();
				}
				else
				{
					flag =1;
				}
				break;
			case '}':
				if(ch=='}' && peep() =='{')
				{
					a = pop();
					display();
				}
				else
				{
					flag =1;
				}
				break;	
			default:
				break;
		}
		if(flag ==1)
		{
			break;
		}
	}
	display();
	if(i==l && is_Empty())
	{
		printf("Balanced");
	}
	else
	{
		printf("Not Balanced");
	}
}
void display()
{
	if(!is_Empty())
	{
		for(int i=0;i<=std.tos;i++)
		{
			printf("%d ",std.a[i]);
		}
	}
	else
	{
		printf("Stack is Empty");
	}
}
int is_Empty()
{
	if(std.tos==-1)
	{
		return 1;
	}
	return 0;
}
int is_Full()
{
	if(std.tos == std.size-1)
	{
		return 1;
	}
	return 0;
}
void push(int num)
{
	if(!(is_Full()))
	{
		std.tos+=1;
		printf("%d\n",std.tos);
		std.a[std.tos]=num;
	}
	else
	{
		printf("Stack is Full");
	}
}
int pop()
{
	int x = -11;
	if(!(is_Empty()))
	{
		x = std.a[std.tos--];
	}
	else
	{
		printf("Stack is Empty\n");
	}
	return x;
}
int peep()
{
	int x = -11;  
	if(!(is_Empty()))
	{
		x = std.a[std.tos]; 
	}
	else
	{
		printf("Stack is Empty\n");
	}
	return x;
}
