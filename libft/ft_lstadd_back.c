/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstadd_back.c                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/19 12:25:44 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/21 21:06:45 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
	new = ft_lstlast(*lst);
	return ;
}
/*
int	main(int ac, char *dc[])
{
	t_list	*node1;
	char	*str;

	if (ac != 3)
		return (1);
	(void)str;
	node1 = ft_lstnew(dc[1]);
	printf("%s\n", (char *)node1->content);
	printf("%s\n\n", (char *)node1->next);
	ft_lstadd_back(&node1, ft_lstnew(dc[2]));
	printf("%s\n", (char *)node1->content);
	printf("%s\n", (char *)node1->next->content);
	printf("%s\n", (char *)node1->next->next);
	return (0);
}
*/
// 
