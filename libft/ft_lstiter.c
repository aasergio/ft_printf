/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstiter.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 20:33:15 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/20 17:34:29 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
	return ;
}
/*
static void	ft_test(void *content)
{
	unsigned char	*str;

	str = (unsigned char *)content;
	str[0] = '6';
	str[1] = '7';
	return ;
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
	ft_lstiter(node1, ft_test);
	printf("\nNow trying to go the same:\n");
	ft_show(ac, node1);
	printf(".\n");
	return (0);
}
*/
// ccc ft_lstiter.c ft_lstnew.c ft_lstadd_front.c ft_strdup.c ft_strlen.c
