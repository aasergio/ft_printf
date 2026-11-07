/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/11 15:23:47 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/21 23:05:00 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static size_t	el_primo(char *s, char c)
{
	size_t	i;
	size_t	word;
	size_t	result;

	word = 1;
	result = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (word == 1 && s[i] != c)
		{
			result++;
			word = 0;
		}
		else if (word != 1 && s[i] == c)
			word = 1;
		i++;
	}
	return (result);
}

static char	**freeall(char **str, int j)
{
	while (j >= 0)
	{
		free(str[j]);
		j--;
	}
	free(str);
	return (NULL);
}

static char	**body(char **str, size_t words, char const *s, char c)
{
	size_t	wsize;
	size_t	i;
	size_t	j;
	size_t	j2;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		wsize = 0;
		j2 = 0;
		while (s[i + wsize] != c && s[i + wsize] != '\0')
			wsize++;
		str[j] = malloc((wsize + 1) * sizeof(char));
		if (!str[j])
			return (freeall(str, j));
		while (j2 < wsize)
			str[j][j2++] = s[i++];
		str[j][j2] = '\0';
		j++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	char	**str;

	if (!s)
		return (NULL);
	words = el_primo((char *)s, c);
	str = malloc((words + 1) * sizeof(char *));
	return (body(str, words, s, c));
}
/*
int	main(int ac, char *dc[])
{
	char	**list;
	size_t	i;

	if (ac != 3)
		return (1);
	printf("words - %zu\n\n", el_primo(dc[1], dc[2][0]));
	list = ft_split(dc[1], dc[2][0]);
	i = 0;
	while (list[i] != NULL)
	{
		printf("%zu - %s\n", i, list[i]);
		i++;
	}
	i = 0;
	while (list[i++] != NULL)
		free(list[i]);
	free(list);
	return (0);
}
*/
