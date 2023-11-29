#include<stdio.h>
#include<mqueue.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#define size 100
struct mq_attr queue_p;

int main()
{	char name[100];
 	mqd_t queue,queue_err;
	queue_p.mq_maxmsg = 4;
	queue_p.mq_msgsize = size;
	queue = mq_open("/mq", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, &queue_p);
	queue_err = mq_receive(queue,name,100,0);
	name[strlen(name)]= '/0';
	printf("%s\n",name);
	mq_close(queue);
}
