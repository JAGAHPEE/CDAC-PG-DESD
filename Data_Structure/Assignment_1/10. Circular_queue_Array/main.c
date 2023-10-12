#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void insert(int);
void display();
int delete();
int peek();

int main()
{
    int option;
    while (1)
    {

        printf("\nPress 1 to Insert");
        printf("\nPress 2 to Display Queue");
        printf("\nPress 3 to Display Peek Element");
        printf("\nPress 4 to Delete");
        printf("\nEnter the Options:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("\nEnter Data to Insert:");
            scanf("%d", &option);
            insert(option);
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\nPeek Element:%d\n", peek());
            break;
        case 4:
            option = delete ();
            if (option > 0)
            {
                printf("Deleted Element:%d", option);
            }
            break;
        default:
            return 0;
            break;
        }
    }
}
void insert(int n)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        queue[rear] = n;
    }
    else if (rear == MAX - 1 && front == 0)
    {
        printf("\nOverflow");
    }
    else if (rear == MAX - 1 && front != 0)
    {
        rear = 0;
        queue[rear] = n;
    }
    else
    {
        rear++;
        queue[rear] = n;
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Empty");
        return;
    }
    // else{
    //     if(front<rear)
    //     {
    //         for(int i=front;i<=rear;i++)
    //         {
    //             printf("%d ",queue[i]);
    //         }
    //     }
    // else
    //{
    int i;
    for (i = front; i != rear; i = (i + 1) % MAX)
    {
        printf("%d ", queue[i]);
    }
    printf("%d ", queue[i]);
    //     }
    // }
}
int delete()
{
    int val;
    if (front == -1 && rear == -1)
    {
        printf("Underflow");
        return -1;
    }
    val = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        if (front == MAX - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
    }
    return val;
}
int peek()
{
    if (front == -1 && rear == -1)
    {
        printf("Underflow");
        return -1;
    }
    else
    {
        return queue[rear];
    }
}