/* server_tcp.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "wrap.h"

#define DEFAULT_PORT 5050
#define SUBF_LEN 128
#define FILENAME_LEN 128
#define VERSION_LEN 15
#define LINE_LEN 1024
#define VERSION "Version"

int download_list(int sAccept, char list_name[]);
int update_list(int sAccept, char list_name[]);
void get_version(char version[], char list_name[]);

int main(int argc, char** argv)
{
    int sPort = DEFAULT_PORT;
    int sListen = 0;
    int sAccept = 0;
    unsigned int sLen = 0;
    struct sockaddr_in ser;
    struct sockaddr_in cli;
    int sSend = 0,sRecv = 0;
    char filename[FILENAME_LEN];
    char is_exist[] = "is_exist";
    char no_exist[] = "no_exist";
   
    printf("Server waiting...\n");
   
    sListen = Socket(AF_INET, SOCK_STREAM, 0);
    if(sListen < 0)
    {
        printf("socket() failure!\n");
        return -1;
    }
   
    ser.sin_family = AF_INET;
    ser.sin_port = htons(sPort);
    ser.sin_addr.s_addr = htonl(INADDR_ANY);
   
    Bind(sListen, (struct sockaddr*)&ser, sizeof(ser));
   
    Listen(sListen, 5); 

    while(1)
    {
	sLen = sizeof(cli);
    sAccept = Accept(sListen, (struct sockaddr*)&cli, (unsigned int*)&sLen);
    if(sAccept < 0)
    {
        printf("accept() failure!\n");             
        break;
    }
   
    printf("accept() client IP: [%s]\n", (char*)inet_ntoa(cli.sin_addr));
    printf("accept() client PORT: [%d]\n", ntohs(cli.sin_port));
       
    sRecv = Recv(sAccept, filename, sizeof(filename), 0);
    if(sRecv < 0)
    {
        printf("recv(filename) failure!\n");
        return -1;
    }  

    FILE *fp = fopen(filename,"r");
    if (fp != NULL)
    {
        sSend = Send(sAccept, is_exist, sizeof(is_exist), 0);
        if(sSend < 0)
        {
            printf("send() failure!\n");
            return -1;
        } 
    }
    else
    {
        printf("%s is not exist,download failed !\n", filename);
        sSend = Send(sAccept, no_exist, sizeof(no_exist), 0);
        if(sSend < 0)
        {
            printf("send() failure!\n");
            return -1;
        } 
    }

//    download_list(sAccept, filename);
    update_list(sAccept, filename);

    printf("Server waiting...\n");
    Close(sAccept);
    }
    Close(sListen);
   
    return 0;
}


int download_list(int sAccept, char list_name[])
{
    int sSend = 0;
    char sbuf[SUBF_LEN];
    char finish[] = "finish";
   
    FILE *fp = fopen(list_name,"r");
    if (fp == NULL)
    {
        printf("cannot open %s\n", list_name);
        return -1;
    }

    while (fgets(sbuf, SUBF_LEN, fp) != NULL)
    {        
        sSend = Send(sAccept, sbuf, sizeof(sbuf), 0);
        if(sSend < 0)
        {
            printf("send(text) failure!\n");
            return -1;
        } 
    }

    sSend = Send(sAccept, finish,sizeof(finish), 0);
    if(sSend < 0)
    {
        printf("send(finish) failure!\n");
        return -1;
    } 

    printf("download %s successfully !\n", list_name);
    fclose(fp);

    return 0;
}

//#if 0
int update_list(int sAccept, char list_name[])
{
    int sSend = 0,sRecv = 0;
    char is_new[] = "is_new";
    char no_new[] = "no_new";
    char version[VERSION_LEN];
    char recv_version[VERSION_LEN];
   
    get_version(version, list_name);

    sRecv=Recv(sAccept, recv_version, sizeof(recv_version), 0);
    if(sRecv < 0)
    {
        printf("recv() failure!\n");
        return -1;
    }

    if (strncmp(version, recv_version, VERSION_LEN) != 0)
    {
        sSend = Send(sAccept, no_new,sizeof(no_new), 0);
        if(sSend < 0)
        {
            printf("send() failure!\n");
            return -1;
        } 
        download_list(sAccept, list_name);
    }
    else
    {
        sSend = Send(sAccept, is_new, sizeof(is_new), 0);
        if(sSend < 0)
        {
            printf("send() failure!\n");
            return -1;
        } 
    }

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
            strncpy(version, aLine,VERSION_LEN);
            fclose(fp);
            break;
        }
    }
}









// #endif


#if 0
int main(int argc, char** argv)
{
    int sPort = DEFAULT_PORT;
    int sListen = 0;
    int sAccept = 0;
    unsigned int sLen = 0;
    int sSend = 0,sRecv = 0;
    struct sockaddr_in ser;
    struct sockaddr_in cli;
    char sbuf[SUBF_LEN] ,filename[FILENAME_LEN];
    char is_exist[] = "is_exist";
    char no_exist[] = "no_exist";
    char finish[] = "finish";
   
    printf("Server waiting...\n");
   
    sListen = socket(AF_INET, SOCK_STREAM, 0);
    if(sListen < 0)
    {
        printf("socket() failure!\n");
        return -1;
    }
   
    ser.sin_family = AF_INET;
    ser.sin_port = htons(sPort);
    ser.sin_addr.s_addr = htonl(INADDR_ANY);
   
    if(bind(sListen, (struct sockaddr*)&ser, sizeof(ser)) < 0)
    {
        printf("bind() failure!\n");       
        return -1;
    }
   
    if(listen(sListen, 5) < 0)
    {
        printf("listen() failure!\n");        
        return -1;
    }

    while(1)
    {
	sLen = sizeof(cli);
    sAccept = accept(sListen, (struct sockaddr*)&cli, (unsigned int*)&sLen);
    if(sAccept < 0)
    {
        printf("accept() failure!\n");             
        break;
    }
   
    printf("accept() client IP: [%s]\n", (char*)inet_ntoa(cli.sin_addr));
    printf("accept() client PORT: [%d]\n", ntohs(cli.sin_port));
       
    sRecv=recv(sAccept, filename, sizeof(filename), 0);
    if(sRecv <= 0)
    {
        printf("recv(filename) failure!\n");
        return -1;
    }  

	FILE *fp = fopen(filename,"r");
    if (fp != NULL){
        sSend = send(sAccept, is_exist,sizeof(is_exist), 0);
        if(sSend <= 0)
        {
            printf("send(is_exist) failure!\n");
            return -1;
        } 

        while (fgets(sbuf, SUBF_LEN, fp) != NULL){        
            sSend = send(sAccept, sbuf, sizeof(sbuf), 0);
            if(sSend <= 0)
            {
                printf("send(text) failure!\n");
                return -1;
            } 
        }

    sSend = send(sAccept, finish,sizeof(finish), 0);
    if(sSend <= 0)
    {
        printf("send(finish) failure!\n");
        return -1;
    } 

    printf("download %s successfully !\n", filename);
	fclose(fp);
    } 
    else
    {
        printf("%s is not exist,download failed !\n", filename);
        sSend = send(sAccept, no_exist, sizeof(no_exist), 0);
        if(sSend <= 0)
        {
            printf("send(no_exist) failure!\n");
            return -1;
        } 
    }

    printf("Server waiting...\n");
    close(sAccept);
    }
    close(sListen);
   
    return 0;
}

#endif
