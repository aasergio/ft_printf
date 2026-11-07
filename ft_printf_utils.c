/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf_utils.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/03 01:40:10 by skaprash         #+#    #+#              */
/*   Updated: 2026/11/03 19:03:21 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_any(unsigned long n, char *system, int *res)
{
	unsigned long	s;

	s = ft_strlen(system);
	if (n >= s)
	{
		ft_putnbr_any((n / s), system, res);
		n = n % s;
	}
	write(1, &system[n], 1);
	*res += 1;
	return ;
}

void	ft_putchar_pr(char c, int *res)
{
	write(1, &c, 1);
	*res += 1;
	return ;
}

void	ft_putstr_pr(char *s, int *res)
{
	size_t	len;

	if (!s)
	{
		write(1, "(null)", 6);
		*res += 6;
		return ;
	}
	len = ft_strlen(s);
	write(1, s, len);
	*res += len;
	return ;
}

void	ft_putnbr_d(int n, int *res)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*res += 11;
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		*res += 1;
	}
	if (n >= 10)
	{
		ft_putnbr_d((n / 10), res);
		n = n % 10;
	}
	n += 48;
	write(1, &n, 1);
	*res += 1;
	return ;
}
/*
int	main(int ac, char *dc[])
{
	if (ac != 2)
		return (1);
	ft_putnbr_any(atoi(dc[1]), HEXUP);
	return (0);
}
*/
