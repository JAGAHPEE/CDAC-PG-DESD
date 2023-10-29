#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *fp;
	fp = fopen("f.txt","a");
	if(fp = NULL)
	{
		perror("Unable to open file");
		exit(1);
	}	
	char ch;
	while((ch=getchar())!=EOF)
	{
		fputc(ch,fp);
	}
	fclose(fp);
	return 0;
	
}

