#include "libft.h"
#include "test_utils.h"

static void	test_single_substr(char *s, unsigned int start, size_t len, char *expected)
{
	char	*subs;

	subs = ft_substr(s, start, len);
	printf("\"%s\" %d %ld  \"%s\"  ", s, start, len, subs);
	printok_ko(strcmp(subs, expected) == 0);
	free(subs);
}

static void	test_substr(void)
{
	printheader("ft_substr");
	test_single_substr("Hello world!!!!!!", 0, 64, "Hello world!!!!!!");
	test_single_substr("Hello world!!!!!!", 6, 6, "world!");
	test_single_substr("Hello world!!!!!!", 6, 2e9, "world!!!!!!");
	test_single_substr("Hello world!!!!!!", 6, 0, "");
	test_single_substr("Hello world!!!!!!", 32, 1, "");
	test_single_substr("Hello world!!!!!!", 2e9, 1, "");
	test_single_substr("Hello world", 10, 64, "d");
	test_single_substr("", 6, 64, "");
}

static void	test_strjoin(void)
{
	char	*s1 = "Hello ";
	char	*s2 = "world!";
	char	*dst;

	printheader("ft_strjoin");
	printf("\"%s\" \"%s\"\n", s1, s2);
	dst = ft_strjoin(s1, s2);
	printf("\"%s\"  ", dst);
	printok_ko(strcmp(dst, "Hello world!") == 0);
	free(dst);
}

static void	test_single_strtrim(char *s, char *set, char *expected)
{
	char	*dst;

	printf("\"%s\" \"%s\"\n", s, set);
	dst = ft_strtrim(s, set);
	printf("\"%s\"  ", dst);
	printok_ko(strcmp(dst, expected) == 0);
	free(dst);
}

static void	test_strtrim(void)
{
	printheader("ft_strtrim");
	test_single_strtrim("___-_Hello_world!!!--___", "_-", "Hello_world!!!");
	printf("\n");
	test_single_strtrim("___-_--___", "_-", "");
	printf("\n");
	test_single_strtrim("Hello_world!!!", "", "Hello_world!!!");
}

static void	test_single_split(char *s, char c, char *expected)
{
	char	**words;
	char	**word;
	char	split_str[32];

	ft_bzero(split_str, 32);
	words = ft_split(s, c);
	word = words;
	while (*word)
	{
		strcat(split_str, *word);
		strcat(split_str, " ");
		free(*word);
		word++;
	}
	if (isprint(c))
		printf("\"%s\" '%c'\n{ %s}  ", s, c, split_str);
	else
		printf("\"%s\" %d\n{ %s}  ", s, c, split_str);
	free(words);
	printok_ko(strcmp(split_str, expected) == 0);
}

static void	test_split(void)
{
	printheader("ft_split");
	test_single_split("___Hello__world!____", '_', "Hello world! ");
	printf("\n");
	test_single_split("___Hello__world!", '_', "Hello world! ");
	printf("\n");
	test_single_split("Hello__world!____", '_', "Hello world! ");
	printf("\n");
	test_single_split("_______", '_', "");
	printf("\n");
	test_single_split("", '_', "");
	printf("\n");
	test_single_split("___Hello__world!____", '\0', "___Hello__world!____ ");
}

static void	test_single_itoa(long n)
{
	char	*s;
	char	s1[12];

	s = ft_itoa(n);
	printf("%ld \"%s\"  ", n, s);
	sprintf(s1, "%d", (int) n);
	printok_ko(strcmp(s, s1) == 0);
	free(s);
}

static void	test_itoa_range(long min, long max)
{
	long	i;

	i = min;
	while (i <= max)
	{
		test_single_itoa(i);
		i++;
	}
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

static void	test_single_strmapi(char *s, char *expected)
{
	char	*fs;

	fs = ft_strmapi(s, f1);
	printf("\"%s\"  ", fs);
	printok_ko(strcmp(fs, expected) == 0);
	free(fs);
}

static void	test_strmapi(void)
{
	printheader("ft_strmapi");
	test_single_strmapi("Hello world!", "Hello WORLD!");
	test_single_strmapi("", "");
}

static void	f2(unsigned int i, char *c)
{
	if (i >= 5)
		*c = ft_toupper(*c);
}

static void	test_striteri(void)
{
	char	*s;

	printheader("ft_striteri");
	s = strdup("Hello world!!");
	ft_striteri(s, f2);
	printf("\"%s\"  ", s);
	printok_ko(strcmp(s, "Hello WORLD!!") == 0);
	free(s);
}

void	test_put(void)
{
	int		fd;
	char	text[128];

	printheader("ft_putchar_fd ft_putstr_fd fd_putendl_fd fd_putnbr_fd");
	fd = open("test_part2_out.txt", O_CREAT | O_WRONLY, 0644);
	ft_putchar_fd('!', fd);
	ft_putstr_fd("Hello ", fd);
	ft_putendl_fd("world!", fd);
	ft_putnbr_fd(-2147483648, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(-1337, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(0, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(1337, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(2147483647, fd);
	ft_putchar_fd('\0', fd);
	close(fd);
	fd = open("test_part2_out.txt", O_RDONLY);
	read(fd, text, 128);
	close(fd);
	printf("\"%s\"  ", text);
	printok_ko(strcmp(text, "!Hello world!\n"
			"-2147483648 -1337 0 1337 2147483647") == 0);
}

int	main(void)
{
	printheader("test part 2: additional functions");
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
	test_strmapi();
	putchar('\n');
	test_striteri();
	putchar('\n');
	test_put();
	return (0);
}
