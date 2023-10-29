/*
Published by :- Sandesh Kale
Linkedin :-  https://www.linkedin.com/in/sandesh-s-kale
@github     :- JAGAHPEE
*/
#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

// 
struct node *start = NULL;
struct node *insert_at_front(struct node *);
struct node *display(struct node *);
struct node *find_e(struct node *);

int main()
{
    int option;
    while (1)
    {

        printf("\nPress 1 to Insert:");
        printf("\nPress 2 to Find:");
        printf("\nPress 3 to Display:");
        printf("\nPress 4 to Exit:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = insert_at_front(start);
            break;
        case 2:
            start = find_e(start);
            break;
        case 3:
            start = display(start);
            break;
        case 4:
            exit(1);
        default:
            exit(1);
            break;
        }
    }
}

// To Insert node at the Beginning
struct node *insert_at_front(struct node *start)
{
    int num;
    struct node *ptr;
    printf("\nEnter the Data:");
    scanf("%d", &num);
    while (1)
    {

        ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = num;
        ptr->next = start;
        start = ptr;
        printf("\nPress -1 to end");
        printf("\nEnter the Data:");
        scanf("%d", &num);
        if (num == -1)
        {
            break;
        }
    }
    return start;
}

// To Display List
struct node *display(struct node *start)
{
    if (start != NULL)
    {
        struct node *ptr;
        ptr = start;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    else
    {
        printf("List is Empty");
    }
    return start;
}


// To Find the node and bring to front
struct node *find_e(struct node *start)
{
    int num;
    struct node *ptr,*temp=NULL;
    if(start==NULL)
    {
        printf("\nList is Empty");
    }
    else
    {
        ptr = start;
        printf("\nEnter the Node to find");
        scanf("%d",&num);
        if(ptr->data==num)
        {
            printf("\nElement is Found");
        }
        else
        {
            while (ptr->next!=NULL && ptr->next->data!=num)
            {
                ptr = ptr->next;
            }
            if(ptr->next!=NULL)
            {
                temp = ptr->next;
                ptr->next = temp->next;
                temp->next = start;
                start = temp;

            }
            else
            {
                printf("\nElement not Found");
            }
            
        }
    }
    return start;
}