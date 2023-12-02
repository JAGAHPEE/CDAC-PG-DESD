
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Port Number Not provided\n");
        exit(1);
    }

    int sockfd, newsockfd, portno, n;
    char buffer[256];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("Error Opening Socket");
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    portno = atoi(argv[1]);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        error("Binding Failed");
    }

    listen(sockfd, 5);
    client_len = sizeof(client_addr);

    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
    if (newsockfd < 0)
    {
        error("Error on Accept");
    }
    bzero(buffer, 256);

     FILE *file;
    file = fopen("stdio.h", "wb");
    if (file == NULL) {
        error("Error opening file");
    }

    int bytes_received;
    while ((bytes_received = read(newsockfd, buffer, 256)) > 0) {
        fwrite(buffer, 1, bytes_received, file);
        printf("%d\n",bytes_received);
        bzero(buffer, 256);
    }

    if (bytes_received < 0) {
        error("Error reading from socket");
    }

    printf("File received successfully\n");

    s:fclose(file);
    close(newsockfd);
    close(sockfd);
    return 0;
}
