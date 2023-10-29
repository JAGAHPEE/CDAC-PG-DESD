#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int display(char line[],char wordtext[]);
int is_end(int);
int main(int argc,char *argv[])
{
	char line[81];
	int total =0;
	int i=0,count=0; 
	FILE *fp;
	if(argc!=2)
	{
		printf("wrong Number of Argument");
		exit(1);
	}
	if((fp=fopen(argv[1],"r"))==NULL)
	{
	
		printf("Unable to open file");
		exit(1);
	}while((fgets(line,81,fp))!=NULL)
	{
		total = total+display(line,"that");
	}
	printf("Number of time if Occured: %d",total);
	return 0;
	
}


int display(char line[],char wordtext[])
{
	int i,j,k,len;
	char str[80];
	int count=0;
	len =strlen(wordtext);
	for(i=0;line[i]!='\0';i++)
	{
		k=0;
		if(is_end(line[i-1]) && is_end(line[i+len]))
		{
		 
			for(k=0,j=i;k < len ; j++,k++)
			{
				str[k] = line[j];
			}
			str[k] = '\0';
			if(strcmp(str,wordtext) ==0)
			{
				count++;
			}
		}
		
		
		
	}
	if(count >0)
	{
		printf("%s",line);
		printf("COunt : %d",count);
	}
	return count;
}
	
int is_end(int ch)
{
	switch(ch)
	{ 	
		case '\n':
		case '\t':
		case ' ':
		case ',':
		case '.':
		case ';':
		case ':':
		case '-':
			return 1;
	}
	return 0;
}
