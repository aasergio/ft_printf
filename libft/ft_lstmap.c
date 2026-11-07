/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstmap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/20 15:19:03 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/21 21:11:19 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*nodenext;
	void	*cuntent;

	if (!lst || !f || !del)
		return (NULL);
	start = NULL;
	while (lst != NULL)
	{
		cuntent = f(lst->content);
		nodenext = ft_lstnew(cuntent);
		if (!nodenext)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		ft_lstadd_back(&start, nodenext);
		lst = lst->next;
	}
	return (start);
}
/*
static void	ft_delc(void *node1)
{
	free(node1);
}

static void	*ft_test(void *content)
{
	char	*str;
	char	*dup;

	str = (char *)content;
	dup = ft_strdup(str);
	if (!dup)
		return (NULL);
	if (dup[0])
		dup[0] = '6';
	if (dup[1])
		dup[1] = '7';
	return ((void *)dup);
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
	t_list	*new;

	if (ac < 2)
		return (1);
	node1 = NULL;
	arg = 1;
	while (arg < ac)
	{
		ft_lstadd_back(&node1, ft_lstnew(ft_strdup(dc[arg])));
		arg++;
	}
	printf(".\nNodes:\n");
	ft_show(ac, node1);
	printf("\nNow trying to go the same:\n");
	new = ft_lstmap(node1, ft_test, ft_delc);
	ft_show(ac, new);
	printf(".\n");
	ft_lstclear(&node1, ft_delc);
	ft_lstclear(&new, ft_delc);
	return (0);
}
*/
// ccc ft_lstmap.c ft_lstiter.c ft_lstnew.c
// ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_strdup.c ft_strlen.c
