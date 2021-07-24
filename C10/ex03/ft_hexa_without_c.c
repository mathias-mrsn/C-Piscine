/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_without_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:21:39 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/12 17:21:40 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_c(t_option *option)
{
	ft_putaddr(option->files_len - option->size);
	write(1, "  ", 2);
	ft_printhex(option);
	ft_fill_white_space(option);
	ft_print_line(option);
}

void	ft_putaddr_c(unsigned long size)
{
	char	addr_c[7];
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
	while (i < 7)
	{
		addr_c[i] = '0';
		i++;
	}
	while (--i >= 0)
		write(1, &addr_c[i], 1);
}

void	ft_hex_c(t_option *option)
{
	unsigned int	i;
	char			*base;

	base = "0123456789abcdef";
	i = -1;
	while (++i < option->size)
	{
		write(1, &base[option->to_print[i] / 16], 1);
		write(1, &base[option->to_print[i] % 16], 1);
		if (i < option->size - 1)
			write(1, " ", 1);
	}
}

void	ft_fill_white_space_c(t_option *option)
{
	int	i;

	i = option->size;
	while (i < 16)
	{
		write(1, "   ", 3);
		i++;
	}
}

void	ft_without_c(t_option *option)
{
	ft_putaddr_c(option->files_len - option->size);
	write(1, " ", 1);
	ft_hex_c(option);
	ft_fill_white_space_c(option);
	write(1, "\n", 1);
}
