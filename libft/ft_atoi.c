/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_atoi.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 18:39:23 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/20 17:43:08 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	minus;
	int	sum;

	i = 0;
	minus = 1;
	sum = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		minus *= -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		sum = (sum * 10) + (nptr[i] - '0');
		i++;
	}
	return (minus * sum);
}
/*
#include <stdio.h>

int	main(int ac, char **dc)
{
	if (ac != 2)
		return (1);
	printf("%s \n", dc[1]);
	printf("%d", ft_atoi(dc[1]));
}
*/
