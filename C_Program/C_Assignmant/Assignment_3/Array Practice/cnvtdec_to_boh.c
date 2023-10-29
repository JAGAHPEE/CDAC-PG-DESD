#include <stdio.h>
void convert(int,int);
int main()
{
    int num;
    int opt;
    printf("Choose option to convert Decimal to \nBinary:1 \nOctal:2 \nHexadeciaml:3\nEnter Option :\n");
    scanf("%d", &opt);
    printf("\nEnter Value: ");
    scanf("%d", &num);
    switch (opt)
    {
    case 1:
        convert(num, 2);
        break;
    case 2:
        convert(num, 8);
        break;
    case 3:
        convert(num, 16);
        break;
    default:
        printf("Invalid Options");
        break;
    }
}

void convert(int num,int b)
{
    char arr[10];
    int i=0,rem;
    while (num>0)
    {
        rem = num%b;
        num/=b;
        if(rem>9 && rem<16)
        {
            arr[i++]=rem-10+'A';
        }  
        else
        {
            arr[i++]= rem + '0';
        }
    }
    for(int j=i-1;j>=0;j--)
    {
        printf("%c",arr[j]);
    }
    
}