#include<stdio.h>
char to_lower(char p)
{
    if(p >= 65 && p <= 90)
    {
    return p + 32;
    }
    else{
        return p;
    }
}
int main()
{
    char ch;
    scanf("%c",&ch);
    // ch = ch+32;
    char lower = to_lower(ch);
    printf("%c",lower);
    return 0;
}