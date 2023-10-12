#include<stdio.h>
 #include<stdlib.h>
 
 struct node
 {
 	int data;
 	struct node *next;
 };
 struct node *start=NULL;
 
 struct node *create_ll(struct node*);
 struct node *display(struct node*);
 struct node *insert_beg(struct node*);
 struct node *insert_end(struct node *);
 struct node *insert_before(struct node *);
 struct node *insert_after(struct node*);
 struct node *delete_beg(struct node*);
 struct node *delete_node(struct node*);
 struct node *delete_last(struct node*);
 struct node *delete_after(struct node*);
 struct node *delete_list(struct node*);
 struct node *sort_list(struct node*);

 
int main()
{	
	int option;
	while(1)
	{
		printf("\nPress 1 to Create List");
		printf("\nPress 2 to Display");
		printf("\nPress 3 to Insert at the Beginning");
		printf("\nPress 4 to Insert at the End");
		printf("\nPress 5 to Insert Before node");
		printf("\nPress 6 to Insert After node");
		printf("\nPress 7 to Delete at the Beginning");
		printf("\nPress 8 to Delete Particular node");
		printf("\nPress 9 to Delete last node");
		printf("\nPress 10 to Delete After node");
		printf("\nPress 11 to Delete list");
		printf("\nPress 12 to Sort list");
		printf("\nPress 14 to Exit");
		printf("\nEnter the Options:");
		scanf("%d",&option);
		switch (option)
		{
		case 1:
			start = create_ll(start);
			break;
		case 2:
			start = display(start);
			break;
		case 3:
			start = insert_beg(start);
			break;
		case 4:
			start = insert_end(start);
			break;
		case 5:
			start = insert_before(start);
			break;
		case 6:
			start = insert_after(start);
			break;
		case 7:
			start = delete_beg(start);
			break;
		case 8:
			start = delete_node(start);
			break;
		case 9:
			start = delete_last(start);
			break;
		case 10:
			start = delete_after(start);
			break;
		case 11:
			start = delete_list(start);
			break;
		case 12:
			start = sort_list(start);
			break;
		case 14:
			exit(1);
			break;
		default:
			break;
		}
	
	
	}
}

struct node *create_ll(struct node *start)
{
	int num;
	struct node *ptr,*new_node;
	printf("\nPress -1 to end");
	printf("\nEnter element to Insert: ");
	scanf("%d",&num);
	while (num!=-1)
	{
		new_node = (struct node *)malloc(sizeof(struct node));
		new_node->data = num; 
		if(start == NULL)
		{
			new_node->next=NULL;
			start = new_node;
		}
		else
		{
			ptr = start;
			while (ptr->next!=NULL)
			{
				ptr = ptr->next;
			}// End of While

			ptr->next  = new_node;
			new_node->next = NULL;

		}// End of IF ELSE

		printf("\nPress -1 to end");
		printf("\nEnter element to Insert:");
		scanf("%d",&num);

	}// End of While

	return start;

}// End of Function

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

// To Insert node at the End
struct node *insert_end(struct node *start)
{
	printf("\nEnter the element to insert at the end: ");
	int n;
	scanf("%d",&n);
	struct node *ptr,*temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->next=NULL;
	temp->data=n;
	// Check First node
	if(start ==NULL)
	{
		start = temp;
	}
	else
	{
		//Check till Last
		ptr = start;
		while (ptr->next!=NULL)
		{
			ptr = ptr->next;
		}
		ptr->next=temp;
		return start;
	}
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

// To delete the particular node
struct node *delete_node(struct node *start)
{
	struct node *ptr,*preptr;
	int n;
	printf("\nEnter the node to Delete: ");
	scanf("%d",&n);
	// Check First Node
	if(ptr->data == n)
	{
		start = delete_beg(start);
		return start;
	}
	else
	{
		// Shift pointer and check the value
		ptr = start;
		while (ptr->data!=n)
		{
			preptr = ptr;
			ptr  = ptr->next;
		}
		preptr->next = ptr->next;
		// Free Space
		free(ptr);
	}
	return start;
}

// To Insert node After the given node 
struct node *insert_after(struct node *start)
{
	struct node *ptr,*temp;
	ptr = start;
	int n,num;
	printf("\nEnter the data: ");
	scanf("%d",&n);
	printf("\nEnter the Node to to insert element after: ");
	scanf("%d",&num);
	// Check ptr is Not NULL
	if(ptr!=NULL)
	{
		// Loop will exit either it reaches NULL or it finds the value
		while(ptr!=NULL && ptr->data!=num)
		{
			ptr = ptr->next;
		}
		// Check if value find // search complete
		if(ptr!=NULL)
		{
			temp = (struct node *)malloc(sizeof(struct node));
			temp->data = n;
			temp->next=ptr->next;
			ptr->next = temp;
			return start;
		}
		else
		{
			printf("\nElement not Fount");
			return start;
		}
	}
	else
	{
		printf("List is Empty");
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

// To delete element after given node
struct node *delete_after(struct node *start)
{
	struct node *ptr,*preptr;
	ptr = preptr = start;
	int val;
	printf("\nEnter the node to delete after given node : ");
	scanf("%d",&val);
	while (preptr->data!=val)
	{
		preptr = ptr;
		ptr = ptr->next;
	}

	preptr->next = ptr->next;
	free(ptr);

	return start; 
}

struct node *delete_list(struct node *start)
{
	// Check If list exist
	if(start!=NULL)
	{
		struct node *ptr;
		ptr =start;
		while (ptr!=NULL)
		{
			printf("\nElement to be deleted: %d",ptr->data);
			// Call delete_beg function to delete element from starting of the list till becomes empty
			start = delete_beg(start);
			ptr = start;
		}
		printf("\n");
	}
	else
	{
		printf("List is Empty");
	}
	return start;
}

// To sort list in Assending Order
struct node*sort_list(struct node *start)
{
	struct node *ptr1,*ptr2;
	int temp;
	for (ptr1 = start;ptr1->next!=NULL; ptr1 = ptr1->next )
	{
		for(ptr2 = ptr1->next;ptr2!=NULL;ptr2=ptr2->next)
		{
			if(ptr1->data > ptr2->data)
			{
				temp = ptr1->data;
				ptr1->data = ptr2->data;
				ptr2->data = temp; 
			}
		}
	}
	return start;
}