#include<stdio.h>
#include<stdlib.h>
struct records
{
	char name[10];
	int marks;
	int roll;
}student;

int main()
{
	int i,n;
	FILE *fp;
	fp=fopen("stu","wb");
	if(fp==NULL)
	{
		printf("Unable to open file");
		exit(1);
	}
	printf("Enter number of Records: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter Name:");
		scanf("%s",student.name);
		fflush(stdin);
		printf("Enter roll no.");
		scanf("%d",&student.roll);
		fflush(stdin);
		printf("Enter marks");
		scanf("%d",&student.marks);
		fflush(stdin);
		fwrite(&student,sizeof(student),1,fp);
		
	}
	fclose(fp);
	return 0;
}
