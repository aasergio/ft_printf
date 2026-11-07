/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strrchr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 18:30:21 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/07 18:31:17 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (c == '\0')
		return ((char *)&s[i]);
	while (i != -1)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (0);
}
/*
#include <stdio.h>

int main(int ac, char *dc[])
{
  if (ac < 1)
    return (1);
  printf("%s\n", ft_strrchr(dc[1], 'c'));
  printf("%p\n", ft_strrchr(dc[1], 'c'));
  return (0);
}
*/
