#include <stdio.h>

char *GetMemory0(void)
{
char p[] = “Hello World”;

return p;
}

char *GetMemory1(void)
{
const char p[] = “Hello World”;

return p;
}

char *GetMemory2(void)
{
char *p = “Hello World”;

return p;
}

void Test(void)
{
char*str = NULL;

str = GetMemory0();
printf(str);            // 输出结果?

str = GetMemory1();
printf(str);            // 输出结果?

str = GetMemory2();
printf(str);            // 输出结果?

}

int main(void)
{
    Test();

    return 0;
}
