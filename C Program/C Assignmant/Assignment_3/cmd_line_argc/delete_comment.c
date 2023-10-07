#include<stdio.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
	FILE *fp1,*fp2;
	if(argc!=3)
	{
		printf("Wrong number of argument");
		exit(1);
	}
	if((fp1=fopen(argv[1],"r"))==NULL)
	{
		printf("Unable to open source file");
		exit(1);
	}
	if((fp2=fopen(argv[2],"w"))==NULL)
	{
		printf("Unable to open destination file");
		exit(1);
	}
	int c1,c2,found = 'n';
	
	c1=fgetc(fp1);
	c2=fgetc(fp1);
	while(c2!=EOF)
	{
		if(c1=='/' && c2 == '*')
		{
			found = 'y';
		}
		if(found == 'n')
		{
			fputc(c1,fp2);
		}
		if(c1=='*' && c2 == '/')
		{
			found = 'n';
			c2 = fgetc(fp1);
		}
		c1=c2;
		
		c2 = fgetc(fp1);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
	
	
}
