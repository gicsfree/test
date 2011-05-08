#include <stdio.h>

char *letter_switch(char *string)
{
	char *p = string;
	while (*p)
		if ((*p >= 'a' && *p <= 'z') || (*p >= 'A' && *p <= 'Z')) {
			*p = (*p) ^ (0x01 << 5);
			p++;
		} else
			p++;
	return string;
}
