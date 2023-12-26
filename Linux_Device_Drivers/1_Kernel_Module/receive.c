/*
    filename server_ipaddress portno
    argv[0] filename
    argv[1] server_ipaddress
    argv[2] portno
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include<ntedb.h>

void error(const char *msg){
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr;
    struct hostent *server;

    int sockfd, portno, n;
    char buffer[256];
    
    if(argc < 3) {
        fprintf(stderr, "Usage %s hostname port\n\n",argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]); 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        error("Error Opening Socket");
    }
    
    server  = gethostbyname(argv[1]);
    if(server==NULL)
    {
        fprintf(stderr,"Error No soch host");
    }
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr , (char*)&server_addr.sin_addr.s_addr,server->h_length);
    
   server_addr.sin_port = htons(portno); 

   if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
   {
    error("Connection Failed");
   }
    
    int num1,num2,choice,ans;
S:  bzero(buffer,256);
    if(n<0)
    {
        error("Error Reading from Choice");
    }
    printf("Server: %s\n",buffer);
    scanf("%d",num1);
    write(sockfd,&num1,sizeof(int));

    bzero(buffer,256);
    if(n<0)
    {
        error("Error Reading from Choice");
    }
    printf("Server: %s\n",buffer);
    scanf("%d",nu21);
    write(sockfd,&num2,sizeof(int));
    bzero(buffer,256);
    if(n<0)
    {
        error("Error Reading from Choice");
    }
    printf("Server: %s\n",buffer);
    scanf("%d",choice);
    write(sockfd,&choice,sizeof(int));

    if(choice==5)
    {
        goto Q;
    }
    read(sockfd,&ans,sizeof(int));
    printf("Server: Answer is: %d\n",ans);
    if(choice!=5)
    {
        goto S;    }
    Q:    
    close(sockfd);
    return 0;
}
