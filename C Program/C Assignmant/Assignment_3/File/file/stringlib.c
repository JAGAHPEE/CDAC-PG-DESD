#include<stdio.h>
#include"stringlib.h"

// To get String INPUTS
char *gets(char *s1)
{
	if(s1 == NULL)
	{
		return NULL;
	}
	char *ptr;
	ptr = s1;
	// To store the String
	for(int i=0;i<100;i++)
	{
		scanf("%c",s1);
		// If Enter is Pressed
		if(*s1==10)
		{
			// Assign Null to the last of String
			s1 = NULL;
			break;
		}
		s1++;
		//printf(" %d ",i);
	}
	return ptr;
}

// To get string length
int strlength(char s1[])
{
	unsigned int i=0;
	while(s1[i]!=10)
	{
		i++;
	}
	return i;
}


// To copy string to another string
char *copys(char *source,char *destination)
{	
	char *ptr;
	ptr = destination;
	while(*source !=10)
	{
		*destination= *source;
		destination++;
		source++;
	}
	*destination =10;
	return ptr;
}

// To reverse the String 
char *strreverse(char *s1)
{
	char *ptr = s1;
	unsigned int index=0;
	index = strlength(s1);
	int j=index;
	//index-=1;	
	//printf("%d",index);
	for(int i=0;i<j;i++,j--)
	{
		char temp = s1[i];
		s1[i]=s1[j-1];
		s1[j-1] = temp; 
	}
	s1[index+1]='\0';
	return ptr;
}

// To compare the String
int strcompare(char *s1,char *s2)
{
	short int check = 1;
	if(strlength(s1)!=strlength(s2))
	{
		return check;
	}
	while(*s1 !='\0' || *s2 != '\0')
	{
		if(*s1 != *s2)
		{
			check=1;
			break;
		}
		else
		{
			check = 0 ;
		}
		s1++;
		s2++;
	}
return check;
}





