#include <stdio.h>

char *encrypt(char *s)
{
	char *p = s, *q = s;
	printf("encrypt_before is :%s\n", s);
	while (*p) {
		*p = *p ^ 'x';
		p++;
	}
	printf("encrypted is      :%s\n", s);
	while (*q) {
		*q = *q ^ 'x';
		q++;
	}
	printf("decrypted is      :%s\n", s);

	return s;
}
