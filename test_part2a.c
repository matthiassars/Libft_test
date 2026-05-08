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

#include "libft/libft.h"

int	main(void)
{
	ft_putendl_fd("----  test part 2a: additional functions: output functions  --------------------", 1);
	ft_putnbr_fd(-2147483648, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(-1337, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(0, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(1337, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(2147483647, 1);
	ft_putchar_fd('\n', 1);
	return (0);
}
