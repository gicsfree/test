#include <stdio.h>
#include <string.h>

char *my_shell(char *s);

int main(int argc,char *argv[])
{
    char str[128];
    printf("input a string :\n");
    while(strlen(gets(str))>0){
        my_shell(str);
        printf("input a string :\n");
        }

    return 0;
}

char *my_shell(char *s)
{
    char *p=s,*q=s,*r,*str=s;
    int flag=0;
    while (*q){
        if (*q=='<'||*q=='>'){
            flag=1;break;
        }else
            *p++=*q++;
        }
    if (flag==1){
        while (*q){
            if (*q != ' ')
                *p++=*q++;
            else
                q++;
        }
    *p='\0';
    }

    while (*s){
        if((*s>'a'&&*s<'z' || *s>'A'&&*s<'Z')
            && (*(s+1)==' '||*(s+1)=='<'||*(s+1)=='>'||*(s+1)=='\n')){
            r=s;
            int i,m=0;
            for(;r>str;r--){
                if (*r==' '||*r=='<'||*r=='>')
                    break;
                m++;
                }
            if (r==str){
                printf("command:");
                for(i=0;i<m+1;i++)
                    printf("%c",*(r+i));
                }else if((*r==' ') && (*(r+1)=='-'||
                    (*(r+1)>'a'&&*(r+1)<'z')||(*(r+1)>'A'&&*(r+1)<'Z'))){
                    printf(",argument:");
                    for(i=0;i<m;i++)
                        printf("%c",*(r+1+i));
                        }else if(*r=='<'){
                            printf("\n,in-file:");
                            for(i=0;i<m;i++)
                                printf("%c",*(r+1+i));
                                printf(", out-file:NULL");
                                }else if(*r=='>'){
                                   printf("\n,in-file:NULL, out-file:");                                    for(i=0;i<m;i++)
                                        printf("%c",*(r+1+i));
                                        }
                
                }
                s++;
            }
    return str;
}
