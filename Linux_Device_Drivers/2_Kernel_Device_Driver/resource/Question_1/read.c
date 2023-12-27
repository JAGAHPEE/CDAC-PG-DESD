#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include"headers.h"
#include<string.h>

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

    ssize_t bytes = read(fd,&data,sizeof(data));
    if(bytes<0)
    {
        printf("Unable to Read to File\n");
    }
    printf("Data from Kernel: %d %s %d",data.size,data.buff,data.r_w);
    
    close(fd);
    return 0;
}