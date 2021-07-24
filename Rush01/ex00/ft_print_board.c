/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_board.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:38:52 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/11 12:38:54 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_print_board(char **tab)
{
	int	a;
	int	b;

	b = 0;
	while (b < 4)
	{
		a = 0;
		while (a < 4)
		{
			ft_putchar(tab[a][b] + 48);
			if (a < 3)
				write(1, " ", 1);
			a++;
		}
		if (b < 3)
			write(1, "\n", 1);
		b++;
	}
	write(1, "\n", 1);
}
