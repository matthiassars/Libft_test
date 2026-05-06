/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_part3.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: msars <msars@student.42berlin.de>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/05 11:38:41 by msars            #+#    #+#              */
/*   Updated: 2026/05/06 10:08:56 by msars           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include "Libft/libft.h"
#include "test_utils.h"

void	printlstitem(void *content)
{
	char	*s;

	s = content;
	printf("%s ", s);
}

void	printlst(t_list *lst)
{
	printf("{ ");
	ft_lstiter(lst, &printlstitem);
	printf("}\n");
}

void	*strtoupper(void *ptr)
{
	char	*str;
	char	*newstr;
	char	*newstrptr;

	str = ptr;
	newstr = malloc(strlen(str) + 1);
	newstrptr = newstr;
	while (*str)
	{
		*newstrptr = toupper(*str);
		newstrptr++;
		str++;
	}
	*newstrptr = '\0';
	return (newstr);
}

void	del(void *x)
{
	(void) x;
}

int	main(void)
{
	char	*s0 = "Hello";
	char	*s1 = "world!";
	char	*s2 = "It's";
	char	*s3 = "a";
	char	*s4 = "beautiful";
	char	*s5 = "day!";
	t_list	*lst;
	t_list	*lst1;

	printheader("ft_lstnew [ft_lstiter]");
	lst = ft_lstnew(s1);
	printlst(lst);
	putchar('\n');
	printheader("ft_lstadd_front [ft_lstiter]");
	ft_lstadd_front(&lst, ft_lstnew(s0));
	printlst(lst);
	putchar('\n');
	printheader("ft_lstadd_back [ft_lstiter]");
	ft_lstadd_back(&lst, ft_lstnew(s2));
	ft_lstadd_back(&lst, ft_lstnew(s3));
	ft_lstadd_back(&lst, ft_lstnew(s4));
	ft_lstadd_back(&lst, ft_lstnew(s5));
	printlst(lst);
	putchar('\n');
	printheader("ft_lstlast");
	printlst(ft_lstlast(lst));
	putchar('\n');
	printheader("ft_lstsize");
	printf("%d\n\n", ft_lstsize(lst));
	printheader("ft_lstmap");
	lst1 = ft_lstmap(lst, strtoupper, del);
	printlst(lst1);
	putchar('\n');
	printheader("ft_lstclear");
	ft_lstclear(&lst, del);
	ft_lstclear(&lst1, del);
	printlst(lst);
	return (0);
}
