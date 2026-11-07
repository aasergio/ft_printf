/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstnew.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/18 13:37:41 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/18 18:37:14 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*str;

	str = malloc(sizeof(t_list));
	if (!str)
		return (NULL);
	str->content = content;
	str->next = NULL;
	return (str);
}
/*
int	main(int ac, char *dc[])
{
	t_list	*node1;

	if (ac != 2)
		return (1);
	node1 = ft_lstnew(dc[1]);
	printf("%s\n", (char *)node1->content);
	printf("%s\n", (char *)node1->next);
	free(node1);
	return (0);
}
*/
