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
    int fd = open("/usr/include/stdio.h", O_RDONLY);
    myqueue.mq_maxmsg = 4;
    myqueue.mq_msgsize = MAX;

    queue = mq_open(path, O_CREAT | O_RDWR, S_IRWXU, &myqueue);
    if (queue == -1)
    {
        perror("Unable to Create/Open Queue");
        exit(EXIT_FAILURE);
    }
    if (fd == -1)
    {
        perror("Unable to Open File");
        printf("Error No. %d\n", errno);
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < 4; i++)
    {
        if (read(fd, buff, sizeof(buff)) == -1)
        {
            perror("Unable to read from File");
            printf("Error No. %d\n", errno);
            exit(EXIT_FAILURE);
        }
        if (mq_send(queue, (const char *)buff, MAX, 0) == -1)
        {
            perror("Unable to Send in Queue");
            printf("Error No. %d\n", errno);
            exit(EXIT_FAILURE);
        }
        printf("\nFile Sent Successfully -> File Size: %ld\n", strlen(buff));
    }
    close(fd);
    mq_close(queue);
}
