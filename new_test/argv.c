#include <stdio.h>

void Printf(void)
{
    printf("%s\n", argv[0]);
}

int main(int argc, const char *argv[])
{
    printf("%s\n", argv[0]);
    Printf();

    return 0;
}
