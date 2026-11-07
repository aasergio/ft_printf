/* ************************************************************************** */
/*																			  */
/*														 :::	  ::::::::	  */
/*	 ft_strlcpy.c									   :+:		:+:    :+:	  */
/*													 +:+ +:+		 +:+	  */
/*	 By: skaprash <skaprash@student.42.fr>		   #+#	+:+		  +#+		  */
/*												 +#+#+#+#+#+   +#+			  */
/*	 Created: 2026/10/07 18:21:53 by skaprash		  #+#	 #+#			  */
/*   Updated: 2026/10/07 18:25:11 by skaprash        ###   ########.fr        */
/*																			  */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <stdio.h>
#include <unistd.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && size - 1 > i)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

/*
int main(void)
{
	char *src = "coucou";
	char dest[10] = "AAAAAAAAAA";
	int i = 0;
	i = ft_strlcpy(dest, src, 0);
	printf("%s\n", dest);
}
*/
