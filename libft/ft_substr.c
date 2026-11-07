/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_substr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 21:39:40 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/07 22:08:59 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*str;

	if (!s || !len)
		return (ft_strdup(""));
	slen = ft_strlen(s);
	if ((slen - start) < len)
		len = (slen - start);
	if (start > slen)
		return (ft_strdup(""));
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main(int ac, char *dc[])
{
	char	*str;

	if (ac < 4)
		return (1);
	str = ft_substr(dc[1], atoi(dc[2]), atoi(dc[3]));
	printf("%s\n", dc[1]);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
