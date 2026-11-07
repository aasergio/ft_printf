/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 18:34:19 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/07 18:35:35 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;

	ptr = (const unsigned char *)s;
	while (n)
	{
		if (*ptr == (const unsigned char)c)
			return ((void *)ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
/*
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *dc[])
{
  if (ac < 3)
    return (1);
  printf("%s\n", (char *)ft_memchr((const void *)dc[1], dc[2][0], atoi(dc[3])));
  printf("%p\n", (char *)ft_memchr((const void *)dc[1], dc[2][0], atoi(dc[3])));
  return (0);
}
*/
