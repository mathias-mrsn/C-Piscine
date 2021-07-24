/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:08:16 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/01 13:02:06 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_unprintable(unsigned char c)
{
	char	*base;

	base = "0123456789abcdef";
	write(1, "\\", 1);
	ft_putchar(base[c / 16]);
	ft_putchar(base[c % 16]);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (str[i] < ' ' || str[i] > 126)
			ft_print_unprintable(str[i]);
		else
			ft_putchar(str[i]);
	}
}
