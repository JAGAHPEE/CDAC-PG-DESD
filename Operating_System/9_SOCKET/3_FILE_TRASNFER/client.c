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
#include <netdb.h>
#include <sys/stat.h>
#include <fcntl.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    struct sockaddr_in server_addr;
    struct hostent *server;

    int sockfd, portno, n;
    char buffer[256];

    if (argc < 3)
    {
        fprintf(stderr, "Usage %s hostname port\n\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("Error Opening Socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL)
    {
        fprintf(stderr, "Error No soch host");
        exit(1);
    }
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    server_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0)
    {
        error("Connection Failed");
    }

    FILE *file;
    file = fopen("/usr/include/stdio.h", "rb");
    if (file == NULL)
    {
        perror("Unable to open file");
        return 0;
    }

    char ch;
    while ((ch = fgetc(file)) != EOF)
    {
        if (write(sockfd, &ch, sizeof(ch)) < 0)
        {
            error("Error writing to socket");
        }
    }

    printf("Data sent successfully\n");
s:
    fclose(file);
    close(sockfd);
    return 0;
}
