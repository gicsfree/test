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
#define FILENAME_LEN 128
#define LINE_LEN 1024
#define VERSION "Version"
#define VERSION_LEN 15

int download_list(int cClient, char list_name[]);
int update_list(int cClient, char list_name[]);
void get_version(char version[], char list_name[]);

int main(int argc, char** argv)
{
    int cPort = DEFAULT_PORT;
    int cClient = 0;
    int cSend = 0,cRecv = 0;
    struct sockaddr_in cli;
    char cbuf[CBUF_LEN], filename[FILENAME_LEN];
    char exist[] = "is_exist";
    char is_exist[10];
   
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

    strncpy(filename, argv[2], FILENAME_LEN);
    cSend = send(cClient, filename, sizeof(filename), 0);
    if(cSend <= 0)
    {
        printf("send(filename) failure!\n");
        return -1;
    } 

    cRecv = recv(cClient, is_exist, sizeof(is_exist), 0);
    if(cRecv <= 0)
    {
        printf("recv(is_exist) failure!\n");
        return -1;
    } 

    if (0 == strncmp(is_exist, exist, strlen(exist)))
//        download_list(cClient, filename);
        update_list(cClient, filename);
    else
        printf("no such file, download failed !\n");

    close(cClient);
   
    return 0;
}


int download_list(int cClient, char list_name[])
{
    int cRecv = 0;
    char cbuf[CBUF_LEN];
    char finish[] = "finish";
   
    memset(cbuf, 0, sizeof(cbuf));

    FILE *fp = fopen(list_name,"w+");
    if (fp == NULL)
    {
        printf("cannot open %s\n", list_name);
        return -1;
    }
    while (1){   
        cRecv = recv(cClient, cbuf, sizeof(cbuf),0);   
        if(cRecv <= 0)
        {
            printf("recv() failure!\n");
            return -1;
        } 

        if (0 != strncmp(cbuf ,finish ,strlen(finish)))
        fputs(cbuf,fp);
        else
        {
            printf("download %s successfully !\n", list_name);
            fclose(fp);
            break;
        }
    }
   
    return 0;
}


int update_list(int cClient, char list_name[])
{
    int cRecv = 0, cSend = 0;
    char new[] = "is_new";
    char is_new[10];
    char version[VERSION_LEN];

    get_version(version, list_name);

    cSend = send(cClient, version, sizeof(version), 0);
    if(cSend <= 0)
    {
        printf("send(version) failure!\n");
        return -1;
    } 

    cRecv = recv(cClient, is_new, sizeof(is_new), 0);
    if(cRecv <= 0)
    {
        printf("recv(is_new) failure!\n");
        return -1;
    } 

    if (0 != strncmp(is_new, new, strlen(new)))
        download_list(cClient, list_name);
    else
        printf("the version is newtest !\n");
   
    return 0;
}

void get_version(char version[], char list_name[])
{
    FILE *fp;
    char aLine[LINE_LEN];

    fp = fopen(list_name, "r");
    if (fp == NULL)
    {
        printf("cannot open %s !\n", list_name);
        exit(1);
    }
    while (fgets(aLine, LINE_LEN, fp) != NULL)
    {
        if (strstr(aLine, VERSION) != NULL)    
        {
            strncpy(version, aLine, LINE_LEN);
            fclose(fp);
            break;
        }
    }

}
























#if 0
int main(int argc, char** argv)
{
    int cPort = DEFAULT_PORT;
    int cClient = 0;
    int cRecv = 0, cSend = 0;
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

    strncpy(filename, argv[2] ,FILENAME_LEN);

    cSend = send(cClient, filename, sizeof(filename), 0);
    if(cSend <= 0)
    {
        printf("send(filename) failure!\n");
        return -1;
    } 

    cRecv = recv(cClient, is_exist, sizeof(is_exist), 0);
    if(cRecv <= 0)
    {
        printf("recv(is_exist) failure!\n");
        return -1;
    } 

    if (0 == strncmp(is_exist, exist, strlen(exist))){

        FILE *fp = fopen(filename,"w+");
        if (fp == NULL)
        {
            printf("cannot open %s\n", filename);
            return -1;
        }
        while (1){   
            cRecv = recv(cClient, cbuf, sizeof(cbuf),0);   
            if(cRecv <= 0)
            {
                printf("recv(text) failure!\n");
                return -1;
            } 

            if (0 != strncmp(cbuf ,finish ,strlen(finish)))
            fputs(cbuf,fp);
            else
            {
                printf("download %s successfully !\n", filename);
                break;
            }
        }
    }
    else
        printf("%s is not exist,download failed !\n", filename);

    close(cClient);
   
    return 0;
}

#endif
