#include <stdio.h>
#include <stdlib.h>

int mycp(const char *dest,const char *src,int choice);
static int cp_by_char(const char *dest,const char *src);
static int cp_by_record(const char *dest,const char *src);
static int cp_by_row(const char *dest,const char *src);

int mycp(const char *dest,const char *src,int choice)
{
    switch(choice){
    case 1:cp_by_char(dest,src);break;
    case 2:cp_by_record(dest,src);break;
    case 3:cp_by_row(dest,src);break;
    }
   
   return 0;
}

static int cp_by_char(const char *dest,const char *src)
{
    char ch;
    FILE *fp1,*fp2;
    if ((fp1=fopen(src,"r"))==NULL){
        printf("can't open:%s\n",src);
        exit(1);
        }
    if ((fp2=fopen(dest,"w"))==NULL){
        printf("can't open:%s\n",dest);
        exit(1);
        }
    while((ch=fgetc(fp1))!=EOF)
        fputc(ch,fp2);
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}

static int cp_by_record(const char *dest,const char *src)
{
    char buff[128];
    FILE *fp1,*fp2;
    if ((fp1=fopen(src,"r"))==NULL){
        printf("can't open:%s\n",src);
        exit(1);
        }
    if ((fp2=fopen(dest,"w"))==NULL){
        printf("can't open:%s\n",dest);
        exit(1);
        }
    while(fread(buff,1,1,fp1)!=0)
        fwrite(buff,1,1,fp2);
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}

static int cp_by_row(const char *dest,const char *src)
{
    char string[81];
    FILE *fp1,*fp2;
    if ((fp1=fopen(src,"r"))==NULL){
        printf("can't open:%s\n",src);
        exit(1);
        }
    if ((fp2=fopen(dest,"w"))==NULL){
        printf("can't open:%s\n",dest);
        exit(1);
        }
    while(fgets(string,81,fp1)!=NULL)
        fputs(string,fp2);
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}
