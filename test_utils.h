#ifndef TEST_UTILS_H
# define TEST_UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <stdint.h>
# include <strings.h>
# include <bsd/string.h>
# include <ctype.h>
# include <fcntl.h>

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

void	printok_ko(int cond)
{
	if (cond)
		printf("\33[1;32m\u2713 :D\33[0m\n");
	else
		printf("\33[1;31m\u2A2F :/\33[0m\n");
}

#endif
