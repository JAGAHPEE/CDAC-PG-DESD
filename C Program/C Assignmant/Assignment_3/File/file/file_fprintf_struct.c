#include<stdio.h>
#include"stringlib.h"
#define pf printf("Enter File Name:")
struct records
{
	char name[20];
	int marks;
}student;
int main()
{
	char ch;
	int c;
	FILE *file;
	FILE *destination;
	char file_name[10];
	pf;
	fscanf(stdin,"%s",file_name);
	file = fopen(file_name,"w+");
	//file = fopen("a1.txt","w+");
	pf;
	fscanf(stdin,"%s",file_name);
	destination = fopen(file_name,"w");
	if(file==NULL)
	{
		perror("Unable to open file");
		return -1;
	}
	printf("Enter Number of Records");
	int n;
	fscanf(stdin,"%d",&n);
	fprintf(file,"S.No.| %-10s| %-5s|\n","Name","Marks");
	for(int i=0;i<n;i++)
	{
		printf("Enter %d Name :",i+1);
		fscanf(stdin,"%s",student.name);
		//gets(student.name);
		//scanf("%d",&c);
		printf("Enter %d Marks :",i+1);
		fscanf(stdin,"%d",&student.marks);
		fprintf(file,"%-4d | %-10s| %-4d |\n",i+1,student.name,student.marks);
	}
	char str[100];
	rewind(file);
	while((ch=fgetc(file))!=EOF)
	{
		fputc(ch,destination);
	}
	fclose(file);
	fclose(destination);
}
