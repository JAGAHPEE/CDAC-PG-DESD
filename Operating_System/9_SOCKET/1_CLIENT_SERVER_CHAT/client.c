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
#include<netdb.h>

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

    portno = atoi(argv[2]); 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        error("Error Opening Socket");
    }
    
    server  = gethostbyname(argv[1]);
    if(server==NULL)
    {
        fprintf(stderr,"Error No soch host");
        exit(1);
    }
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr , (char*)&server_addr.sin_addr.s_addr,server->h_length);
    
   server_addr.sin_port = htons(portno); 

   if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0)
   {
    error("Connection Failed");
   }
    
    while (1) {
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);
        n = write(sockfd, buffer, strlen(buffer));
        if(n < 0) {
            error("Error on Writing");
        }
        bzero(buffer, 256);
        n = read(sockfd, buffer, 255);
        if(n < 0) {
            error("Error on Reading");
        }
        printf("Server: %s\n",buffer);
        int i = strncmp("Bye", buffer, 3);
        if(i == 0) {
            break;
        }
    }

    close(sockfd);
    return 0;
}

