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
	int	hline_len_l;
	int	hline_len_r;
	int	str_len;

	str_len = strlen(s);
	hline_len_l = (76 - strlen(s)) / 2;
	hline_len_r = 76 - str_len - hline_len_l;
	printrepchar('-', hline_len_l);
	printf("  %s  ", s);
	printrepchar('-', hline_len_r);
	putchar('\n');
}
