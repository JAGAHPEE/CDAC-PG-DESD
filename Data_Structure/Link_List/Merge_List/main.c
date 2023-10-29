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
struct node *list1 = NULL;
struct node *list2 = NULL;
struct node *list3 = NULL;

struct node *create_list(struct node *);
struct node *display(struct node *);
struct node *Merge(struct node *, struct node *, struct node *);
struct node *add_node(struct node *, int);
struct node *return_last_addrs(struct node*);
int main()
{
    int option;
    while (1)
    {
        printf("\nPress 1 to Create List 1");
        printf("\nPress 2 to Display List 1");
        printf("\nPress 3 to Create List 2");
        printf("\nPress 4 to Display List 2");
        printf("\nPress 5 to Merge List");
        printf("\nPress 6 to Display Merge List");
        printf("\nEnter the Option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nEnter Sorted List: ");
            list1 = create_list(list1);
            break;
        case 3:
            list2 = create_list(list2);
            break;
        case 2:
            list1 = display(list1);
            break;
        case 4:
            list2 = display(list2);
            break;
        case 5:
            list3 = Merge(list1, list2, list3);
            break;
        case 6:
            list3 = display(list3);
            break;
            return 0;
        default:
            return 0;
            break;
        }
    }
}

struct node *Merge(struct node *start1, struct node *start2, struct node *start3)
{
    struct node *ptr1, *ptr2;
    ptr1 = start1;
    ptr2 = start2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->data == ptr2->data)
        {
            start3 = add_node(start3, ptr1->data);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if (ptr1->data < ptr2->data)
        {
            start3 = add_node(start3, ptr1->data);
            ptr1 = ptr1->next;
        }
        else if (ptr2->data < ptr1->data)
        {
            start3 = add_node(start3, ptr2->data);
            ptr2 = ptr2->next;
        }
    }
    if (ptr1 == NULL)
    {
        while (ptr2 != NULL)
        {
            if (ptr2->data > return_last_addrs(start3)->data)
            {
                start3 = add_node(start3, ptr2->data);
                ptr2 = ptr2->next;
            }
            else
            {
                ptr2 = ptr2->next;
            }
        }
    }
    if (ptr2 == NULL)
    {
        while (ptr1 != NULL)
        {
            if (ptr1->data > return_last_addrs(start3)->data)
            {

                start3 = add_node(start3, ptr1->data);
                ptr1 = ptr1->next;
            }
            else
            {
                ptr1 = ptr1->next;
            }
        }
    }
    return start3;
}

struct node *add_node(struct node *start, int n)
{
    struct node *ptr;
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = n;
    if (start == NULL)
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
    return start;
}

struct node *create_list(struct node *start)
{
    struct node *ptr, *new_node;
    int num;

    printf("Enter the Number: ");
    scanf("%d", &num);
    while (num != -1)
    {

        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (start == NULL)
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
        printf("Press -1 to Exit");
        printf("Enter the Number: ");
        scanf("%d", &num);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    if (start != NULL)
    {
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

struct node *return_last_addrs(struct node*start)
{
    struct node*ptr;
    ptr = start;
    while (ptr->next!=NULL)
    {
        ptr = ptr->next;
    }
    return ptr;
    
}