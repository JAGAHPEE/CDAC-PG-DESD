#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MAX 8192 // Max size of queue default
char path[] = "/library_queue";
struct mq_attr myqueue;
unsigned char buff[MAX];
int main()
{
    mqd_t queue;

    myqueue.mq_maxmsg = 4;
    myqueue.mq_msgsize = MAX;

    queue = mq_open(path, O_CREAT | O_RDWR, S_IRWXU, &myqueue);
    if (queue == -1)
    {
        perror("Unable to Create/Open Queue");
        exit(EXIT_FAILURE);
    }
    int count = 0, j = 0;
    for (int i = 0; i < 4; i++)
    {
        ssize_t q = mq_receive(queue, buff, MAX, 0);
        if (queue == -1)
        {
            perror("Unable to Read from Queue");
            printf("Error No. %d\n", errno);
            exit(EXIT_FAILURE);
        }
        int length = strlen(buff);
        for (j = 0; j <= length; j++)
        {
            if (buff[j] == 's')
                count++;
        }
    }
    printf("Count : %d", count);
    return 0;
}
