#include<stdio.h>
#include<stdlib.h>
/*
that is that
int main(int argc,char *argv[])
{
	FILE *source,*destination;
	int c;
	if(argc!=3)
	{
		printf("Wrong number of argument");
		exit(1);
	}
	if((source=fopen(argv[1],"r"))==NULL)
	{
		printf("Unable to open source file");
		exit(1);
	}
	if((destination=fopen(argv[2],"w"))==NULL)
	{
		printf("Unable to open destination file");
		exit(1);
	}
	while((c=fgetc(source))!=EOF)
	{
		fputc(c,destination);
	}
	fclose(source);
	fclose(destination);
	
	
}
*/
if (argc!=3)
	{
		printf("Wrong number of argument");
		exit(1);
	}
	if((source=fopen(argv[1],"r"))==NULL)
	{
		printf("Unable to open source file");
		exit(1);
	}
	if((destination=fopen(argv[2],"w"))==NULL)
	{
		printf("Unable to open destination file");
		exit(1);
	}
	while((c=fgetc(source))!=EOF)
	{
		fputc(c,destination);
	}
	fclose(source);
	fclose(destination);


