/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstclear.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 14:35:59 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/20 17:34:59 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*nextone;

	while (*lst != NULL)
	{
		nextone = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = nextone;
	}
	return ;
}
/*
static void	ft_delc(void *node1)
{
	free(node1);
}

static void	ft_show(int ac, t_list *tmp)
{
	int	i;

	i = 0;
	while (i < ac - 1)
	{
		printf("%d: %s\n", i, (char *)tmp->content);
		tmp = tmp->next;
		i++;
	}
	return ;
}

int	main(int ac, char *dc[])
{
	int		arg;
	t_list	*node1;

	if (ac < 2)
		return (1);
	node1 = ft_lstnew(ft_strdup(dc[1]));
	arg = 1;
	while (arg < ac)
	{
		ft_lstadd_front(&node1, ft_lstnew(ft_strdup(dc[arg])));
		arg++;
	}
	printf(".\nNodes:\n");
	ft_show(ac, node1);
	ft_lstclear(&node1, ft_delc);
	printf(".\nNow trying to go the same:\n");
	printf(".\n");
	return (0);
}
*/
// ccc ft_lstclear.c ft_lstnew.c ft_lstadd_front.c 
// ft_strdup.c ft_strlen.c ft_lstdelone.c
