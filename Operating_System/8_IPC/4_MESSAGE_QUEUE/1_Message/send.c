#include<stdio.h>
#include<mqueue.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#define size 100
struct mq_attr queue_p;

int main()
{
 	mqd_t queue,queue_err;
	queue_p.mq_maxmsg = 4;
	queue_p.mq_msgsize = size;
	char name[size];
	queue = mq_open("/mq", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, &queue_p);
	scanf("%[^\n]s",name);
	queue_err = mq_send(queue,name,strlen(name),0);
	mq_close(queue);

}
