#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *start = NULL;
struct node *insert_beg(struct node *);
struct node *insert_last(struct node *);
struct node *display(struct node *);
struct node *insert_after(struct node *);
struct node *insert_before(struct node *start);
struct node *delete_beg(struct node *start);
struct node *delete_after(struct node *start);
struct node *delete_last(struct node *start);
struct node *delete_before(struct node *start);
struct node *delete_node(struct node *start);
struct node *display_reverse(struct node *start);
int main()
{
    int option;
    while (1)
    {

        printf("\nPress 1 to Insert at Beginning");
        printf("\nPress 2 to Display");
        printf("\nPress 3 to Insert at End");
        printf("\nPress 4 to Insert after the Given Node");
        printf("\nPress 5 to Insert Before the Given Node");
        printf("\nPress 6 to Delete First");
        printf("\nPress 7 to Delete after a given node");
        printf("\nPress 8 to Delete Last");
        printf("\nPress 9 to Delete a given node");
         printf("\nPress 10 to Delete a given node");
        printf("\nPress 11 to Display in Reverse Order");
        printf("\nEnter the Options:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = insert_beg(start);
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_last(start);
            break;
        case 4:
            start = insert_after(start);
            break;
        case 5:
            start = insert_before(start);
            break;
        case 6:
            start = delete_beg(start);
            break;
        case 7:
            start = delete_after(start);
            break;
        case 8:
            start = delete_last(start);
            break;
        case 9:
            start = delete_node(start);
            break;
        case 10:
            start = delete_before(start);
            break;
	 case 10:
	    start = display_reverse(start);
	    break;
        default:
            return 0;
            break;
        }
    }
}

// To Insert at the Beginning
struct node *insert_beg(struct node *start)
{
    struct node *new_node;
    new_node = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the Number: ");
    int num;
    scanf("%d", &num);
    new_node->prev = NULL;
    new_node->data = num;
    new_node->next = start;
    if (start != NULL)
    {
        start->prev = new_node;
    }
    start = new_node;
    return start;
}

// To Display
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (ptr != NULL)
    {
        printf("List: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
    else
    {
        printf("\nList is Empty");
    }
    return start;
}

// To Insert at the End
struct node *insert_last(struct node *start)
{
    struct node *new_node, *curr;
    printf("\nEnter the Number: ");
    int num;
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = num;
    new_node->next = NULL;
    curr = start;
    if (start == NULL)
    {
        new_node->prev = NULL;
        start = new_node;
        return start;
    }
    else
    {
        curr = start;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        new_node->prev = curr;
        curr->next = new_node;
        new_node->next = NULL;
    }
    return start;
}

// To Insert after given Node
struct node *insert_after(struct node *start)
{
    struct node *new_node, *ptr;
    int num, s;
    printf("\nEnter the Number to Insert: ");
    scanf("%d", &num);
    printf("\nEnter the Node to Insert after a given Node: ");
    scanf("%d", &s);
    ptr = start;
    if (start != NULL)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        ptr = start;
        while (ptr != NULL && ptr->data != s)
        {
            ptr = ptr->next;
        }
        if (ptr != NULL)
        {
            new_node->prev = ptr;
            new_node->next = ptr->next;
            ptr->next = new_node;
            if (ptr->next != NULL)
            {
                ptr->next->prev = new_node;
            }
        }
        else
        {
            printf("\nElement Not Found");
        }
    }
    else
    {
        printf("\nList is Empty");
    }
    return start;
}

// To Insert before the Given Node
struct node *insert_before(struct node *start)
{
    struct node *new_node, *ptr;
    int num, s;
    printf("\nEnter the Number to Insert: ");
    scanf("%d", &num);
    printf("\nEnter the Node to Insert after a given Node: ");
    scanf("%d", &s);
    if (ptr != NULL)
    {
        ptr = start;
        while (ptr != NULL && ptr->data != s)
        {
            ptr = ptr->next;
        }
        if (ptr != NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->data = num;
            new_node->prev = ptr->prev;
            new_node->next = ptr;
            if (ptr->prev != NULL)
            {
                ptr->prev->next = new_node;
            }
            else
            {
                start = new_node;
            }
            ptr->prev = new_node;
        }
        else
        {
            printf("\nElement Not Found");
        }
    }
    else
    {
        printf("List is Empty");
    }
    return start;
}

