/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_striteri.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/18 11:58:05 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/20 17:36:49 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return ;
}
/*
static void	ft_test(unsigned int i, char *s)
{
	s[i]++;
	return ;
}

int	main(int ac, char *dc[])
{
	char	*str;

	if (ac != 2)
		return (1);
	str = dc[1];
	ft_striteri(str, ft_test);
	printf("%s\n", str);
	return (0);
}
*/
