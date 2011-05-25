#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    char *p = NULL; 
    short nMemSize = 0; 

    p = malloc(1024); 
    nMemSize = sizeof(p); 
    printf("%d %d\n",sizeof(p),sizeof(*p));

    return 0;
}
