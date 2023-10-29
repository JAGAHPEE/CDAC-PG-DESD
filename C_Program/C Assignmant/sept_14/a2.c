#include<stdio.h>
#include<ctype.h>
int main()
{
char a;
printf("Enter Value : ");
scanf("%c",&a);
if(isalpha(a))
{
    printf("Character");
    printf("\nASCII = %d\n",a);
}
if(isdigit(a))
{
    printf("Digit");
    printf("\nASCII = %d\n",a);
}
// if(((a>96)&&(a<123))||((a>64)&&(a<91)))
// {
//     printf("Character");
//     printf("\nASCII = %d\n",a);

// }
// else if((a>47)&&(a<58))
// {
//     printf("Digit");
//     printf("\nASCII = %d\n",a);
// }
}
