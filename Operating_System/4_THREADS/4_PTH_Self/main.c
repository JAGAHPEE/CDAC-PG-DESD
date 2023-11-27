#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
struct value
{
	int *a;
	int *b;
};
void *pf(void *data)
{

	struct value *v = (struct value*)data;
	int *a = v->a;
	int *b = v->b;	
	printf("Inside Thread\n");
	printf("\na = %d",*a);
	printf("\nb = %d",*b);
	pthread_t thread_id;
	thread_id = pthread_self();
	printf("\nThread ID: %ld",thread_id);
}
int main()
{
	pthread_t id1;
	int a =10;
	int b = 20;
	struct value v;
	v.a = &a;
	v.b = &b;
	//pthread_create(&id1,NULL,pf,(void*)&v);
	pthread_create(&id1,NULL,pf,(void*)&v);
	pthread_join(id1,NULL);
	return 0;
}
