/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strncmp.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 18:32:19 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/21 22:53:33 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && n > i)
	{
		if (s1[i] != s2[i])
			return (((unsigned char)s1[i] - (unsigned char)s2[i]));
		i++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *dc[])
{
  if (ac < 1)
    return (1);
  printf("%s\n%s\n%s\n\n", dc[1], dc[2], dc[3]);
  printf("%d", ft_strncmp(dc[1], dc[2], atoi(&dc[3][0])));
  return (0);
}
*/
