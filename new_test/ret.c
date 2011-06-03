#include <stdio.h>

#define N 2

void is_even(int n)
{
    if (n % 2 == 0)
    {
        printf("%d is even !\n", n);
        return;
    }
    printf("%d is not even !\n", n);
}

int main(void)
{
    is_even(N);

    return 0;
}
