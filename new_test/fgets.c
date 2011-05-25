#include <stdio.h>

#define MAX 4

int main(int argc, const char *argv[])
{
    char str[MAX];

    fgets(str,MAX,stdin);
    fputs(str,stdout);
    fputs("\n",stdout);

    return 0;
}
