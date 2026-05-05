/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   test_part3.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: msars <msars@student.42berlin.de>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/05/05 11:38:41 by msars            #+#    #+#              */
/*   Updated: 2026/05/05 18:48:18 by msars           ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "Libft/libft.h"
#include "test_utils.h"

void	printlstitem(void *content)
{
	char	*s;

	s = content;
	ft_putstr_fd(s, 1);
	ft_putchar_fd(' ', 1);
}

void	printlst(t_list *lst)
{
	ft_putstr_fd("{ ", 1);
	ft_lstiter(lst, &printlstitem);
	ft_putstr_fd("}\n", 1);
}

void	*strtoupper(void *ptr)
{
	char	*str;
	char	*newstr;
	char	*newstrptr;

	str = ptr;
	newstr = malloc(ft_strlen(str) + 1);
	newstrptr = newstr;
	while (*str)
	{
		*newstrptr = ft_toupper(*str);
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

	printheader("ft_lstnew");
	lst = ft_lstnew(s1);
	printlst(lst);
	putchar('\n');
	printheader("ft_lstadd_front");
	ft_lstadd_front(&lst, ft_lstnew(s0));
	printlst(lst);
	putchar('\n');
	printheader("ft_lstadd_back");
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
	ft_putnbr_fd(ft_lstsize(lst), 1);
	ft_putchar_fd('\n', 1);
	putchar('\n');
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
