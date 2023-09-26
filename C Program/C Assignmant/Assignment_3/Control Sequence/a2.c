#include <stdio.h>
int main()
{
    char ch;
    scanf("%c", &ch);
    if (ch == 'a' || ch == 'A')
    {
        printf("A for apple");
    }
    else if (ch == 'b' || ch == 'B')
    {
        printf("B for Ball");
    }
    else if (ch == 'd' || ch == 'D')
    {
        printf("D for Dog");
    }
    else if (ch == 'f' || ch == 'F')
    {
        printf("F for Fan");
    }
    else
    {
        printf("Character is not in the range");
    }
    switch (ch)
    {
    case 'a':
        printf("A for apple");
        break;
    case 'A':
        printf("A for apple");
        break;
    case 'B':
        printf("B for Ball");
        break;
    case 'b':
        printf("B for Ball");
        break;
    case 'd':
        printf("D for Dog");
        break;
    case 'D':
        printf("D for Dog");
        break;
    case 'f':
        printf("F for Fan");
        break;
    case 'F':
        printf("F for Fan");
        break;
    default:
        printf("Character is not in the Range");
        break;
    }
}