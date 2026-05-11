/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_part3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msars <msars@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 11:38:41 by msars             #+#    #+#             */
/*   Updated: 2026/05/11 12:41:42 by msars            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "libft/libft.h"
#include "test_utils.h"

static void	sprintlst(char *s, t_list *lst)
{
	sprintf(s, "{ ");
	while (lst)
	{
		strcat(s, (char *) lst->content);
		strcat(s, " ");
		lst = lst->next;
	}
	strcat(s, "}");
	printf("%s  ", s);
}

static void	upcase(void *ptr)
{
	char	*c;

	c = ptr;
	while (*c)
	{
		*c = toupper(*c);
		c++;
	}
}

static void	*capitalize(void *ptr)
{
	char	*str;
	char	*newstr;
	char	*newstrptr;

	str = ptr;
	newstr = malloc(strlen(str) + 1);
	if (*str == '\0')
	{
		*newstr = '\0';
		return (newstr);
	}
	newstrptr = newstr;
	*newstrptr = toupper(*str);
	newstrptr++;
	str++;
	while (*str)
	{
		*newstrptr = tolower(*str);
		newstrptr++;
		str++;
	}
	*newstrptr = '\0';
	return (newstr);
}

static void	noop(void *x)
{
	(void) x;
}

int	main(void)
{
	t_list	*lst;
	t_list	*lst1;
	char	*s;
	char	*print_str;

	s = malloc(128);
	print_str = malloc(128);
	strcpy(s, "Hello");
	strcpy(s + 16, "world!");
	strcpy(s + 32, "It's");
	strcpy(s + 48, "a");
	strcpy(s + 64, "beautiful");
	strcpy(s + 80, "day!");
	printheader("test part 3: linked list");
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstnew");
	lst = ft_lstnew(s + 16);
	sprintlst(print_str, lst);
	printok_ko(strcmp(print_str, "{ world! }") == 0);
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstadd_front");
	ft_lstadd_front(&lst, ft_lstnew(s));
	sprintlst(print_str, lst);
	printok_ko(strcmp(print_str, "{ Hello world! }") == 0);
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstadd_back");
	ft_lstadd_back(&lst, ft_lstnew(s + 32));
	ft_lstadd_back(&lst, ft_lstnew(s + 48));
	ft_lstadd_back(&lst, ft_lstnew(s + 64));
	ft_lstadd_back(&lst, ft_lstnew(s + 80));
	sprintlst(print_str, lst);
	printok_ko(strcmp(print_str, "{ Hello world! It's a beautiful day! }") == 0);
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstlast");
	sprintlst(print_str, ft_lstlast(lst));
	printok_ko(strcmp(print_str, "{ day! }") == 0);
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstsize");
	printf("%d  ", ft_lstsize(lst));
	printok_ko(ft_lstsize(lst) == 6);
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstiter");
	ft_lstiter(lst, upcase);
	sprintlst(print_str, lst);
	printok_ko(strcmp(print_str, "{ HELLO WORLD! IT'S A BEAUTIFUL DAY! }") == 0);
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstmap");
	lst1 = ft_lstmap(lst, capitalize, free);
	sprintlst(print_str, lst1);
	printok_ko(strcmp(print_str, "{ Hello World! It's A Beautiful Day! }") == 0);
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstclear");
	ft_lstclear(&lst, noop);
	ft_lstclear(&lst1, free);
	sprintlst(print_str, lst);
	printok_ko(strcmp(print_str, "{ }") == 0);
	sprintlst(print_str, lst1);
	printok_ko(strcmp(print_str, "{ }") == 0);
	///////////////////////////////////////////////////////////////////////////
	putchar('\n');
	printheader("edge cases:");
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstadd_front");
	lst = ft_lstnew("Hello");
	ft_lstadd_front(NULL, lst);
	printok_ko(1);
	///////////////////////////////////////////////////////////////////////////
	strcpy(s, "Hello");
	ft_lstclear(&lst, noop);
	ft_lstadd_front(&lst, ft_lstnew(s));
	sprintlst(print_str, lst);
	printok_ko(strcmp(print_str, "{ Hello }") == 0);
	ft_lstclear(&lst, noop);
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstlast");
	sprintlst(print_str, ft_lstlast(NULL));
	printok_ko(strcmp(print_str, "{ }") == 0);
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstadd_back");
	lst = ft_lstnew(s);
	ft_lstadd_back(NULL, lst);
	printok_ko(1);
	///////////////////////////////////////////////////////////////////////////
	ft_lstclear(&lst, noop);
	ft_lstclear(&lst1, noop);
	lst1 = ft_lstnew(s);
	ft_lstadd_front(&lst, lst1);
	sprintlst(print_str, lst);
	printok_ko(strcmp(print_str, "{ Hello }") == 0);
	ft_lstclear(&lst, noop);
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstclear");
	ft_lstclear(NULL, noop);
	printok_ko(1);
	///////////////////////////////////////////////////////////////////////////
	free(s);
	free(print_str);
	return (0);
}
