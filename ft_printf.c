/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_printf.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/30 15:30:48 by skaprash         #+#    #+#              */
/*   Updated: 2026/11/03 19:04:08 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static void	ft_pointer(va_list args, int *res)
{
	void	*argument;

	argument = va_arg(args, void *);
	if (argument != NULL)
	{
		write(1, "0x", 2);
		*res += 2;
		ft_putnbr_any((uintptr_t)argument, HEXLOW, res);
	}
	else
	{
		write(1, "(nil)", 5);
		*res += 5;
	}
	return ;
}

static void	ft_letter(char c, va_list args, int *res)
{
	if (c == 'c')
		ft_putchar_pr(va_arg(args, int), res);
	else if (c == 's')
		ft_putstr_pr(va_arg(args, char *), res);
	else if (c == 'p')
		ft_pointer(args, res);
	else if (c == 'd' || c == 'i')
		ft_putnbr_d(va_arg(args, int), res);
	else if (c == 'u')
		ft_putnbr_any(va_arg(args, unsigned int), DEC, res);
	else if (c == 'x')
		ft_putnbr_any(va_arg(args, unsigned int), HEXLOW, res);
	else if (c == 'X')
		ft_putnbr_any(va_arg(args, unsigned int), HEXUP, res);
	else if (c == '%')
	{
		write(1, "%", 1);
		*res += 1;
	}
	return ;
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	i;
	int		res;

	res = 0;
	va_start(args, s);
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			if (s[i + 1] == '\0')
				break ;
			ft_letter(s[++i], args, &res);
		}
		else if (s[i] != '\0')
		{
			write(1, &s[i], 1);
			res += 1;
		}
		i++;
	}
	va_end(args);
	return (res);
}
/*
#include <stdio.h>

int	main(int ac, char *dc[])
{
	int	i;

	if (ac < 2)
		return (1);
	i = 0;
	i = printf("mama help - %s\n", dc[1]);
	printf("%d\n", i);
	i = ft_printf("mama help - %s\n", dc[1]);
	printf("%d\n", i);
	return (0);
}
*/
