#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

struct arithmatic
{
	int *a;
	int *b;
	int *sum;
};

void *operation(void *data)
{
	struct arithmatic *value = (struct arithmatic*)data;
	int sum;
	int a,b;
	a = *value->a;
	b = *value->b;
	printf("Addition: %d",a + b);

}


int main()
{
	pthread_t id;
	int a,b;
	struct arithmatic value;
	printf("\nEnter the First Number: ");
	scanf("%d",&a);
	printf("\nEnter the Second Number: ");
	scanf("%d",&b);	
 
        value.a = &a;
        value.b = &b;

	// Creating a Thread	
	pthread_create(&id,NULL,operation,(void*)&value);
	pthread_join(id,NULL);
	//printf("Sum : %d\n",value );
	return 0;
}
