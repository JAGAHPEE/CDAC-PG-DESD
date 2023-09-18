#include<stdio.h>
int main()
{
    char ch;
    // ch = getchar();
    scanf("%c",&ch);
    // printf("%c",ch);
    if(ch >='a' && ch <='z')
        printf("\nlower case ASCII = %d",ch);
    if(ch >='A' && ch <='Z')
        printf("\nUppercase case ASCII = %d",ch);
    if(ch >='0' && ch <='9')
        printf("\nDigit ASCII = %d",ch);
}
