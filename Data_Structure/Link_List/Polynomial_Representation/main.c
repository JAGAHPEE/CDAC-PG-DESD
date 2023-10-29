/*
Published by :- Sandesh Kale
Linkedin :-  https://www.linkedin.com/in/sandesh-s-kale
@github     :- JAGAHPEE
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    int coff;
    struct node *next;
};
struct node *poly1 = NULL;
struct node *poly2 = NULL;
struct node *poly3 = NULL;
struct node *poly4 = NULL;
struct node *last3 = NULL;

struct node *create_poly(struct node *);
struct node *display_poly(struct node *);
struct node *sum_poly(struct node *,struct node*);
struct node *add_node(struct node *,int,int);
int main()
{
    int option;
    while (1)
    {
        printf("\nPress 1 to Create Poly 1 ");
        printf("\nPress 2 to Create Poly 2 ");
        printf("\nPress 3 to Display Poly 1 ");
        printf("\nPress 4 to Display Poly 2 ");
        printf("\nPress 5 to Sum ");
        printf("\nPress 6 to Display Sum ");
        printf("\nPress 7 to EXIT");
        // printf("\nPress to ");
        printf("\nEnter Option: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            poly1 = create_poly(poly1);
            break;
        case 2:
            poly2 = create_poly(poly2);
            break;
        case 3:
            poly1 = display_poly(poly1);
            break;
        case 4:
            poly2 = display_poly(poly2);
            break;
        case 5:
            poly3 = sum_poly(poly1,poly2);
            break;
        case 6:
            poly3 = display_poly(poly3);
            break;
        case 7:
            return 0;
        default:
            printf("\nInvalid Options");
            break;
        }
    }
}
struct node *create_poly(struct node *start)
{
    struct node *ptr, *new_node;
    int n, c;
    printf("\nEnter Number: ");
    scanf("%d", &n);
    printf("\nEnter Cofficient: ");
    scanf("%d", &c);
    while (n!=-1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->num = n;
        new_node->coff = c;
        if (start == NULL)
        {
            new_node = (struct node *)malloc(sizeof(struct node));
            new_node->num = n;
            new_node->coff = c;
            new_node->next = NULL;
            start = new_node;
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
        printf("Press -1 to end: ");
        printf("\nEnter Number: ");
        scanf("%d", &n);
        if (n == -1)
        {
            break;
        }
        printf("\nEnter Cofficient: ");
        scanf("%d", &c);
    }
    return start;
}


struct node*add_node(struct node*start,int n,int c)
{
    struct node *ptr;
    struct node*new_node;
    new_node=(struct node*)malloc(sizeof(struct node));
    new_node->num = n;
    new_node->coff = c;
    if(start==NULL)
    {
        start = new_node;
        new_node->next = NULL;
    }
    else
    {
        ptr = start;
        while(ptr->next!=NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->next=NULL;
    }
    return start;
}

struct node *display_poly(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (ptr != NULL)
    {
        printf("\nPolynomial Expression : ");
        while (ptr != NULL)
        {
            printf("%dX^%d ", ptr->num, ptr->coff);
            ptr = ptr->next;
        }
    }
    else
    {
        printf("\nPloynomial Not Inserted");
    }
    return start;
}

struct node*sum_poly(struct node*start1,struct node*start2)
{
    struct node*ptr1,*ptr2,*poly3;
    int sum;
    ptr1=start1;
    ptr2=start2;
    while(ptr1!=NULL && ptr2!=NULL)
    {
        if(ptr1->coff == ptr2->coff)
        {
            sum = ptr1->num+ptr2->num;
            poly3 = add_node(poly3,sum,ptr1->coff);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        else if(ptr1->coff > ptr2->coff)
        {
            poly3 = add_node(poly3,ptr1->num,ptr1->coff);
            ptr1 = ptr1->next;
        }
        else if(ptr1->coff < ptr2->coff)
        {
            poly3 = add_node(poly3,ptr2->num,ptr2->coff);
            ptr2 = ptr2->next;
        }
    }
    if(ptr1==NULL)
    {
        while(ptr2!=NULL)
        {
            poly3 = add_node(poly3,ptr2->num,ptr2->coff);
            ptr2 = ptr2->next;
        }
    }
    if(ptr2==NULL)
    {
        while(ptr1!=NULL)
        {
            poly3 = add_node(poly3,ptr1->num,ptr1->coff);
            ptr1 = ptr1->next;
        }
    }
    return poly3;
}