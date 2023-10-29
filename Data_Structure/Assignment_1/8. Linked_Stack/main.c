/*
Published by :- Sandesh Kale
Linkedin :-  https://www.linkedin.com/in/sandesh-s-kale
@github     :- JAGAHPEE
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *start = NULL;
struct node *last = NULL;
struct node *push(struct node *);
struct node *pop(struct node *);
struct node *display(struct node *);

int main()
{
    int option;
    while (1)
    {
        printf("\nPress 1 to PUSH");
        printf("\nPress 2 to POP");
        printf("\nPress 3 to PEEK");
        printf("\nPress 4 to DISPLAY");
        printf("\nPress 5 to EXIT");
        printf("\nEnter the Options: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = push(start);
            break;
        case 2:
            start = pop(start);
            break;
        case 3:
            if (last != NULL)
                printf("Last Element Inserted: %d", last->data);
            else
                printf("No Element Inserted");
            break;
        case 4:
            start = display(start);
            break;
        default:
            return 0;
            break;
        }
    }
}

struct node *push(struct node *start)
{
    int num;
    struct node *ptr, *new_node;
    printf("\nEnter the Number: ");
    scanf("%d", &num);
    ptr = start;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    if (ptr == NULL)
    {
        start = new_node;
        new_node->next = NULL;
    }
    else
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = NULL;
    }
    last = new_node;
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    else
    {
        printf("Stack is Empty");
    }
    return start;
}

struct node *pop(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (ptr != NULL)
    {

        if (ptr->next == NULL)
        {
            ptr = (struct node *)malloc(sizeof(struct node *));
            ptr = start;
            start = start->next;
            last = start;
            free(ptr);
            ptr = NULL;
        }
        else
        {
            ptr = start;
            while (ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            free(ptr->next);
            ptr->next = NULL;
            last = ptr;
        }
    }
    else
    {
        printf("Stack Underflow");
    }
    return start;
}