/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_part2.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: msars <msars@student.42berlin.de>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/05 18:32:45 by msars            #+#    #+#              */
/*   Updated: 2026/05/06 15:08:14 by msars           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "test_utils.h"

void	test_single_substr(char *s, unsigned int start, size_t len)
{
	char	*dst;

	dst = ft_substr(s, start, len);
	printf("\"%s\" %d %ld \"%s\"\n", s, start, len, dst);
	free(dst);
}

void	test_substr(void)
{
	printheader("ft_substr");
	test_single_substr("Hello world!!!!!!", 0, 64);
	test_single_substr("Hello world!!!!!!", 6, 64);
	test_single_substr("Hello world!!!!!!", 6, 6);
	test_single_substr("Hello world!!!!!!", 6, 0);
	test_single_substr("Hello world!!!!!!", 64, 1);
	test_single_substr("Hello world", 10, 64);
	test_single_substr("", 6, 64);
	test_single_substr("hola", 4294967295, 0);
}

void	test_strjoin(void)
{
	char	*s1 = "Hello ";
	char	*s2 = "world!";
	char	*dst;

	printheader("ft_strjoin");
	printf("\"%s\" \"%s\"\n", s1, s2);
	dst = ft_strjoin(s1, s2);
	printf("\"%s\"\n", dst);
	free(dst);
}

void	test_single_strtrim(char *s, char *set)
{
	char	*dst;

	printf("\"%s\" \"%s\"\n", s, set);
	dst = ft_strtrim(s, set);
	printf("\"%s\"\n", dst);
	free(dst);
}

void	test_strtrim(void)
{
	printheader("ft_strtrim");
	test_single_strtrim("___-_Hello World!!!--___", "_-");
	printf("\n");
	test_single_strtrim("___-_--___", "_-");
}

void	test_single_split(char *s, char c)
{
	char	**words;
	char	**word;

	words = ft_split(s, c);
	word = words;
	printf("\"%s\" '%c'\n{ ", s, c);
	while (*word)
	{
		printf("\"%s\" ", *word);
		free(*word);
		word++;
	}
	printf("}\n");
	free(words);
}

void	test_split(void)
{
	printheader("ft_split");
	test_single_split("   Hello  world!    ", ' ');
	test_single_split("   Hello  world!", ' ');
	test_single_split("       ", ' ');
	test_single_split("", ' ');
	test_single_split("   Hello  world!    ", '\0');
}

void	test_itoa_range(long min, long max)
{
	long	i;
	char	*s;

	i = min;
	while (i <= max)
	{
		s = ft_itoa(i);
		printf("%ld \"%s\"  ", i, s);
		free(s);
		i++;
	}
	printf("\n");
}

void	test_itoa(void)
{
	printheader("ft_itoa");
	test_itoa_range(-2147483649, -2147483647);
	test_itoa_range(-20, 20);
	test_itoa_range(2147483646, 2147483648);
}

char	f1(unsigned int i, char c)
{
	(void) i;
	return (ft_toupper(c));
}

void	f2(unsigned int i, char *c)
{
	(void) i;
	*c = ft_toupper(*c);
}

void	test_strmap_iteri(void)
{
	char	*s;
	char	*fs;

	printheader("ft_strmapi ft_striteri");
	s = malloc(17);
	ft_strlcpy(s, "Hello World!!", 17);
	fs = ft_strmapi(s, f1);
	printf("\"%s\"\n", fs);
	ft_striteri(s, f2);
	printf("\"%s\"\n", s);
	free(s);
	free(fs);
}

void	test_putendl_fd(void)
{
	printheader("ft_putchar_fd ft_putendl_fd");
	ft_putchar_fd('\"', 1);
	ft_putendl_fd("Hello world!!", 1);
	ft_putendl_fd("\"", 1);
}

void	test_single_putnbr(int n)
{
	printf("%d\n", n);
	ft_putnbr_fd(n, 1);
	printf("\n");
}

void	test_putnbr_fd(void)
{
	printheader("ft_putnbr_fd");
	test_single_putnbr(-2147483648);
	test_single_putnbr(-1337);
	test_single_putnbr(0);
	test_single_putnbr(1337);
	test_single_putnbr(2147483647);
}

int	main(void)
{
	test_substr();
	putchar('\n');
	test_strjoin();
	putchar('\n');
	test_strtrim();
	putchar('\n');
	test_split();
	putchar('\n');
	test_itoa();
	putchar('\n');
	test_strmap_iteri();
	putchar('\n');
	test_putendl_fd();
	putchar('\n');
	test_putnbr_fd();
	putchar('\n');
	return (0);
}
