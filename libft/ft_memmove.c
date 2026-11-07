/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memmove.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 18:20:38 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/07 18:21:11 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*ptrd;
	unsigned char	*ptrs;

	ptrd = (unsigned char *)dest;
	ptrs = (unsigned char *)src;
	if (dest < src)
	{
		i = 0;
		while (i < n)
		{
			ptrd[i] = ptrs[i];
			i++;
		}
	}
	else if (src < dest)
	{
		i = n;
		while (i > 0)
		{
			i--;
			ptrd[i] = ptrs[i];
		}
	}
	return (ptrd);
}
/*
int	main(int ac, char **dc)
{
	if (ac < 3)
		return (1);
	int		d = atoi(&dc[1][0]);
	int		s = atoi(&dc[2][0]);
	int		n = atoi(&dc[3][0]);
	char	list[] = "abcdefg";
	char	list2[] = "abcdefg";
	char	*dest = &list[d];
	char	*src = &list[s];
	char    *dest2 = &list2[d];
    char    *src2 = &list2[s];

	printf("abcdefg\n");
	printf("%s\n", memmove(dest, src, n));
	printf("%s\n\n", list);
	printf("abcdefg\n");
	printf("%s\n", ft_memmove(dest2, src2, n));
	printf("%s\n", list2);
}
*/
