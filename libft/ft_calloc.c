/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_calloc.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 18:12:52 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/20 14:42:24 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdint.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*list;

	i = 0;
	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	list = malloc(nmemb * size);
	if (!list)
		return (NULL);
	ft_bzero(list, nmemb * size);
	return (list);
}
/*
#include <stdio.h>

int	main(int ac, char *dc[])
{
	char	*cal;
	int		i;

	if (ac < 3)
		return (1);
	cal = ft_calloc(atoi(dc[1]), atoi(dc[2]));
	printf("%p\n", cal);
	i = 0;
	while (i++ < atoi(dc[1]))
		printf("%d\n", cal[i]);
	free(cal);
}
*/
