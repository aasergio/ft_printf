/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ftprintf.h                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: skaprash <skaprash@student.42.fr>         #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/02 19:27:09 by skaprash         #+#    #+#              */
/*   Updated: 2026/11/03 19:06:53 by skaprash        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEC "0123456789"
# define HEXUP "0123456789ABCDEF"
# define HEXLOW "0123456789abcdef"
# include <unistd.h>
# include <stdint.h>
# include <libft.h>

void	ft_putnbr_any(unsigned long n, char *system, int *res);
void	ft_putchar_pr(char c, int *res);
void	ft_putstr_pr(char *s, int *res);
void	ft_putnbr_d(int n, int *res);
int		ft_printf(const char *s, ...);

#endif
