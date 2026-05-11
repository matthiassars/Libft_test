/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_part1.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: msars <msars@student.42berlin.de>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/05 23:33:32 by msars            #+#    #+#              */
/*   Updated: 2026/05/11 11:02:18 by msars           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "test_utils.h"

static void	print_bytes(unsigned char *a, size_t n)
{
	size_t	i;
	size_t	max;

	i = 0;
	if (n > 16)
		max = 16;
	else
		max = n;
	printf("{ ");
	while (i < max)
	{
		printf("%d ", a[i]);
		i++;
	}
	if (n > 16)
		printf("... ");
	putchar('}');
}

static int	cmp_sgn(int x, int y)
{
	if (x < 0 && y < 0)
		return (1);
	if (x == 0 && y == 0)
		return (1);
	if (x > 0 && y > 0)
		return (1);
	return (0);
}

static void	test_single__char_class(int c)
{
	printf("%4d ", c);
	if (isprint(c))
		printf("'%c'", c);
	else
		printf("   ");
	printf(" %d  %d  %d  %d  %d  ",
		ft_isalpha(c), ft_isdigit(c), ft_isalnum(c), ft_isascii(c), ft_isprint(c));
	printok_ko(ft_isalpha(c) == !!isalpha(c)
		&& ft_isalpha(c) == !!isalpha(c)
	&& ft_isdigit(c) == !!isdigit(c)
	&& ft_isalnum(c) == !!isalnum(c)
	&& ft_isascii(c) == !!isascii(c)
	&& ft_isprint(c) == !!isprint(c));
}

static void	test_char_class(void)
{
	printheader("ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_isprint");
	printf("         al dg an as pr\n");
	test_single__char_class(-1);
	test_single__char_class('\0');
	test_single__char_class('#');
	test_single__char_class('7');
	test_single__char_class('s');
	test_single__char_class('S');
	test_single__char_class('s' + 256);
	test_single__char_class(1024);
}

static void	test_strlen(void)
{
	char	*s = "Hello";

	printheader("ft_strlen");
	printf("\"%s\" %zu  ", s, ft_strlen(s));
	printok_ko(ft_strlen(s) == strlen(s));
}

static void	test_mem(void)
{
	unsigned char	s[8];
	unsigned char	s1[8];
	unsigned char	t[8];
	unsigned char	t1[8];

	printheader("ft_bzero ft_memset ft_memcpy");
	ft_bzero(s, 8);
	bzero(t, 8);
	print_bytes(s, 8);
	printf("  ");
	printok_ko(memcmp(s, t, 8) == 0);
	ft_memset(s, 7, 4);
	memset(t, 7, 4);
	print_bytes(s, 8);
	printf("  ");
	printok_ko(memcmp(s, t, 8) == 0);
	ft_memcpy(s1, s, 8);
	memcpy(t1, t, 8);
	print_bytes(s1, 8);
	printf("  ");
	printok_ko(memcmp(s1, t1, 8) == 0);
}

static void	test_single_memmove(char *str, int dst_i, int src_i, size_t n)
{
	char	s[11];
	char	s1[11];
	char	*ptr;
	char	*ptr1;

	strcpy(s, str);
	strcpy(s1, str);
	printf("%s %d %d %zu  ", s, dst_i, src_i, n);
	ptr = (char *) ft_memmove(s + dst_i, s + src_i, n);
	ptr1 = (char *) memmove(s1 + dst_i, s1 + src_i, n);
	printf("%s ", ptr);
	printf("%s  ", s);
	printok_ko(strcmp(s, s1) == 0 && strcmp(ptr, ptr1) == 0);
}

static void	test_memmove(void)
{
	printheader("ft_memmove");
	test_single_memmove("0123456789", 4, 2, 3);
	test_single_memmove("0123456789", 2, 4, 3);
}

static void	test_single_strlcpy(char *src, size_t size)
{
	char	dst[16];
	char	dst1[16];
	size_t	n;
	size_t	n1;

	printf("\"%s\" %zu ", src, size);
	n = ft_strlcpy(dst, src, size);
	n1 = strlcpy(dst1, src, size);
	if (size > 0)
		printf("\"%s\" ", dst);
	printf("%zu  ", n);
	printok_ko(n == n1 && (strncmp(dst, dst1, size) == 0));
}

static void	test_strlcpy(void)
{
	char	*src = "Hello!!!";

	printheader("ft_strlcpy");
	test_single_strlcpy(src, 0);
	test_single_strlcpy(src, 1);
	test_single_strlcpy(src, 7);
	test_single_strlcpy(src, 16);
}

static void	test_single_strlcat(char *dst, char *src, size_t size)
{
	char	dst1[32];
	char	dst2[32];
	size_t	n1;
	size_t	n2;

	memset(dst1, 'A', 32);
	memset(dst2, 'A', 32);
	strcpy(dst1, dst);
	strcpy(dst2, dst);
	n1 = ft_strlcat(dst1, src, size);
	n2 = strlcat(dst2, src, size);
	printf("\"%s\" %zu  ", dst1, n1);
	printok_ko(n1 == n2 && strcmp(dst1, dst2) == 0);
}

static void	test_strlcat(void)
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

static void	test_single_toupper_lower(int c)
{
	printf("%c%c  ", ft_toupper(c), ft_tolower(c));
	printok_ko(ft_toupper(c) == toupper(c) && tolower(c) == tolower(c));
}

static void	test_toupper_lower(void)
{
	printheader("ft_toupper ft_tolower");
	test_single_toupper_lower('#');
	test_single_toupper_lower('S');
	test_single_toupper_lower('s');
}

static void	test_single_strchr(char *s, int c)
{
	printf("'%c' %d  \"%s\" \"%s\"  ", c, c, ft_strchr(s, c), ft_strrchr(s, c));
	printok_ko((ft_strchr(s, c) == strchr(s, c))
		&& (ft_strrchr(s, c) == strrchr(s, c)));
}

static void	test_strchr(void)
{
	char	*s = "Go and find the needle in the haystack, my friend.";

	printheader("ft_strchr ft_strrchr");
	printf("\"%s\"\n", s);
	test_single_strchr(s, 'f');
	test_single_strchr(s, '\0');
	test_single_strchr(s, 'x');
	test_single_strchr(s, 'G');
	test_single_strchr(s, '.');
	test_single_strchr(s, 'f' + 256);
	test_single_strchr(s, 1024);
	test_single_strchr("", 'x');
}

static void	test_single_strncmp(const char *s1, const char *s2, size_t n)
{
	printf("\"%s\" \"%s\" %lu  %d  ",
		s1, s2, n, ft_strncmp(s1, s2, n));
	printok_ko(cmp_sgn(ft_strncmp(s1, s2, n), strncmp(s1, s2, n)));
}

static void	test_strncmp(void)
{
	printheader("ft_strncmp");
	test_single_strncmp("Hello world!", "Hello everyone!", 0);
	test_single_strncmp("Hello world!", "Hello everyone!", 6);
	test_single_strncmp("Hello world!", "Hello everyone!", 7);
	test_single_strncmp("Hello world!", "Hello everyone!", 16);
	test_single_strncmp("Hello!\x80", "Hello!\x00", 7);
}

static void	test_single_memchr(void *s, int c, size_t n)
{
	printf("%zu  \"%s\"  ", n, (char *) ft_memchr(s, c, n));
	printok_ko(ft_memchr(s, c, n) == memchr(s, c, n));
}

static void	test_memchr(void)
{
	char	s[64] = "Go and find the needle in the haystack, my friend.";

	printheader("ft_memchr");
	printf("\"%s\"\n", s);
	test_single_memchr(s, 'f', 7);
	test_single_memchr(s, 'f', 8);
	test_single_memchr(s, 'G', 1);
	test_single_memchr(s, 'G', 0);
	test_single_memchr(s, '\0', 64);
	test_single_memchr("", 'x', 1);
}

static void	test_single_memcmp(char *s1, char *s2, size_t n)
{
	printf("\"%s\" \"%s\" %lu  %d  ",
		s1, s2, n, ft_strncmp(s1, s2, n));
	printok_ko(cmp_sgn(ft_strncmp(s1, s2, n), strncmp(s1, s2, n)));
}

static void	test_memcmp(void)
{
	printheader("ft_memcmp");
	test_single_memcmp("Hello world!", "Hello everyone!", 0);
	test_single_memcmp("Hello world!", "Hello everyone!", 6);
	test_single_memcmp("Hello world!", "Hello everyone!", 7);
	test_single_memcmp("Hello world!", "Hello everyone!", 16);
}

static void	test_single_strnstr(char *big, char *little, size_t n)
{
	printf("%zu  \"%s\"  ", n, ft_strnstr(big, little, n));
	printok_ko(ft_strnstr(big, little, n) == strnstr(big, little, n));
}

static void	test_strnstr(void)
{
	char	*big = "Find the needle in the haystack.";
	char	*little = "needle";

	printheader("ft_strnstr");
	printf("\"%s\" \"%s\"\n", big, little);
	test_single_strnstr(big, little, 0);
	test_single_strnstr(big, little, 14);
	test_single_strnstr(big, little, 15);
}

static void	test_single_atoi(char *s)
{
	printf("\"%s\" %d  ", s, ft_atoi(s));
	printok_ko(ft_atoi(s) == atoi(s));
}

static void	test_atoi(void)
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
	printf("\n");
}

static void	test_single_calloc(size_t nmemb, size_t size)
{
	unsigned char	*c;
	unsigned char	*c1;
	size_t			tot_size;

	tot_size = nmemb * size;
	printf("%zu %zu:  ", nmemb, size);
	c = ft_calloc(nmemb, size);
	if (!c)
	{
		if (tot_size == 0)
			printok_ko(0);
		else
			printok_ko(1);
		return ;
	}
	c1 = calloc(nmemb, size);
	if (!c)
	{
		free(c);
		return ;
	}
	print_bytes(c, tot_size);
	printf("  ");
	printok_ko(memcmp(c, c1, tot_size) == 0);
	free(c);
	free(c1);
}

static void	test_calloc(void)
{
	printheader("ft_calloc");
	test_single_calloc(4, 4);
	test_single_calloc(0, 4);
	test_single_calloc(1e9, 1e9);
	test_single_calloc(SIZE_MAX, SIZE_MAX);
	test_single_calloc(-5, -5);
}

static void	test_strdup(void)
{
	char	*s;
	char	*s1;

	printheader("ft_strdup");
	s = ft_strdup("Hello world!");
	if (!s)
	{
		putchar('\n');
		return ;
	}
	printf("\"%s\"  ", s);
	s1 = strdup("Hello world!");
	if (!s1)
	{
		putchar('\n');
		free(s);
		return ;
	}
	printok_ko(strcmp(s, s1) == 0);
	free(s);
	free(s1);
}

int	main(void)
{
	printheader("test part 1: libc functions");
	test_char_class();
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
	putchar('\n');
	test_strdup();
	putchar('\n');
	return (0);
}
