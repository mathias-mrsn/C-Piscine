/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 18:27:50 by mamaurai          #+#    #+#             */
/*   Updated: 2021/06/29 18:27:51 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_tab(int *tab, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		ft_putchar(tab[i] + 48);
	if (10 - size != tab[0])
		write(1, ", ", 2);
}

void	ft_recursive(int *tab, int last_nb, int pos, int size)
{
	int		i;

	i = last_nb;
	if (pos == size)
	{
		ft_print_tab(tab, size);
		return ;
	}
	while (++i < 10)
	{
		tab[pos] = i;
		ft_recursive(tab, i, pos + 1, size);
	}
}

void	ft_print_combn(int n)
{
	int		tab[10];

	if (n > 0 && n < 10)
		ft_recursive(tab, -1, 0, n);
}
