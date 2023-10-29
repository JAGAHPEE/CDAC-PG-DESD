/*
Published by :- Sandesh Kale
Linkedin :-  https://www.linkedin.com/in/sandesh-s-kale
@github     :- JAGAHPEE
*/
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int *data;
	int front;
	int rear;
	int size;
}q;

int deque();
void enque(int);
int underflow();
int overflow();
void display();

int main()
{
	int n;
	scanf("%d",&q.size);
	q.data = (int *)malloc(sizeof(int)*q.size);
	q.front =-1;
	q.rear =-1;
	enque(1);
	enque(12);
	enque(13);
	enque(14);
	display();
	printf("\n");
	deque();
	deque();
	deque();
	display();
}

int underflow()
{
	if(q.rear ==-1 && q.front == -1)
	{
		return 1;
	}
	return 0;
}
int overflow()
{
	if(q.rear == q.size-1)
	{
		return 1;
	}
	return 0;
}

void enque(int n)
{
	if(!overflow())
	{
		if(underflow())
		{
			q.front++;
		}
		
		q.data[++q.rear] = n;
		
	}
	else
	{
		printf("Queue is Full");
	}	
}
int deque()
{
	int x= -1;
	if(!underflow())
	{
		x = q.data[q.front];
		if(q.front == q.rear)
		{
			q.front = q.rear =-1;
		}  
		else
		{
			q.front++;
		}
	}
	else
	{
		printf("Queue is Empty\n");
	}
	return x;
}
/* Owner :- Sandesh Kale  */
void display()
{
	if(!underflow())
	{
		for(int i=q.front;i<=q.rear;i++)
		{
			printf("%d ",q.data[i]);
		}
	}
	else
	{
		printf("Queue is Empty");
	}
}
