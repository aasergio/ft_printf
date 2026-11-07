/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstadd_front.c                                 :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/18 16:51:54 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/19 12:54:25 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
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
	ft_lstadd_front(&node1, ft_lstnew(dc[2]));
	printf("%s\n", (char *)node1->content);
	printf("%s\n", (char *)node1->next->content);
	printf("%s\n", (char *)node1->next->next);
	return (0);
}
*/
// ccc ft_lstadd_front.c ft_lstnew.c ft_lstlast.c
