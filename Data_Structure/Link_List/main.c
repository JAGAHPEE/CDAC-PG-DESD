/* Owner :- Sandesh Kale  */
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
void insert_After(int ele, int n);
void insert_Before(int ele, int s);
int delete_First();
int delete_Last();
void delete_Sp(int);
void traverse_Forward();
void traverse_Backward();
void print_func(struct node *);
void reverse();

int main()
{
	int option;
	while(1)
	{
		
		printf("\nPress 1 to Insert Beginning\n");
		printf("Press 2 to Insert End\n");
		printf("Press 3 to Insert After\n");
		printf("Press 4 to Insert Before\n");
		printf("Press 5 to Delete First\n");
		printf("Press 6 to Delete Last\n");
		printf("Press 7 to Delete Specific\n");
		printf("Press 8 to Travel Forward\n");
		printf("Press 9 to Travel Reverse\n");
		printf("Press 0 to Reverse List\n");		
		printf("Enter Option: ");
		scanf("%d",&option);
		int n;
		switch(option)
		{
			case 1:
				printf("\nEnter the element to Insert:");
				scanf("%d",&n);
				insert_Beg(n);
				break;
			case 2:
				printf("\nEnter the element to Insert:");
				scanf("%d",&n);
				insert_End(n);
				break;
			case 3:
				printf("\nEnter the element to Insert After:");
				scanf("%d",&n);
				insert_After(10,n);
				break;
			case 4:
				printf("\nEnter the element to Insert Before:");
				scanf("%d",&n);
				insert_Before(10,n);
				break;
			case 5:
				delete_First();
				break;
			case 6:
				delete_Last();
				break;
			case 7:
				printf("\nEnter the element for Delete Specific:");
				scanf("%d",&n);
				delete_Sp(10);
				break;
			case 8:
				traverse_Forward();
				break;
			case 9:
				traverse_Backward();
				break;
			case 0:
				reverse();
				break;
			default:
				printf("Invalid Options--\n");
				exit(1);
				break;
		}	
	}
}
/* Owner :- Sandesh Kale  */
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
/* Owner :- Sandesh Kale  */
void insert_After(int ele, int s)
{
	struct node *current, *temp;
	if (start != NULL)
	{
		current = start;
		while (current != NULL && current->data != s)
		{
			current = current->next;
		}
		if (current != NULL)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = ele;
			temp->next = current->next;
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

void insert_Before(int ele, int s)
{
	struct node *temp, *current, *prev;
	if (start != NULL)
	{
		current = start;
		if (current->data == s)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = ele;
			temp->next = start;
			start = temp;
		}
		else
		{

			current = start;
			while (current->next != NULL && current->next->data != s)
			{
				current = current->next;
			}
			if (current->next != NULL)
			{
				temp = (struct node *)malloc(sizeof(struct node));
				temp->data = ele;
				temp->next = current->next;
				current->next = temp;
			}
			else
			{
				printf("Element not found");
			}
		}
	}
	else
	{
		printf("List is Empty");
	}
}

int delete_First()
{
	int x;
	if (start != NULL)
	{

		struct node *temp;
		temp = (struct node *)malloc(sizeof(struct node));
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
void delete_Sp(int s)
{
	struct node *temp, *current;
	if (start != NULL)
	{
		current = start;

		if (current->data == s)
		{
			start = current->next;
			free(current);
		}
		else
		{
			while (current->next != NULL && current->next->data != s)
			{
				current = current->next;
			}
			if (current->next != NULL)
			{
				temp = (struct node *)malloc(sizeof(struct node));
				temp = current->next;
				current->next = temp->next;
				free(temp);
				temp = NULL;
			}
			else
			{
				printf("Element not found");
			}
		}
	}
	else
	{
		printf("List is empty");
	}
}
int delete_Last()
{
	struct node *temp, *current;
	int x = -1;
	if (start != NULL)
	{
		if (start->next == NULL)
		{
			x = start->data;
			free(start);
			start = NULL;
		}
		else
		{
			current = start;
			while (current->next->next != NULL)
			{
				current = current->next;
			}
			x = current->next->data;
			free(current->next);
			current->next = NULL;
		}
	}
	else
	{
		printf("List is Empty");
	}
	return x;
}
void print_func(struct node *current)
{
	if (current == NULL)
	{
		return;
	}
	print_func(current->next);
	printf("%d ", current->data);
}
void traverse_Backward()
{
	if (start != NULL)
	{
		print_func(start);
	}
	else
	{
		printf("List is Empty");
	}
}
void reverse()
{
	struct node *temp, *rev;
	rev = NULL;
	while (start != NULL)
	{
		temp = start;
		start = temp->next;
		temp->next = rev;
		rev = temp;
	}
	start = rev;
}
