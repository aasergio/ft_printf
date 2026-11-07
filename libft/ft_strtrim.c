/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strtrim.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/08 20:36:57 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/20 17:13:23 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	isit(char c, char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && c != '\0')
	{
		if (c == s[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (s1[i] && isit(s1[i], (char *)set) == 1)
		i++;
	start = i;
	i = ft_strlen(s1);
	while (i > start && (isit(s1[i - 1], (char *)set) == 1))
		i--;
	end = i;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (i < end)
		str[j++] = s1[i++];
	str[j] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main()
{
	char *ret = ft_strtrim("   xxxtripouille", " x");

	printf(": annihilate all the \n");
	printf("%s\n", ret);
	free(ret);
	return (0);
}
*/
