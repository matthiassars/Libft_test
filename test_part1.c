/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_part1.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: msars <msars@student.42berlin.de>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/05 23:33:32 by msars            #+#    #+#              */
/*   Updated: 2026/05/05 23:33:32 by msars           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "Libft/libft.h"
#include "test_utils.h"

void	print_bytes(unsigned char *a, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d ", a[i]);
		i++;
	}
	putchar('\n');
}

void	test_isalpha(void)
{
	int	c;

	printheader("ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint");
	printf("     al dg an as pr\n");
	c = -1;
	while (c <= 128)
	{
		printf("%03d  %d  %d  %d  %d  %d  \'%c\'\n", c,
			ft_isalpha(c),
			ft_isdigit(c),
			ft_isalnum(c),
			ft_isascii(c),
			ft_isprint(c),
			c);
		c++;
	}
}

void	test_strlen(void)
{
	char	*s = "Hello";

	printheader("ft_strlen");
	printf("\"%s\"  test: %zu  libc: %zu\n", s, ft_strlen(s), strlen(s));
}

void	test_mem(void)
{
	unsigned char	s[8];
	unsigned char	s1[8];

	printheader("ft_memset ft_memcpy");
	printf("test:\n");
	ft_bzero(s, 8);
	print_bytes(s, 8);
	ft_memset(s, 7, 4);
	print_bytes(s, 8);
	ft_memcpy(s1, s, 8);
	print_bytes(s1, 8);
	printf("libc:\n");
	bzero(s, 8);
	print_bytes(s, 8);
	memset(s, 7, 4);
	print_bytes(s, 8);
	memcpy(s1, s, 8);
	print_bytes(s1, 8);
}

void	test_memmove(void)
{
	char	s[11];
	int		i;

	printheader("ft_memmove");
	printf("test:\n");
	i = 0;
	while (i < 10)
	{
		s[i] = i + '0';
		i++;
	}
	s[10] = '\0';
	printf("%s\n", (char *) ft_memmove(s + 4, s + 2, 3));
	printf("%s\n", s);
	i = 0;
	while (i < 10)
	{
		s[i] = i + '0';
		i++;
	}
	s[10] = '\0';
	printf("%s\n", (char *) ft_memmove(s + 2, s + 4, 3));
	printf("%s\n", s);
	printf("libc:\n");
	i = 0;
	while (i < 10)
	{
		s[i] = i + '0';
		i++;
	}
	s[10] = '\0';
	printf("%s\n", (char *) memmove(s + 4, s + 2, 3));
	printf("%s\n", s);
	i = 0;
	while (i < 10)
	{
		s[i] = i + '0';
		i++;
	}
	s[10] = '\0';
	printf("%s\n", (char *) memmove(s + 2, s + 4, 3));
	printf("%s\n", s);
}

void	test_strlcpy(void)
{
	char	*src = "Hello!!!";
	char	dst[16];
	int		n;

	printheader("ft_strlcpy");
	n = ft_strlcpy(dst, src, 7);
	printf("test:  \"%s\" %d\n", dst, n);
	n = strlcpy(dst, src, 7);
	printf("libc:  \"%s\" %d\n", dst, n);
	n = ft_strlcpy(dst, src, 16);
	printf("test:  \"%s\" %d\n", dst, n);
	n = strlcpy(dst, src, 16);
	printf("libc:  \"%s\" %d\n", dst, n);
}

void	test_strlcat(void)
{
	char	*src = "world!!!!!!";
	char	dst0[32] = "Hello ";
	char	dst1[32] = "Hello ";
	char	dst2[32] = "Hello ";
	char	dst3[32] = "Hello ";
	size_t	n;

	printheader("ft_strlcat");
	printf("\"%s\" \"%s\" %zu %zu\n",
		dst0, src, ft_strlen(dst0), ft_strlen(src));
	n = ft_strlcat(dst0, src, 13);
	printf("test:  \"%s\" %zu %zu\n", dst0, n, ft_strlen(dst0));
	n = strlcat(dst1, src, 13);
	printf("libc:  \"%s\" %zu %zu\n", dst1, n, ft_strlen(dst1));
	n = ft_strlcat(dst2, src, 32);
	printf("test:  \"%s\" %zu %zu\n", dst2, n, ft_strlen(dst2));
	n = strlcat(dst3, src, 32);
	printf("libc:  \"%s\" %zu %zu\n", dst3, n, ft_strlen(dst3));
}

void	test_toupper_lower(void)
{
	int	c;

	printheader("ft_toupper ft_tolower");
	c = 33;
	while (c < 127)
	{
		printf("%c%c ", ft_toupper(c), ft_tolower(c));
		c++;
	}
	putchar('\n');
}

void	test_strchr(void)
{
	char	*s = "Go and find the needle in the haystack, my friend.";

	printheader("ft_strchr");
	printf("test:  %s\n", ft_strchr(s, 'f'));
	printf("libc:  %s\n", strchr(s, 'f'));
	printf("test:  %d\n", *ft_strchr(s, '\0'));
	printf("libc:  %d\n", *strchr(s, '\0'));
	printf("test:  %s\n", ft_strchr(s, 'x'));
	printf("libc:  %s\n", strchr(s, 'x'));
	printf("test:  %s\n", ft_strrchr(s, 'f'));
	printf("libc:  %s\n", strrchr(s, 'f'));
	printf("test:  %d\n", *ft_strrchr(s, '\0'));
	printf("libc:  %d\n", *strrchr(s, '\0'));
	printf("test:  %s\n", ft_strrchr(s, 'x'));
	printf("libc:  %s\n", strrchr(s, 'x'));
	printf("test:  %s\n", ft_strrchr(s, 'G'));
	printf("libc:  %s\n", strrchr(s, 'G'));
}

void	test_strncmp(void)
{
	char	*s1 = "Hello world!";
	char	*s2 = "Hello everyone!";
	int		n;

	printheader("ft_strncmp");
	n = 5;
	while (n <= 8)
	{
		printf("test:  \"%s\" \"%s\" %d %d\n", s1, s2, n, ft_strncmp(s1, s2, n));
		printf("libc:  \"%s\" \"%s\" %d %d\n", s1, s2, n, strncmp(s1, s2, n));
		n++;
	}
	printf("test:  \"%s\" \"%s\" %d %d\n", s1, s1, 16, ft_strncmp(s1, s2, 16));
	printf("libc:  \"%s\" \"%s\" %d %d\n", s1, s1, 16, strncmp(s1, s2, 16));
}

void	test_memchr(void)
{
	char	s[64] = "Go and find the needle in the haystack, my friend.";
	int		n;

	printheader("ft_memchr");
	n = 6;
	while (n <= 9)
	{
		printf("test:  %s\n", (char *) ft_memchr(s, 'f', n));
		printf("libc:  %s\n", (char *) memchr(s, 'f', n));
		n++;
	}
	printf("test:  %s\n", (char *) ft_memchr(s, 'x', 64));
	printf("libc:  %s\n", (char *) memchr(s, 'x', 64));
}

void	test_memcmp(void)
{
	char	s1[16] = "Hello world!";
	char	s2[16] = "Hello everyone!";
	int		n;

	printheader("ft_memcmp");
	n = 5;
	while (n <= 8)
	{
		printf("test:  \"%s\" \"%s\" %d %d\n", s1, s2, n, ft_memcmp(s1, s2, n));
		printf("libc:  \"%s\" \"%s\" %d %d\n", s1, s2, n, memcmp(s1, s2, n));
		n++;
	}
	printf("test:  \"%s\" \"%s\" %d %d\n", s1, s1, 16, ft_memcmp(s1, s2, 16));
	printf("libc:  \"%s\" \"%s\" %d %d\n", s1, s1, 16, memcmp(s1, s2, 16));
}

void	test_strnstr(void)
{
	int	n;

	printheader("ft_strnstr");
	n = 13;
	while (n <= 16)
	{
		printf("test:  \"%s\" %d\n", ft_strnstr("Find the needle in the haystack.", "needle", n), n);
		printf("libc:  \"%s\" %d\n", strnstr("Find the needle in the haystack.", "needle", n), n);
		n++;
	}
}

void	test_single_atoi(char *s)
{
	printf("\"%s\" %d\n", s, ft_atoi(s));
}

void	test_atoi(void)
{
	long	i;
	char	*s;

	printheader("ft_atoi");
	s = malloc(32);
	i = -2147483649;
	while (i <= -2147483647)
	{
		sprintf(s, " %ld", i);
		test_single_atoi(s);
		i++;
	}
	i = -20;
	while (i <= 20)
	{
		sprintf(s, "%+ld", i);
		test_single_atoi(s);
		i++;
	}
	i = 2147483646;
	while (i <= 2147483648)
	{
		sprintf(s, "  %ld", i);
		test_single_atoi(s);
		i++;
	}
	free(s);
	test_single_atoi("  --42 ");
	test_single_atoi("  --1337+42");
	putchar('\n');
}

void	test_calloc1(size_t nmemb, size_t size)
{
	unsigned char	*c;

	printf("test:  %zu %zu:  ", nmemb, size);
	c = ft_calloc(nmemb, size);
	if (!c)
		printf("NULL\n");
	else
	{
		print_bytes(c, nmemb * size);
		free(c);
	}
	printf("libc:  %zu %zu:  ", nmemb, size);
	c = calloc(nmemb, size);
	if (!c)
		printf("NULL\n");
	else
	{
		print_bytes(c, nmemb * size);
		free(c);
	}
}

void	test_calloc(void)
{
	printheader("ft_calloc");
	test_calloc1(4, 4);
	test_calloc1(0, 4);
}

int	main(void)
{
	test_isalpha();
	putchar('\n');
	test_strlen();
	putchar('\n');
	test_mem();
	putchar('\n');
	test_memmove();
	putchar('\n');
	test_strlcpy();
	putchar('\n');
	test_strlcat();
	putchar('\n');
	test_toupper_lower();
	putchar('\n');
	test_strchr();
	putchar('\n');
	test_strncmp();
	putchar('\n');
	test_memchr();
	putchar('\n');
	test_memcmp();
	putchar('\n');
	test_strnstr();
	putchar('\n');
	test_atoi();
	putchar('\n');
	test_calloc();
	return (0);
}
