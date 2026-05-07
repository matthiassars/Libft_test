#include <stdio.h>
#include <string.h>

void	printrepchar(char c, int n)
{
	while (n > 0)
	{
		putchar(c);
		n--;
	}
}

void	printheader(char *s)
{
	int	str_len;

	str_len = strlen(s);
	printrepchar('-', 4);
	printf("  %s  ", s);
	printrepchar('-', 72 - str_len);
	putchar('\n');
}
