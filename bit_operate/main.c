#include <stdio.h>
#include "d2b.h"
#include "exchange.h"
#include "encryption.h"
#include "multi.h"

int main(int argc, char *argv[])
{
	int m;
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
			d2b();
			break;
		case 2:
			multi();
			break;
		case 3:
			exchange();
			break;
		case 4:
			encryption();
			break;
		case 5:
			return 0;
		}
	}
	return 0;
}
