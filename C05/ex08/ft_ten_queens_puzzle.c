/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/04 10:38:55 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/04 10:38:56 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_board(int *tab)
{
	int	i;

	i = -1;
	while (++i < 10)
		ft_putchar(tab[i] + 48);
	ft_putchar('\n');
}

int	ft_check(int tab[], int pos, int i)
{
	int	j;

	j = -1;
	while (++j < pos)
	{
		if ((tab[j] == i - (pos - j))
			|| (tab[j] == i + (pos - j)) || tab[j] == i)
			return (0);
	}
	return (1);
}

void	ft_recursive(int tab[], int pos, int *posib)
{
	int	i;

	i = -1;
	if (pos == 10)
	{
		ft_print_board(tab);
		(*posib)++;
		return ;
	}
	while (++i < 10)
	{
		if (ft_check(tab, pos, i))
		{
			tab[pos] = i;
			ft_recursive(tab, pos + 1, posib);
		}		
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	res;
	int	tab[10];

	res = 0;
	ft_recursive(tab, 0, &res);
	return (res);
}
