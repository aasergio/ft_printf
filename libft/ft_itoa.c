/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_itoa.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/12 14:24:56 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/12 17:49:12 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	nsize(int64_t n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static char	*recfill(int64_t n, char *str, size_t size)
{
	while (n > 0)
	{
		str[--size] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	size;
	int64_t	nb;

	nb = n;
	size = nsize(nb);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	str = recfill(nb, str, size);
	str[size] = '\0';
	return (str);
}
/*
int	main(int ac, char *dc[])
{
	char	*list;
	int		sigma;

	if (ac != 2)
		return (1);
	sigma = atoi(dc[1]);
	list = ft_itoa(sigma);
	printf(".\n\nsource: %d\n\n", sigma);
	printf("amount of chars: %zu\n\n", nsize(sigma));
	printf("result is: %s\n\n.\n", list);
	free(list);
	return (0);
}
*/
