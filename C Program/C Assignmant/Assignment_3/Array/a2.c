#include<stdio.h>
int main()
{
    int n;
    printf("Enter the No. of Elements:");
    scanf("%d",&n);
    char text[n];
    for(int i=0;i<n;i++)
    {
        // scanf("%c",&text[i]);
        text[i] = getchar();
    }
    int sp,letter,tab,dgt;
    sp=letter=tab=dgt=0;
    for(int j=0;j<n;j++)
    {
        // if(text[j]==' '&& text[j+1]==' ')
        // {
        //     tab++;
        // }
        if(text[j]==9)
        {
            tab++;
        }
        else if ((text[j]>='a'&& text[j]<='z')||(text[j]>='A'&& text[j]<='Z'))
        {
            letter++;
        }
        else if (text[j]==' ')
        {
            sp++;
        }
        else if (text[j]>='0'&& text[j]<='9')
        {
            dgt++;
        }
        
        
    }
    for(int i=0;i<n;i++)
    {
        printf("%d ",text[i]);
    }
    printf("\nSpace : %d \n Letter : %d \n Tabs: %d \nDigits : %d",sp,letter,tab,dgt);
}