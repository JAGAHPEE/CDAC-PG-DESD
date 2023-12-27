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
    printf("Enter tht String: ");
    scanf("%[^\n]s",data.buff);

    data.size = strlen(data.buff);
    
    ssize_t bytes = write(fd,&data,sizeof(data));
    if(bytes<0)
    {
        printf("Unable to Write to File\n");
    }
    printf("Data Sent\n");
    close(fd);

    return 0;
}