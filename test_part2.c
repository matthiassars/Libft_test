/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_part2.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: msars <msars@student.42berlin.de>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/05 18:32:45 by msars            #+#    #+#              */
/*   Updated: 2026/05/08 09:51:00 by msars           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"
#include "test_utils.h"

static void	test_single_substr(char *s, unsigned int start, size_t len)
{
	char	*dst;

	dst = ft_substr(s, start, len);
	printf("\"%s\" %d %ld \"%s\"\n", s, start, len, dst);
	free(dst);
}

static void	test_substr(void)
{
	printheader("ft_substr");
	test_single_substr("Hello world!!!!!!", 0, 64);
	test_single_substr("Hello world!!!!!!", 6, 6);
	test_single_substr("Hello world!!!!!!", 6, 2e9);
	test_single_substr("Hello world!!!!!!", 6, 0);
	test_single_substr("Hello world!!!!!!", 32, 1);
	test_single_substr("Hello world!!!!!!", 2e9, 1);
	test_single_substr("Hello world", 10, 64);
	test_single_substr("", 6, 64);
}

static void	test_strjoin(void)
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

static void	test_single_strtrim(char *s, char *set)
{
	char	*dst;

	printf("\"%s\" \"%s\"\n", s, set);
	dst = ft_strtrim(s, set);
	printf("\"%s\"\n", dst);
	free(dst);
}

static void	test_strtrim(void)
{
	printheader("ft_strtrim");
	test_single_strtrim("___-_Hello_world!!!--___", "_-");
	printf("\n");
	test_single_strtrim("___-_--___", "_-");
	printf("\n");
	test_single_strtrim("Hello_world!!!", "");
}

static void	test_single_split(char *s, char c)
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
	printf("}\n\n");
	free(words);
}

static void	test_split(void)
{
	printheader("ft_split");
	test_single_split("___Hello__world!____", '_');
	test_single_split("___Hello__world!", '_');
	test_single_split("_______", '_');
	test_single_split("", '_');
	test_single_split("___Hello__world!____", '\0');
}

static void	test_itoa_range(long min, long max)
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

static void	test_itoa(void)
{
	printheader("ft_itoa");
	test_itoa_range(-2147483649, -2147483647);
	test_itoa_range(-20, 20);
	test_itoa_range(2147483646, 2147483648);
}

char	f1(unsigned int i, char c)
{
	if (i >= 5)
		return (ft_toupper(c));
	return ((c));
}

static void	f2(unsigned int i, char *c)
{
	if (i >= 5)
		*c = ft_toupper(*c);
}

static void	test_strmap_iteri(void)
{
	char	*s;
	char	*fs;

	printheader("ft_strmapi ft_striteri");
	s = malloc(17);
	strcpy(s, "Hello World!!");
	fs = ft_strmapi(s, f1);
	printf("\"%s\"\n", fs);
	strcpy(s, "");
	fs = ft_strmapi(s, f1);
	printf("\"%s\"\n", fs);
	strcpy(s, "Hello World!!");
	ft_striteri(s, f2);
	printf("\"%s\"\n", s);
	free(s);
	free(fs);
}

int	main(void)
{
	printheader("test part 2: additional functions");
	putchar('\n');
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
	return (0);
}
