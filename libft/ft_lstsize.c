/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstsize.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 10:51:07 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/19 11:33:04 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

unsigned int	ft_lstsize(t_list *lst)
{
	unsigned int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
/*
int	main(int ac, char *dc[])
{
	unsigned int	arg;
	t_list			*node1;

	if (ac < 2)
		return (1);
	node1 = ft_lstnew(dc[1]);
	arg = 1;
	while (arg < (unsigned int)ac - 1)
	{
		ft_lstadd_front(&node1, ft_lstnew(dc[arg]));
		arg++;
	}
	printf(".\nNodes: %d\n.\n", ft_lstsize(node1));
	return (0);
}
*/
