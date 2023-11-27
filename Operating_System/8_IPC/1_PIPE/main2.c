//Pipes

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#define BUFF 4096
int main()
{
        char buff[BUFF],read_data[BUFF];
        int  pipes[2],pipes2[2];
        char buff2[BUFF];
        if(pipe(pipes)==-1)
        {
                printf("Unable to Create pipe\n");
                exit(EXIT_FAILURE);
        }
        if(pipe(pipes2)==-1)
        {
                printf("Unable to Create pipe\n");
                exit(EXIT_FAILURE);
        }
        // To Create a Child Process
        pid_t cpid = fork();
        if(cpid==-1)
        {
                printf("Process Error\n");
                exit(EXIT_FAILURE);
        }


        // Child Process
        if(cpid==0)
        {
                close(pipes[1]);
                read(pipes[0],buff, BUFF);
                printf("Data Received in Child Process: ");
                printf("%s\n",buff);
                close(pipes[0]);
                close(pipes2[0]);

                write(pipes2[1],"Kale\n",4);
                printf("Data sent by Child\n");
                close(pipes2[1]);
        }
        else
        {
                close(pipes[0]);
                scanf("%[^\n]s",read_data);
                write(pipes[1],read_data,strlen(read_data));
                printf("Data Sent by Parent\n");
                close(pipes[1]);
                wait(NULL);
                read(pipes2[0],buff2,BUFF);
                printf("Data Received by Parent: ");
                printf("%s\n",buff2);
                close(pipes2[0]);
        }
        return 0;



}
