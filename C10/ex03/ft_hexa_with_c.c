/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:10:04 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/12 14:52:43 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_printhex(t_option *option)
{
	unsigned int	i;
	char			*base;

	base = "0123456789abcdef";
	i = -1;
	while (++i < option->size)
	{
		write(1, &base[option->to_print[i] / 16], 1);
		write(1, &base[option->to_print[i] % 16], 1);
		if (i % 8 == 7)
			write(1, " ", 1);
		write(1, " ", 1);
	}
}

void	ft_print_line(t_option *option)
{
	unsigned int	i;

	i = -1;
	ft_putchar('|');
	while (++i < option->size)
	{
		if (option->to_print[i] >= 32 && option->to_print[i] <= 126)
			ft_putchar(option->to_print[i]);
		else
			ft_putchar('.');
	}
	ft_putchar('|');
	write(1, "\n", 1);
	option->size = 0;
	option->to_print[0] = '\0';
}

void	ft_putaddr(unsigned long size)
{
	char	addr_c[8];
	int		i;

	i = 0;
	while (size > 0)
	{
		addr_c[i] = size % 16;
		if (addr_c[i] < 10)
			addr_c[i] += '0';
		else
			addr_c[i] += 87;
		size = size / 16;
		i++;
	}
	while (i < 8)
	{
		addr_c[i] = '0';
		i++;
	}
	while (--i >= 0)
		write(1, &addr_c[i], 1);
}

void	ft_fill_white_space(t_option *option)
{
	int	i;

	i = option->size;
	while (i < 16)
	{
		write(1, "   ", 3);
		if (i % 8 == 7)
			write(1, " ", 1);
		i++;
	}
}
