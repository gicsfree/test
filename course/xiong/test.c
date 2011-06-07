#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    char str[] = "ls -l";

    system(str);

    return 0;
}
