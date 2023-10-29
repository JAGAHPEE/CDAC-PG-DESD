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

void sort_name(struct employee emp[]);
void sort_dob(struct employee emp[]);
void sort_doj(struct employee emp[]);
void sort_salary(struct employee emp[]);
void display(struct employee emp[]);
int datecmp(struct date date1,struct date date2);

int main()
{
	FILE *fp;
	fp=fopen("data","wb");
	if(fp==NULL)
	{
		printf("Unable to open file");
		exit(1);
	}
	struct employee emp[N];
	int i,choice;
	for(i=0;i<N;i++)
	{
		printf("Enter Name: ");
		fscanf(stdin,"%s",emp[i].name);
		fflush(stdin);
		printf("\nEnter Date of Birth (DD/MM/YY): ");
		fflush(stdin);
		scanf("%d/%d/%d",&emp[i].dob.day,&emp[i].dob.month,&emp[i].dob.year);
		printf("\nEnter Date of Joining (DD/MM/YY): ");
		fflush(stdin);
		scanf("%d/%d/%d",&emp[i].doj.day,&emp[i].doj.month,&emp[i].doj.year);
		fflush(stdin);
		printf("\nEnter Salary: ");
		scanf("%d",&emp[i].salary);
		printf("\n");
		fwrite(&emp,sizeof(emp),1,fp);
	}
		fclose(fp);
	while(1)
	{
		printf("1. Sort by name\n");
		printf("2. Sort by dob\n");
		printf("3. Sort by doj\n");
		printf("4. Sort by salary\n");
		printf("5. Exit\n");
		printf("Enter your Choice:-");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				sort_name(emp);
				break;
			case 2:
				sort_dob(emp);
				break;
			case 3:
				sort_doj(emp);
				break;
			case 4:
				sort_salary(emp);
				break;
			case 5:
				exit(1);
			default:
				printf("Invalid Choice:");
				break;
		}
		printf("\n");
		display(emp);
	}
}

void display(struct employee e[])
{
	for(int i=0;i<N;i++)
	{
		printf("%d. %-10s\t",i+1,e[i].name);
		printf("%d/%d/%d\t",e[i].dob.day,e[i].dob.month,e[i].dob.year);
		printf("%d/%d/%d\t",e[i].doj.day,e[i].doj.month,e[i].doj.year);
		printf("\n");
	}
		printf("\n");
}
void sort_name(struct employee emp[])
{
	struct employee temp;
	int i,j;
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			//printf("%d",strcompare(emp[i].name,emp[j].name));
			if(strcmp(emp[i].name,emp[j].name)<0)
			{
				temp = emp[i];
				emp[i] = emp[j];
				emp[j] = temp;
			}
			//printf("%d",strcmp(emp[i].name,emp[j].name));
		}
	}	
	
}
void sort_dob(struct employee emp[])
{
	struct employee temp;
	int i,j;
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(datecmp(emp[i].dob,emp[j].dob) > 0)
			{
				temp = emp[i];
				emp[i] = emp[j];
				emp[j] = temp;
			}
		}
	}
}
void sort_doj(struct employee emp[])
{
	struct employee temp;
		int i,j;
		for(i=0;i<N-1;i++)
		{
			for(j=i+1;j<N;j++)
			{
				if(datecmp(emp[i].doj,emp[j].doj) > 0)
				{
					temp = emp[i];
					emp[i] = emp[j];
					emp[j] = temp;
				}
			}
		}
}
void sort_salary(struct employee emp[])
{
	struct employee temp;
	int i,j;
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if(emp[i].salary > emp[j].salary)
			{
				temp = emp[i];
				emp[i] = emp[j];
				emp[j] = temp;
			}
		}
	}	
}

int datecmp(struct date date1,struct date date2)
{
	if(date1.year > date2.year)
	{
		return 1;
	}
	if(date1.year < date2.year)
	{
		return -1;
	}
	if(date1.month > date2.month)
	{
		return 1;
	}
	if(date1.month < date2.month)
	{
		return -1;
	}
	if(date1.day > date2.day)
	{
		return 1;
	}
	if(date1.day < date2.day)
	{
		return -1;
	} 
	
}
