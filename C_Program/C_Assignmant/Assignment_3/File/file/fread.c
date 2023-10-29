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
	fp=fopen("stu","rb");
	if(fp==NULL)
	{
		printf("Unable to open file");
		exit(1);
	}
	printf("\nNAME\tROLL\tMARKS\n");
	while(fread(&student,sizeof(student),1,fp)==1)
	{
		printf("%s\t",student.name);
		printf("%d\t",student.roll);
		printf("%d\n",student.marks);
	}
	
	fclose(fp);
	return 0;
}
