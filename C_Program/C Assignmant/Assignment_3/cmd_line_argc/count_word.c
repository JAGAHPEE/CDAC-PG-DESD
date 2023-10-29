#include<stdio.h>
#include<stdlib.h>
int is_end(int);
int main(int argc,char *argv[])
{
	char line[81];
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
	}
	while((fgets(line,81,fp))!=NULL)
	{
		for(i=0;line[i]!='\0';i++)
		{
			if(is_end(line[i]))
			{
			count++;
			}
		}
	}
	printf("%d",count);
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
