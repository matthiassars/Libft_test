/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_part2.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: msars <msars@student.42berlin.de>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/05 18:32:45 by msars            #+#    #+#              */
/*   Updated: 2026/05/05 23:34:46 by msars           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "Libft/libft.h"
#include "test_utils.h"

void	test_substr(void)
{
	char	*s = "Hello world!!!!!!";
	char	*dst;

	printheader("ft_substr");
	printf("\"%s\"\n", s);
	dst = ft_substr(s, 0, 32);
	printf("\"%s\" %d %d\n", dst, 0, 32);
	free(dst);
	dst = ft_substr(s, 6, 6);
	printf("\"%s\" %d %d\n", dst, 6, 6);
	free(dst);
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

void	test_strtrim(void)
{
	char	*s = "___-_Hello World!!!--___";
	char	*set = "_-";
	char	*dst;

	printheader("ft_strtrim");
	printf("\"%s\" \"%s\"\n", s, set);
	dst = ft_strtrim(s, set);
	printf("\"%s\"\n", dst);
	free(dst);
}

void	test_split(void)
{
	char	*s = "   Hello  world!!    ";
	char	**words;
	char	**word;

	printheader("ft_split");
	words = ft_split(s, ' ');
	word = words;
	printf("\"%s\"\n", s);
	while (*word)
	{
		printf("\"%s\" ", *word);
		free(*word);
		word++;
	}
	putchar('\n');
	free(words);
}

void	test_single_itoa(int n)
{
	char	*s;

	s = ft_itoa(n);
	printf("%d \"%s\"\n", n, s);
	free(s);
}

void	test_itoa(void)
{
	long	i;

	printheader("ft_itoa");
	i = -2147483649;
	while (i <= -2147483647)
	{
		test_single_itoa(i);
		i++;
	}
	i = -20;
	while (i <= 20)
	{
		test_single_itoa(i);
		i++;
	}
	i = 2147483646;
	while (i <= 2147483648)
	{
		test_single_itoa(i);
		i++;
	}
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
}

void	test_putendl_fd(void)
{
	printheader("ft_putendl_fd");
	ft_putchar_fd('\"', 1);
	ft_putendl_fd("Hello world!!", 1);
	ft_putendl_fd("\"", 1);
}

void	test_single_putnbr_fd(long n)
{
	ft_putnbr_fd(n, 1);
	ft_putchar_fd('\n', 1);
}

void	test_putnbr_fd(void)
{
	long	i;

	printheader("ft_putnbr");
	i = -2147483649;
	while (i <= -2147483647)
	{
		test_single_putnbr_fd(i);
		i++;
	}
	i = -20;
	while (i <= 20)
	{
		test_single_putnbr_fd(i);
		i++;
	}
	i = 2147483646;
	while (i <= 2147483648)
	{
		test_single_putnbr_fd(i);
		i++;
	}
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
