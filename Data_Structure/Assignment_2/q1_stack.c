/* Question : 1 Implement a stack in C using an array. Write functions
for push, pop, and display operations. Provide an example of how to
use the stack.
*/

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int *a;
    int size;
    int tos;
} std;

char input[] = "(a+b{c+d}*a)";
int is_empty();
int is_full();
int peek();
int pop();
void display();
void insert();

int main()
{
    std.tos = -1;
    int i = 0;
    int length;
    while (input[i] != '\0')
    {
        length++;
        i++;
    }
    std.size = length;
    std.a = (int *)malloc(sizeof(int) * std.size);
    printf("length: %d", length);
    int flag = 0;
    for (i = 0; input[i] != '\0'; i++)
    {
        char ch = input[i];
        switch (ch)
        {
        case '(':
        case '[':
        case '{':
            insert(ch);
            break;
        case ']':
        case ')':
        case '}':
            if ((ch == ')' && peek() == '(') || (ch == '}' && peek() == '{') || (ch == ']' && peek() == '['))
            {
                pop();
            }
            else
            {
                flag = 1;
            }
        }
        if (flag == 1)
        {
            break;
            ;
        }
    }
    if (flag == 0 && i == length)
    {
        printf("\nBalanced");
    }
    else
    {
        printf("\nNot Balanced");
    }
}
int is_empty()
{
    if (std.tos == -1)
    {
        return 1;
    }
    return 0;
}
int is_full()
{
    if (std.tos == std.size - 1)
    {
        return 1;
    }
    return 0;
}

void insert(int data)
{
    if (!is_full())
    {
        std.a[++std.tos] = data;
    }
    else
    {
        printf("\nStack is Full");
    }
}
void display()
{
    if (!is_empty())
    {
        for (int i = 0; i <= std.tos; i++)
        {
            printf("%d ", std.a[i]);
        }
    }
    else
    {
        printf("\nStack is Empty");
    }
}
int pop()
{
    if (!is_empty())
    {
        int x = std.a[std.tos--];
        return x;
    }
    else
    {
        printf("\nStack is EMpty");
    }
    return -1;
}

int peek()
{
    if (!is_empty())
    {
        return std.a[std.tos];
    }
    return -1;
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