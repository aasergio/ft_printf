/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strjoin.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/08 15:24:34 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/08 16:00:31 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;
	size_t	j;
	char	*res;

	dlen = ft_strlen(s1);
	slen = ft_strlen(s2);
	res = (char *)malloc((dlen + slen + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < dlen)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < slen)
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}
/*
#include <stdio.h>

int	main(int ac, char *dc[])
{
	if (ac < 3)
		return (1);
	printf("%s + %s\n", dc[1], dc[2]);
	printf("%s\n", ft_strjoin(dc[1], dc[2]));
	return (0);
}
*/
