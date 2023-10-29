/*
Published by :- Sandesh Kale
Linkedin :-  https://www.linkedin.com/in/sandesh-s-kale
@github     :- JAGAHPEE
*/
/* 
Question 2: Implement a queue in C using a linked list. Write
functions for enqueue, dequeue, and display operations. Provide an
example of how to use the queue.
*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;

void enque(int);
int deque();
int is_empty();
void display();
int main()
{
    int option;
    while (1)
    {

        printf("\nPress 1 to Enque");
        printf("\nPress 2 to Deque");
        printf("\nPress 3 to Display");
        printf("\nPress 4 to Exit");
        printf("\nEnter Options: ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nEnter the Data to Insert:");
            scanf("%d", &option);
            enque(option);
            break;
        case 2:
            option = deque();
            if (option >= 0)
            {
                printf("\ndeleted Element: %d", option);
            }
            break;
        case 3:
            display();
            break;
            ;
        case 4:
            exit(1);
        default:
            break;
        }
    }
}
void enque(int data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (front == NULL && rear == NULL)
    {
        front = new_node;
    }
    else
    {
        rear->next = new_node;
    }
    rear = new_node;
}
int is_empty()
{
    if (front == NULL && rear == NULL)
    {
        return 1;
    }
    return 0;
}

int deque()
{
    if (!is_empty())
    {
        int x = front->data;
        struct node *temp;
        temp = front;
        if (front->next == NULL)
        {
            free(front);
            rear = front = NULL;
        }
        else
        {
            front = front->next;
            temp->next = NULL;
            free(temp);
        }
        return x;
    }
    else
    {
        printf("\nQueue id Empty");
        return -1;
    }
}
void display()
{
    if (!is_empty())
    {
        struct node *ptr = front;
        printf("\nList:");
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


/*
1. In a stack, the element that is removed first is:
ANS: Top ELement

2. Which data structure follows the Last-In-First-Out (LIFO) principle?
ANS: Stack

3. In a queue, the element that is removed first is:
ANS: Front Element

4. Queue follows the ________ principle.
ANS: FIFO (First In First Out)

5. What operation is used to add an element to the top of a stack?
ANS: Push

6. Which of the following data structures is not suitable for
ANS: Array

7. In a stack, which operation is used to retrieve the top element
without removing it?
ANS: PEEK

8. Which data structure is best suited for implementing an undo
feature in a text editor?
ANS: Stack

9. In a queue, which pointer indicates the front of the queue?
ANS: Front Pointer

10. Which of the following is a practical application of a queue data
structure?
ANS: Implementing a back button in a web browser



ANS
______________________________________________________________________
|1) A | 2) A | 3) A | 4) A | 5) B | 6) A | 7) C | 8) A | 9) C | 10) B |
|_____|______|______|______|______|______|______|______|______|_______|


*/