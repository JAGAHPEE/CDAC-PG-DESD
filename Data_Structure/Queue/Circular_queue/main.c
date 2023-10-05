#include<stdio.h>
#include<stdlib.h>
struct node
{
	int *data;
	int rear;
	int front;
	int size;
}q;
void enque(int);
int deque();
int underflow();
int overflow();
void display();

int main()
{
	scanf("%d",&q.size);
	q.data = (int *)malloc(sizeof(int)*q.size);
	q.front =-1;
	q.rear=-1;
	enque(10);
	enque(10);
	enque(10);
	display();
	deque();
	
	
}
int underflow()
{
	if(q.front==-1 && q.rear==-1)
	{
		return 1;
	}
	return 0;
}
int overflow()
{
	if((q.rear+1)%q.size == q.front)
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
		q.rear = (q.rear+1)%q.size;
		q.data[q.rear] = n;
		
	}
	else
	{
		printf("Queue is FULL");
	}
}
int deque()
{
	int x =-1;
	if(!underflow())
	{
		x = q.data[q.front];
		if(q.front == q.rear)
		{
			q.front = q.rear =-1;
		}
		else
		{
			q.front = (q.front+1)%q.size;
		}
	}
	else
	{
		printf("Queue is Empty\n");
	}
	return x;
}
void display()
{
	if(!underflow())
	{
		int i;
		for(i = q.front;i!=q.rear;i=(i+1)%q.size)
		{
			printf("%d ",q.data[i]);
		}
		printf("%d ",q.data[i]);
	}
	else
	{
		printf("Queue is Empty");
	}
}
