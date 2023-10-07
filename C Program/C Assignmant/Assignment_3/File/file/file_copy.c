#include<stdio.h>
int main()
{
	FILE *file;
	FILE *destination;
	file = fopen("a1.txt","r");
	destination = fopen("a5.txt","w");
	if(file==NULL)
	{
		perror("Unable to open file");
		return 0;
	}
	char ch;
	while((ch = fgetc(file))!=EOF)
	{
		printf("%c",ch);
		fputc(ch,destination);
	}
	fprintf(destination,"File fprintf");
	fclose(file);
	fclose(destination);
	

}
