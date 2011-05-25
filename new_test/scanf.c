#include <stdio.h>

int main(int argc, char *argv[])
{
	int n;
	char ch;
	char s[5];
	float f;

	printf("%d\n", scanf("%d %c %s %f", &n, &ch, s, &f));

	return 0;
}
