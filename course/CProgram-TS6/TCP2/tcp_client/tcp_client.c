/* client_tcp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_PORT 5050
#define CBUF_LEN 128
#define FILENAME_LEN 20

int main(int argc, char** argv)
{
    int cPort = DEFAULT_PORT;
    int cClient = 0;
    int cLen = 0;
    struct sockaddr_in cli;
    char cbuf[CBUF_LEN];
    char filename[FILENAME_LEN];
    char exist[] = "is_exist";
//    char no_exist[] = "no_exist";
    char is_exist[10];
    char finish[] = "finish";
   
    if(argc < 3)
    {
        printf("Uasge: client[server IP address] [filename]\n");
        return -1;
    }
   
    memset(cbuf, 0, sizeof(cbuf));
   
    cli.sin_family = AF_INET;
    cli.sin_port = htons(cPort);
    cli.sin_addr.s_addr = inet_addr(argv[1]);
   
    cClient = socket(AF_INET, SOCK_STREAM, 0);
    if(cClient < 0)
    {
        printf("socket() failure!\n");
        return -1;
    }
   
    if(connect(cClient, (struct sockaddr*)&cli, sizeof(cli)) < 0)
    {
        printf("connect() failure!\n");
        return -1;
    }

    strcpy(filename,argv[2]);
    send(cClient, filename, sizeof(filename), 0);
    recv(cClient, is_exist, sizeof(is_exist), 0);
    if (0 == strncmp(is_exist, exist, strlen(exist))){
        FILE *fp = fopen(filename,"w+");
        while (1){   
            cLen = recv(cClient, cbuf, sizeof(cbuf),0);   
            if((cLen < 0)||(cLen == 0))
            {
                printf("recv() failure!\n");
                return -1;
            }
            if (0 != strncmp(cbuf ,finish ,strlen(finish)))
            fputs(cbuf,fp);
            else{
                printf("download successfully !\n");
                break;
            }
        }
    }
    else
        printf("no such file !\n");

    close(cClient);
   
    return 0;
}
