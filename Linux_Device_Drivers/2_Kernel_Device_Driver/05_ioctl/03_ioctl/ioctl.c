#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/ioctl.h>
#include<stdlib.h>

#include"headers.h"

#define FILE_NAME "/dev/Char_device_file"
int main()
{
    int fd = open(FILE_NAME,O_RDWR);
    if(fd<0)
    {
        printf("Unable to Open File\n");
        return -1;
    }
    struct my_data data;
    if(ioctl(fd,GETSTATS,&data))
    {

        printf("IOCTL Error\n");
    }
    printf("Status : %d",data.r_w);
    close(fd);

    return 0;
}