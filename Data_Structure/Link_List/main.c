#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start;
// start = (struct node*)malloc(sizeof(struct node));
// start = NULL;

void insert_Beg(int ele);
void insert_End(int ele);
void insert_After(int ele,int n);
void insert_Before(int ele,int s);
int delete_First();
int delete_Last();
void delete_Sp(int, int);
void traverse_Forward();
void traverse_Backward();

int main()
{
	insert_Beg(11);
	traverse_Forward();
	printf("\n");
	insert_Beg(10);
	insert_Beg(12);
	traverse_Forward();
	printf("\n");
	delete_First();
	insert_End(10);
	traverse_Forward();
	printf("\n");
	insert_After(20,11);
	traverse_Forward();
	insert_Before(20,11);
	printf("\n");
}
void insert_Beg(int ele)
{
	struct node *temp;
	temp = (struct node *)malloc(sizeof(struct node));
	if (temp == NULL)
	{
		printf("Memory not created");
	}
	else
	{

		temp->data = ele;
		temp->next = start;
		start = temp;
	}
}
void insert_End(int ele)
{
	struct node *temp, *current;
	temp = (struct node *)malloc(sizeof(struct node *));
	// current = (struct node *)malloc(sizeof(struct node));
	temp->data = ele;
	temp->next = NULL;
	if (start == NULL)
	{
		start = temp;
	}
	else
	{
		current = start;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = temp;
	}
}

void insert_After(int ele, int s)
{
	struct node *current, *temp;
	if(start!=NULL)
	{
		current = start;
		while(current!=NULL && current->data !=s)
		{
			current = current->next;
		}
		if(current!=NULL)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = ele;
			temp ->next = current->next;
			current->next = temp;
		}
		else
		{
			printf("Element not Found");
		}
	}
	else
	{
		printf("List is Empty");
	}
}

void insert_Before(int ele,int s)
{
	struct node *temp,*current,*prev;
	if(start!=NULL)
	{	
		current = start;
  prev = current ;
		while (current!=NULL && current->data!=s)
		{
			prev = current;
			current = current->next;
		}
		if(current!=NULL)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = ele;
			temp->next = current;
			prev->next = temp;

		}
		else
		{
			printf("Element not found");
		}
		
	}
	else
	{
		printf("List is Empty");
	}

}

// void insert_After(int ele, int s)
// {
// 	struct node *current, *temp;
// 	if (start == NULL)
// 	{
// 		printf("List is Empty");
// 	}
// 	else
// 	{
// 		current = start;
// 		while (current != NULL && current->data != s)
// 		{
// 			current = current->next;
// 		}
// 		if (current != NULL)
// 		{
// 			temp = (struct node *)malloc(sizeof(struct node));
// 			temp->data = ele;
// 			temp->next = current->next;
// 			current->next = temp;
// 		}
// 		else
// 		{
// 			printf("Element not Found");
// 		}
// 	}
// }

int delete_First()
{
	int x;
	if(start!=NULL)
	{

		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp = start;
		x = temp->data;
		start = temp->next;
		free(temp);
	}
	else
	{
		printf("List is Empty");
	}
	return x;
}
void traverse_Forward()
{
	struct node *current;
	current = start;
	while (current != NULL)
	{
		printf("%d ", current->data);
		current = current->next;
	}
}
