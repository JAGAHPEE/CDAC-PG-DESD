#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Port Number Not provided\n");
        exit(1);
    }
    
    int sockfd, newsockfd, portno, n;
    char buffer[256];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        error("Error Opening Socket");
    }
    
    bzero((char *)&server_addr, sizeof(server_addr));
    portno = atoi(argv[1]); 
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno); 
    
    if(bind(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        error("Binding Failed");
    }
    
    listen(sockfd, 5);
    client_len = sizeof(client_addr);
    
    newsockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_len);
    if(newsockfd < 0) {
        error("Error on Accept");
    }
    
    int num1,num2,answer,choice;
s: n = write(newsockfd,"Enter Number 1: ",strlen("ENter Number 1: "));
    if(n<0)
    {
        error("Error Writing to Socket");
    }
    read(newsockfd,&num1,sizeof(int));
    printf("Client: 1st Number is %d\n",num1);



    n = write(newsockfd,"Enter Number 2: ",strlen("Enter Number 2: "));
    if(n<0)
    {
        error("Error Writing to Socket");
    }
    read(newsockfd,&num2,sizeof(int));
    printf("Client:2nd Number is %d\n",num2);



    n = write(newsockfd,"Enter Choice:\n1 for Addition\n2 for Subtraction\n3 for Multiplication\n4 for Division\n5 for Exit\n",strlen("Enter Choice:\n1 for Addition\n2for Subtraction\n3 for Multiplication\n4 for Division\n5 for Exit\n"));
    if(n<0)
    {
        error("Error Writing to Socket");
    }
    read(newsockfd,&choice,sizeof(int));

    printf("Client:Choice is %d\n",choice);
   
    switch (choice)
    {
    case 1:
        answer = num1+num2;
        break;
    case 2:
        answer = num1-num2;
        break;
    case 3:
        answer = num1*num2;
        break;
    case 4:
        answer = num1/num2;
        break;
    case 5:
        goto Q;
        break;
    }
    write(newsockfd,&answer,sizeof(int));
    if(choice!=5)
    {
        goto s;
    }
Q:  close(newsockfd);
    close(sockfd);
    return 0;
}
