/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strlcat.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 18:26:28 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/21 23:29:08 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dsize;
	size_t	ssize;
	size_t	i;

	ssize = ft_strlen(src);
	if (size == 0)
		return (ssize);
	dsize = ft_strlen(dest);
	if (dsize >= size)
		return (ssize + size);
	i = dsize;
	while ((i < (size - 1)) && *src)
	{
		dest[i] = *src++;
		i++;
	}
	dest[i] = '\0';
	return (dsize + ssize);
}
