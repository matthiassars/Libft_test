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
#include "libft/libft.h"
#include "test_utils.h"

static void	printcontent(void *content)
{
	char	*s;

	s = content;
	printf("%s ", s);
}

static void	printlst(t_list *lst)
{
	printf("{ ");
	ft_lstiter(lst, &printcontent);
	printf("}\n");
}

static void	*strtoupper(void *ptr)
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

static void	empty_fn(void *x)
{
	(void) x;
}

int	main(void)
{
	t_list	*lst;
	t_list	*lst1;

	printheader("test part 3: linked list");
	printf("\n");
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstnew");
	lst = ft_lstnew("world!");
	printlst(lst);
	printf("\n");
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstadd_front ft_lstiter");
	ft_lstadd_front(&lst, ft_lstnew("Hello"));
	printlst(lst);
	putchar('\n');
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstadd_back ft_lstiter");
	ft_lstadd_back(&lst, ft_lstnew("It's"));
	ft_lstadd_back(&lst, ft_lstnew("a"));
	ft_lstadd_back(&lst, ft_lstnew("beautiful"));
	ft_lstadd_back(&lst, ft_lstnew("day!"));
	printlst(lst);
	putchar('\n');
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstlast");
	printlst(ft_lstlast(lst));
	printf("\n");
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstsize");
	printf("%d\n\n", ft_lstsize(lst));
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstmap");
	lst1 = ft_lstmap(lst, strtoupper, free);
	printlst(lst1);
	putchar('\n');
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstclear");
	ft_lstclear(&lst, empty_fn);
	ft_lstclear(&lst1, free);
	printlst(lst);
	putchar('\n');
	///////////////////////////////////////////////////////////////////////////
	printheader("edge cases:");
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstadd_front");
	ft_lstadd_front(NULL, ft_lstnew("Hello"));
	ft_lstadd_front(&lst, ft_lstnew("Hello"));
	printlst(lst);
	ft_lstclear(&lst, empty_fn);
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstlast");
	printlst(ft_lstlast(NULL));
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstadd_back");
	ft_lstadd_back(NULL, ft_lstnew("Hello"));
	ft_lstadd_front(&lst, ft_lstnew("Hello"));
	printlst(lst);
	ft_lstclear(&lst, empty_fn);
	///////////////////////////////////////////////////////////////////////////
	printheader("ft_lstclear");
	ft_lstclear(NULL, empty_fn);
	///////////////////////////////////////////////////////////////////////////
	return (0);
}
