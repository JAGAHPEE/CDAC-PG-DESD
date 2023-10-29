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

// Functions of circular Link List
struct node *create_cll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *delete_after(struct node *);
struct node *delete_cll(struct node *);

int main()
{
    int option;
    while (1)
    {
        printf("\nPress 1 to Create Circular List ");
        printf("\nPress 2 to Insert data in Beginning");
        printf("\nPress 3 to Insert data at ENd");
        printf("\nPress 4 to Delete First elemment");
        printf("\nPress 5 ot Delete Last elemment");
        printf("\nPress 6 to Delete After elemment");
        printf("\nPress 7 to Delete List ");
        printf("\nPress 8 to Display");
        printf("\nPress 9 to Exit");
        printf("\nEnter Options: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_cll(start);
            break;
        case 2:
            start = insert_beg(start);
            break;
        case 3:
            start = insert_end(start);
            break;
        case 4:
            start = delete_beg(start);
            break;
        case 5:
            start = delete_end(start);
            break;
        case 6:
            start = delete_after(start);
            break;
        case 7:
            start = delete_cll(start);
            break;
        case 8:
            start = display(start);
            break;
        case 9:
            exit(1);
        }
    }
}

// To Create Circular List
struct node *create_cll(struct node *start)
{
    struct node *ptr, *temp;
    int num;
    printf("\nEnter the Data: ");
    scanf("%d", &num);
    while (num != -1)
    {
        ptr = start;
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = num;
        if (ptr == NULL)
        {
            start = temp;
            temp->next = start;
            // return start;
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->next = start;
            // return start;
        }
        printf("\nPress -1 to end");
        printf("\n Enter the Data: ");
        scanf("%d", &num);
    }
    return start;
}

// To Display Circular List
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (ptr != NULL)
    {

        printf("\nCircular List: ");
        while (ptr->next != start)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d ", ptr->data);
        printf("\n");
    }
    else
    {
        printf("\nList is Empty\n");
    }
    return start;
}

// To Insert in Beginning
struct node *insert_beg(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\nEnter the Data to Insert at the Beginning: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    if (ptr == NULL)
    {
        start = new_node;
        new_node->next = start;
    }
    else
    {
        ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = start;
        start = new_node;
    }
    return start;
}

// To Insert at the End
struct node *insert_end(struct node *start)
{
    struct node *ptr, *new_node;
    int num;
    printf("\nEnter the Data to Insert at the End: ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    ptr = start;
    if (ptr == NULL)
    {
        start = new_node;
        new_node->next = start;
    }
    else
    {
        ptr = start;
        while (ptr->next != start)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next = start;
    }
    return start;
}

// To delete at the Beginning
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (ptr != NULL)
    {

        if (ptr->next == start)
        {
            free(ptr);
            start = NULL;
        }
        else
        {
            ptr = start;
            while (ptr->next != start)
            {
                ptr = ptr->next;
            }
            ptr->next = start->next;
            free(start);
            start = ptr->next;
        }
        return start;
    }
    else
    {
        printf("\nList is Empty\n");
    }
    return start;
}

// To delete last element
struct node *delete_end(struct node *start)
{

    struct node *ptr, *preptr;
    ptr = preptr = start;
    if (ptr != NULL)
    {

        while (ptr->next != start)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        // preptr->next = start;
        free(ptr);
    }
    else
    {
        printf("\nList is Empty\n");
    }
    return start;
}

// To delete after the node
struct node *delete_after(struct node *start)
{
    struct node *ptr, *preptr;
    ptr = preptr = start;
    int num;
    printf("\nEnter the node to delete the next node\n");
    scanf("%d", &num);
    if (ptr != NULL)
    {
        if (ptr->next != start)
        {
            while (preptr->next != start && preptr->data != num)
            {
                preptr = ptr;
                ptr = ptr->next;
            }
            if (preptr->next != start)
            {

                preptr->next = ptr->next;
                // if (ptr == start)
                // {
                //     start = preptr->next;
                // }
                free(ptr);
            }
            else
            {
                printf("\nElement not found\n");
            }
            return start;
        }
        else
        {
            printf("\nNo other element is present\n");
        }
        return start;
    }
    else
    {
        printf("\nList is Empty\n");
    }
    return start;
}

// To delete the list
struct node *delete_cll(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (ptr != NULL)
    {

        while (ptr->next != start)
        {
            start = delete_end(start);
        }
        free(start);
        start  = NULL;
    }
    else
    {
        printf("\nList is Empty\n");
    }
    return start;
}