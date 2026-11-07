/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 18:28:04 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/07 18:29:26 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}
/*
#include <stdio.h>

int main(int ac, char *dc[])
{
  if (ac < 1)
    return (1);
  printf("%s\n", ft_strchr(dc[1], 'c'));
  printf("%p\n", ft_strchr(dc[1], 'c'));
  return (0);
}
*/
