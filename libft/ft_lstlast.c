/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstlast.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 11:27:55 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/19 11:42:38 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>

int	main(int ac, char *dc[])
{
	unsigned int	arg;
	t_list			*node1;

	if (ac < 2)
		return (1);
	node1 = ft_lstnew(dc[1]);
	arg = 1;
	while (arg < (unsigned int)ac)
	{
		ft_lstadd_front(&node1, ft_lstnew(dc[arg]));
		arg++;
	}
	printf(".\nFirst node: %s\n\n", (char *)node1->content);
	printf("\nLast node: %s\n.\n", (char *)ft_lstlast(node1)->content);
	return (0);
}
*/
