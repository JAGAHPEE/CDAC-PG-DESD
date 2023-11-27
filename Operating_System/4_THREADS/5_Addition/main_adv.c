#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
struct value
{
	int a;
	int b;
	int c;
};
void addition(void *data)
{
	struct value *v = (struct value *)data;
	int sum = v->a + v->b;
	printf("Sum of %d and %d : %d\n",v->a,v->b,sum);
}
int main(int argc, char *argv[])
{
	struct value v;
	pthread_t id;
	v.a = 10;
	v.b = 20;
	pthread_create(&id,NULL,(void *)addition,(void*)&v);
	pthread_join(id,NULL);
	return 0;

}
