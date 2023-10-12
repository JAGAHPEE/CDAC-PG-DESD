#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
int is_empty();
void insert();
void display();
void delete();
int peek();

int main()
{
    int option;
    while (1)
    {
        printf("\nPress 1 to Insert Element");
        printf("\nPress 2 to Delete Element");
        printf("\nPress 3 to Display Queue");
        printf("\nPress 4 to Display Peek Element");
        printf("\nEnter Options: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("\nPeek Element : %d", peek());
            break;
        default:
            return 0;
            break;
        }
    }
}

int peek()
{
    if (!(is_empty()))
    {
        return rear->data;
    }
    printf("\nQueue is Empty");
    return 0;
}
void display()
{
    struct node *ptr;
    if (!is_empty())
    {
        ptr = front;
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    else
    {
        printf("\nQueue is Empty");
    }
}
void insert()
{
    int n;
    printf("\nEnter the Number: ");
    scanf("%d", &n);
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = n;
    ptr->next = NULL;

    if (front == NULL)
    {
        front = ptr;
    }
    else
    {
        rear->next = ptr;
    }
    rear = ptr;
}
void delete()
{
    struct node *ptr;
    if (!is_empty())
    {
        ptr = front;
        printf("Element to be deleted: %d", ptr->data);
        if (front->next == NULL)
        {
            free(front);
            free(rear);
            front = rear = NULL;
        }
        else
        {
            front = front->next;
        }
        free(ptr);
    }
    else
    {
        printf("\nQueue is Empty");
    }
}
int is_empty()
{
    if (front == NULL && rear == NULL)
    {
        return 1;
    }
    return 0;
}