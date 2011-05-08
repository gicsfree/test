#include <stdio.h>
#include "d2b.h"
#include "exchange.h"
#include "eneryption.h"
#include "multi.h"

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
			bit_mul(x, y);
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