// To Delete First Element
struct node *delete_beg(struct node *start)
{
    struct node *ptr;
    if (start != NULL)
    {

        ptr = (struct node *)malloc(sizeof(struct node));
        ptr = start;
        free(ptr);
        start = start->next;
        if (start != NULL)
        {
            start->prev = NULL;
        }
    }
    else
    {
        printf("List is Empty");
    }
    return start;
}
// To Delete after a Given Node
struct node *delete_after(struct node *start)
{
    struct node *ptr, *temp;
    ptr = start;
    if (ptr != NULL)
    {
        int num, s;
        printf("\nEnter the Node to Delete after a given Node: ");
        scanf("%d", &s);
        while (ptr->next != NULL && ptr->data != s)
        {
            ptr = ptr->next;
        }
        if (ptr->next != NULL)
        {
            // temp = (struct node *)malloc(sizeof(struct node));
            temp = ptr->next;
            if (temp->next != NULL)
            {

                ptr->next = temp->next;
                temp->next->prev = ptr;
            }
            else
            {
                ptr->next = NULL;
            }
            temp->prev = NULL;
            free(temp);
        }
        else
        {
            printf("Not Found");
        }
    }
    else
    {
        printf("List is Empty");
    }
    return start;
}

// To Delete a given node
struct node *delete_node(struct node *start)
{
    int s;
    printf("\nEnter the node to delete: ");
    scanf("%d", &s);
    struct node *curr, *temp;
    curr = start;
    if (curr != NULL)
    {
        while (curr != NULL && curr->data != s)
        {
            curr = curr->next;
        }
        if (curr != NULL)
        {
            if (curr->next != NULL)
            {
                curr->next->prev = curr->prev;
            }
            if (curr->prev != NULL)
            {
                curr->prev->next = curr->next;
            }
            else
            {
                start = curr->next;
            }
            free(curr);
        }
        else
        {
            printf("Element Not Found");
        }
    }
    else
    {
        printf("\nList is Empty");
    }
    return start;
}

// To Delete last element
struct node *delete_last(struct node *start)
{
    struct node *curr,*temp;
    curr = start;
    if (curr != NULL)
    {
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        if (curr->prev == NULL)
        {
            start = NULL;
            free(curr);
        }
        else
        {
            temp = curr;
            curr = curr->prev;
            curr->next->prev = NULL;
            curr->next = NULL;
            free(temp);
        }
        
    }
    else
    {
        printf("\nList is Empty");
    }
    return start;
}
struct node *display_reverse(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (ptr != NULL)
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        printf("Reverse List: ");
        while (ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr = ptr->prev;
        }
    }
    else
    {
        printf("List is EMpty");
    }
    return start;
}

// To delete a node before a given node
struct node *delete_before(struct node *start)
{
    if (start != NULL)
    {
        int s;
        printf("\nEnter the Node after which the node to be deleted: ");
        scanf("%d", &s);
        struct node *ptr, *temp;
        ptr = start;
        while (ptr != NULL && ptr->data != s)
        {
            ptr = ptr->next;
        }
        if (ptr->data == s)
        {
            if (ptr->prev != NULL)
            {
                temp = ptr->prev;
                temp->next = NULL;
                if (temp->prev == NULL)
                {
                    start = ptr;
                    start->prev = NULL;
                }
                else
                {
                    ptr->prev = temp->prev;
                    temp->prev->next = ptr;
                    temp->prev = NULL;
                }
                printf("\nNode to be Deleted: %d", temp->data);
                free(temp);
                temp = NULL;
            }
            else
            {
                printf("\nNo Previous node is Present");
            }
        }
        else
        {
            printf("\nNode not Found");
        }
    }
    else
    {
        printf("\nList is Empty");
    }
    return start;
}
