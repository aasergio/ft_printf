/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstdelone.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 12:55:19 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/19 14:34:07 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
	return ;
}
/*
static void	ft_delc(void *node1)
{
	free(node1);
}

int	main(int ac, char *dc[])
{
	t_list			*node1;

	if (ac != 2)
		return (1);
	node1 = ft_lstnew(ft_strdup(dc[1]));
	printf(".\nHere is the node: %s\n\n", (char *)node1->content);
	ft_lstdelone(node1, ft_delc);
	printf("\nHere is no node: %s\n\n", (char *)node1->content);
	return (0);
}
*/
// ccc ft_lstdelone.c ft_lstnew.c ft_strdup.c ft_strlen.c
