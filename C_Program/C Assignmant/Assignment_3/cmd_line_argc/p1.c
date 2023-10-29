#include<stdio.h>
void main(int argc , char argv[])
{
	int i;
	printf("Number of command line: %d",argc);
	for(i=0;i<argc;i++)
	{
		printf("%c",argv);
	}
}
