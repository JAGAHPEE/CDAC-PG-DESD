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
    
    while (1) {
        bzero(buffer, 256);
        n = read(newsockfd, buffer, 255);
        if(n < 0) {
            error("Error on Reading");
        }
        printf("Client: %s\n", buffer);
        
        bzero(buffer, 256);
        fgets(buffer, 255, stdin);
        
        n = write(newsockfd, buffer, strlen(buffer));
        if(n < 0) {
            error("Error on Writing");
        }
        
        int i = strncmp("Bye", buffer, 3);
        if(i == 0) {
            break;
        }
    }
    
    close(newsockfd);
    close(sockfd);
    return 0;
}

