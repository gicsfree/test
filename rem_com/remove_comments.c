#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define BUF_SIZE 1024

void perr_exit(const char *s);
void remove_comment2(char *str);
void remove_comment1(char *str);

/* main */
int main(int argc, const char *argv[])
{
    if (argc != 3){
        printf("Usage: ./main src.c dest.c\n");
        return -1;
    }

    FILE *fp_src;
    FILE *fp_dest;
    char buf[BUF_SIZE];

    fp_src = fopen(argv[1], "r");
    if (fp_src == NULL)
        perr_exit("fopen file src.c");
    fp_dest = fopen(argv[2], "w");
    if (fp_dest == NULL)
        perr_exit("fopen file dest.c");

    while (fgets(buf, BUF_SIZE, fp_src) != NULL){
        remove_comment1(buf);
        remove_comment2(buf);
        fputs(buf, fp_dest);
    }

    fclose(fp_src);
    fclose(fp_dest);

    return 0;
}

void perr_exit(const char *s)
{
    perror(s);
    exit(1);
}

void remove_comment1(char *str)
{
    char *p;
    int i, cnt = 0;

    p = strstr(str, "/*");
    if (p == NULL)
        return;
    else{
        for (i = 0; i < (p - str); i++)
            if (str[i] == '"')
                cnt++;
        if (!(cnt % 2)){
            *p = '\n';
            *(p + 1) = '\0';
        }
    }

    return;
}
void remove_comment2(char *str)
{
    char *p;
    int i, cnt = 0;

    p = strstr(str, "//");
    if (p == NULL)
        return;
    else{
        for (i = 0; i < (p - str); i++)
            if (str[i] == '"')
                   cnt++;
        if (!(cnt % 2)){
            *p = '\n';
            *(p + 1) = '\0';
        }
    }

    return;
}
