#include<stdio.h>
#include"stack_function.h"

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