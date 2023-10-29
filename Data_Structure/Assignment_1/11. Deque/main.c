/*
Published by :- Sandesh Kale
Linkedin :-  https://www.linkedin.com/in/sandesh-s-kale
@github     :- JAGAHPEE
*/
#include<stdio.h>
#include<stdlib.h>
 
 struct node
 {
 	int data;
 	struct node *next;
 };
 struct node *start=NULL;
 struct node *display(struct node*);
 struct node *insert_beg(struct node*);
 struct node *delete_beg(struct node *);
 struct node *delete_last(struct node*);
 
int main()
{	
	int option;
	while(1)
	{
		printf("\nPress 1 to Display");
		printf("\nPress 2 to Insert");
		printf("\nPress 3 to Delete");
		printf("\nEnter the Options:");
		scanf("%d",&option);
		switch (option)
		{
		case 1:
			start = display(start);
			break;
		case 2:
			start = insert_beg(start);
			break;
		case 3:
			start = delete_last(start);
			break;
		case 4:
			exit(1);
			break;
		default:
			break;
		}
	
	
	}
}

// To Display the List
struct node *display(struct node *start)
{
	if(start==NULL)
	{
		printf("\n***List is Empty***\n");
		return start;
	}
	else
	{
		struct node *ptr;
		ptr = start;

		while (ptr!=NULL)
		{
			printf("%d ",ptr->data);
			ptr = ptr->next;

		}// END of Loop

	}// End of IF_ELSE
	return start;
}// End of Function

// To Insert node at the Beginning
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	printf("\nENter the Number to Inster in the Beginning: ");
	int n;
	scanf("%d",&n);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = n;
	new_node->next = start;
	start = new_node;
	return start; 
}

// To Insert data before the given node
struct node *insert_before(struct node *start)
{
		struct node *ptr,*temp;
		printf("\nEnter the element to insert: ");
		int n;
		scanf("%d",&n);
		printf("\nEnter the node to insert element before: ");
		int val;
		scanf("%d",&val);
		// Check whether the list is empty or not
		if(start!=NULL)
		{
			ptr = start;
			// Check First node Seperately
			if(ptr->data==val)
			{
				temp = (struct node*)malloc(sizeof(struct node));
				temp->data = n;
				temp->next = start;
				start = temp;
			}
			else
			{
				// Loop will exit either it reaches NULL or it finds the value
				while (ptr->next!=NULL && ptr->next->data!=val)
				{
					ptr=ptr->next;
				}
				// Check if value find or search complete
				if(ptr->next!=NULL)
				{
					temp = (struct node*)malloc(sizeof(struct node));
					temp->data = n;
					temp->next = ptr->next;
					ptr->next= temp;
				}
				else
				{
				return start;	printf("Element not Found\n");
				}
				
			}
		}
		else
		{
			printf("List is Empty\n");
		}
		return start;
} 
	
// To Delete the Last Node in the List
struct node *delete_last(struct node *start)
{
	struct node *ptr;
	ptr = start;
	// Check whether List Exist or Not
	if(ptr!=NULL)
	{
		// Check whether the First node next is NULL or Not
		if(ptr->next==NULL)
		{
			start = delete_beg(start);
			return start;
		}
		else
		{	// check ptr next node is NULL or not
			while (ptr->next->next!=NULL)
			{
				ptr = ptr->next;
			}
			// ptr next node
			free(ptr->next);
			// Assign NULL
			ptr->next=NULL;
			return start;
		}
		
	}
	// Else List is Empty
	else
	{
		printf("List is Empty");
	}
	return start;
}
// To delete the Beginning Node
struct node *delete_beg(struct node *start)
{
	if(start!=NULL)
	{
		struct node *temp;
		temp = (struct node*)malloc(sizeof(struct node));
		temp = start;
		start = temp->next;
		free(temp);
	}
	else
	{
		printf("List is Empty");
	}
	return start;
}

