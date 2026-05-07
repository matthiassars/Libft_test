/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_part1.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: msars <msars@student.42berlin.de>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/05 23:33:32 by msars            #+#    #+#              */
/*   Updated: 2026/05/07 11:31:27 by msars           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <bsd/string.h>
#include "libft/libft.h"
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
	printf("\"%s\"  libft: %zu  libc:  %zu\n", s, ft_strlen(s), strlen(s));
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
	n = ft_strlcpy(dst, src, 0);
	printf("libft:  %d\n", n);
	n = strlcpy(dst, src, 0);
	printf("libc:   %d\n", n);
	n = ft_strlcpy(dst, src, 1);
	printf("libft:  \"%s\" %d\n", dst, n);
	n = strlcpy(dst, src, 1);
	printf("libc:   \"%s\" %d\n", dst, n);
	n = ft_strlcpy(dst, src, 7);
	printf("libft:  \"%s\" %d\n", dst, n);
	n = strlcpy(dst, src, 7);
	printf("libc:   \"%s\" %d\n", dst, n);
	n = ft_strlcpy(dst, src, 16);
	printf("libft:  \"%s\" %d\n", dst, n);
	n = strlcpy(dst, src, 16);
	printf("libc:   \"%s\" %d\n", dst, n);
}

void	test_single_strlcat(char *dst, char *src, size_t size)
{
	char	dst1[32];
	size_t	n;

	memset(dst1, 'A', 32);
	strcpy(dst1, dst);
	n = ft_strlcat(dst1, src, size);
	printf("libft:  \"%s\" %zu %zu %zu\n", dst1, size, strlen(dst1), n);
	memset(dst1, 'A', 32);
	strcpy(dst1, dst);
	n = strlcat(dst1, src, size);
	printf("libc:   \"%s\" %zu %zu %zu\n", dst1, size, strlen(dst1), n);
}

void	test_strlcat(void)
{
	char	*dst = "Hello ";
	char	*src = "world!!!!!!";

	printheader("ft_strlcat");
	printf("\"Hello \" \"%s\"  %zu %zu\n", src,
		ft_strlen("Hello "), ft_strlen(src));
	test_single_strlcat(dst, src, 1);
	test_single_strlcat(dst, src, 7);
	test_single_strlcat(dst, src, 8);
	test_single_strlcat(dst, src, 13);
	test_single_strlcat(dst, src, 32);
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

void	test_single_strchr(char *s, int c)
{
	printf("'%c' %d\n", c, c);
	printf("libft:  \"%s\" \"%s\"\n", ft_strchr(s, c), ft_strrchr(s, c));
	printf("libc:   \"%s\" \"%s\"\n", strchr(s, c), strrchr(s, c));
}

void	test_strchr(void)
{
	char	*s = "Go and find the needle in the haystack, my friend.";

	printheader("ft_strchr ft_strrchr");
	test_single_strchr(s, 'f');
	test_single_strchr(s, '\0');
	test_single_strchr(s, 'x');
	test_single_strchr(s, 'G');
	test_single_strchr(s, '.');
	test_single_strchr(s, 'f' + 256);
	test_single_strchr(s, 1024);
	test_single_strchr("", 'x');
}

void	test_single_strncmp(char *s1, char *s2, size_t n)
{
	printf("libft:  \"%s\" \"%s\" %lu %u\n", s1, s2, n, ft_strncmp(s1, s2, n));
	printf("libc:   \"%s\" \"%s\" %lu %u\n", s1, s2, n, strncmp(s1, s2, n));
}

void	test_strncmp(void)
{
	printheader("ft_strncmp");
	test_single_strncmp("Hello world!", "Hello everyone!", 0);
	test_single_strncmp("Hello world!", "Hello everyone!", 6);
	test_single_strncmp("Hello world!", "Hello everyone!", 7);
	test_single_strncmp("Hello world!", "Hello everyone!", 16);
	test_single_strncmp("Hello!\x80", "Hello!\0", 7);
}

void	test_single_memchr(void *s, int c, size_t n)
{
	printf("libft:  \"%s\"\n", (char *) ft_memchr(s, c, n));
	printf("libc:   \"%s\"\n", (char *) memchr(s, c, n));
}

void	test_memchr(void)
{
	char	s[64] = "Go and find the needle in the haystack, my friend.";

	printheader("ft_memchr");
	test_single_memchr(s, 'f', 7);
	test_single_memchr(s, 'f', 8);
	test_single_memchr(s, 'G', 1);
	test_single_memchr(s, 'G', 0);
	test_single_memchr(s, '\0', 64);
	test_single_memchr("", 'x', 1);
}

void	test_single_memcmp(char *s1, char *s2, size_t n)
{
	printf("libft:  \"%s\" \"%s\" %lu %u\n", s1, s2, n, ft_memcmp(s1, s2, n));
	printf("libc:   \"%s\" \"%s\" %lu %u\n", s1, s2, n, memcmp(s1, s2, n));
}

void	test_memcmp(void)
{
	printheader("ft_memcmp");
	test_single_memcmp("Hello world!", "Hello everyone!", 0);
	test_single_memcmp("Hello world!", "Hello everyone!", 6);
	test_single_memcmp("Hello world!", "Hello everyone!", 7);
	test_single_memcmp("Hello world!", "Hello everyone!", 16);
}

void	test_single_strnstr(size_t n)
{
	printf("libft:  \"%s\" %ld\n", ft_strnstr("Find the needle in the haystack.", "needle", n), n);
	printf("libc:   \"%s\" %ld\n", strnstr("Find the needle in the haystack.", "needle", n), n);
}

void	test_strnstr(void)
{
	printheader("ft_strnstr");
	test_single_strnstr(0);
	test_single_strnstr(14);
	test_single_strnstr(15);
}

void	test_single_atoi(char *s)
{
	printf("\"%s\" %d  ", s, ft_atoi(s));
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
	printf("\n");
	i = -20;
	while (i <= 20)
	{
		sprintf(s, "%+ld", i);
		test_single_atoi(s);
		i++;
	}
	printf("\n");
	i = 2147483646;
	while (i <= 2147483648)
	{
		sprintf(s, "  %ld", i);
		test_single_atoi(s);
		i++;
	}
	printf("\n");
	free(s);
	test_single_atoi("  --42 ");
	test_single_atoi("  --1337+42");
	printf("\n");
}

void	test_single_calloc(size_t nmemb, size_t size)
{
	unsigned char	*c;

	printf("libft:  %zu %zu:  ", nmemb, size);
	c = ft_calloc(nmemb, size);
	if (!c)
		printf("NULL\n");
	else
	{
		print_bytes(c, nmemb * size);
		free(c);
	}
	printf("libc:   %zu %zu:  ", nmemb, size);
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
	test_single_calloc(4, 4);
	test_single_calloc(0, 4);
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
