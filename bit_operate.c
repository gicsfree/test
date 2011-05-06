#include <stdio.h>

int decimal_to_binary(int n);
int bit_mul(int m, int n);
char *letter_switch(char *string);
char *decrypt(char *string);

int main(int argc, char *argv[])
{
	int m, n, x, y;
	char string[128], s[128];
	while (1) {
		printf("1.secimal to bilary\n");
		printf("2.x*y\n");
		printf("3.low or up exchange\n");
		printf("4.encryption\n");
		printf("5.exit\n");
		printf("please choose [1-5]:");
		scanf("%d", &m);
		if (m < 1 || m > 5)
			return 0;

		switch (m) {
		case 1:

			printf("input a number :");
			scanf("%d", &n);
			decimal_to_binary(n);
			break;
		case 2:

			printf("intput x y :");
			scanf("%d %d", &x, &y);
			bit_mul(x,y);
			break;
		case 3:
			printf("input a string :");
			scanf("%s", string);
			letter_switch(string);
			break;
		case 4:

			printf("input a string :");
			scanf("%s", s);
			decrypt(s);
			break;
		case 5:
			return 0;
		}
	}
	return 0;
}

int decimal_to_binary(int n)
{
	int i, j, p;
	if ((n >> 31) & 1) {
		p = ~(n - 1);
		printf("-");
	} else
		p = n;
	for (i = 30; i >= 0; i--)
		if ((p >> i) & 1)
			break;
	printf("decimal %d change to binary is ", n);
	for (j = i; j >= 0; j--)
		printf("%d", ((p >> j) & 1));
	printf("\n");
	return 0;
}


int bit_mul(int m, int n)
{
	int i, p, q, result = 0, flag = 0;
	if ((m >> 31) & 1)
		p = ~(m - 1);
	else
		p = m;
	if ((n >> 31) & 1)
		q = ~(n - 1);
	else
		q = n;
	if (((m >> 31) & 1) ^ ((n >> 31) & 1))
		flag = 1;
	for (i = 0; i < 31; i++)
		if ((p >> i) & 1)
			result += q << i;
	if (1 == flag)
		result = ~result + 1;
	printf("x * y =%d\n", result);
	return result;
}

char *letter_switch(char *string)
{
	char *p = string;
	while (*p)
		if (*p >= 'a' && *p <= 'z' || *p >= 'A' && *p <= 'Z') {
			*p = (*p) ^ (0x01 << 5);
			p++;
		} else
			p++;
	printf("%s\n", string);
	return string;
}

char *decrypt(char *string)
{
	char *p = string, *q = string;
	printf("jiamiqian :%s\n", p);
	while (*p) {
		*p = *p ^ 'x';
		p++;
	}
	printf("jiamihou :%s\n", string);
	while (*q) {
		*q = *q ^ 'x';
		q++;
	}
	printf("jiemihou :%s\n", string);

	return string;
}
