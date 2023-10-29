#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"stringlib.h"
#define N 2
struct date
{
	int day;
	int month;
	int year;
};

struct employee
{
	char name[10];
	struct date dob;
	struct date doj;
	int salary;
};
int main()
{
	FILE *fp;
	fp=fopen("data","rb");
	if(fp==NULL)
	{
		printf("Unable to open file");
		exit(1);
	}
	struct employee e;
	printf("\nNAME\tDOB\t\tDOJ\t\tSALARY\n");
	while(fread(&e,sizeof(e),1,fp)==1)
	{
		printf("%s\t",e.name);
		//printf("%d/%d/%d\t",e.dob.day,e.dob.month,e.dob.year);
		//printf("%d/%d/%d\t",e.doj.day,e.doj.month,e.doj.year);
		printf("%d\n",e.salary);
		
	}
	fclose(fp);
	return 0;



}

