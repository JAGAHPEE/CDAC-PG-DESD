/*
 * Published by : Sandesh Kale
 * LinkedIn     : https://www.linkedin.com/in/sandesh-s-kale
 * github       : https://github.com/JAGAHPEE
*/

/*User Space Application*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int8_t write_buf[1024];
int8_t read_buf[1024];

int main(int argc,char*argv[])
{
	if(argc<2)
	{
		printf("Provide File Name\n");
		return -1;
	}
        int fd;
        char option;
        /**fd = open(argv[1], O_RDWR);
        if(fd > 0) {
                printf("Device File Opened successfully in the path /dev/driver2_device...\n");
        }
        else {
                printf("Cannot open device file...\n");
                return 0;
        }*/

        while(1) {
                printf("****Please Enter the Option******\n");
                printf("        1. Write               \n");
                printf("        2. Read                 \n");
                printf("        3. Exit                 \n");
                printf("*********************************\n");
                scanf(" %c", &option);
                printf("Your Option = %c\n", option);
                
                switch(option) {
                        case '1':
        			fd = open(argv[1], O_RDWR);
                                printf("Enter the string to write into driver :");
                                scanf("  %[^\t\n]s", write_buf);
                                printf("Data Writing ...");
                                write(fd, write_buf, strlen(write_buf)+1);
                                printf("Done!\n");
                                close(fd);
				break;
                        case '2':

        			fd = open(argv[1], O_RDWR);
                                printf("Data Reading ...");
                                read(fd, read_buf, 1024);
                                printf("Done!\n\n");
                                printf("Data = %s\n\n", read_buf);
                                close(fd);
				break;
                        case '3':
                                exit(1);
                                break;
                        default:
                                printf("Enter Valid option = %c\n",option);
                                break;
                }
        }
        close(fd);
}
