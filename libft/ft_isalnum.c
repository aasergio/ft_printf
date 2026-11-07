/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_isalnum.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/07 18:15:02 by skaprash         #+#    #+#              */
/*   Updated: 2026/10/21 22:42:25 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	c = (char)c;
	if (ft_isalpha((int)c) || ft_isdigit((int)c))
		return (1);
	return (0);
}
// ccc ft_isalnum.c ft_isalpha.c ft_isdigit.c
