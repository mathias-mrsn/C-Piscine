/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backtracking.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:38:22 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/11 12:38:23 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check(char **board, int x, int y, int i)
{
	int	l;
	int	h;

	l = x - 1;
	h = y - 1;
	while (l >= 0)
	{
		if (board[l][y] == i)
			return (0);
		l--;
	}
	while (h >= 0)
	{
		if (board[x][h] == i)
			return (0);
		h--;
	}
	return (1);
}

int	ft_comb(char **board, char **argv, int pos, int *solve)
{
	int	x;
	int	y;
	int	i;

	x = pos / 4;
	y = pos % 4;
	if (pos == 16)
	{
		if (ft_checkchar(board, argv) == 1)
		{
			ft_print_board(board);
			(*solve)++;
		}
		return (0);
	}
	i = 0;
	while (++i < 5)
	{
		if (ft_check(board, x, y, i) == 1 && (*solve) == 0)
		{
			board[x][y] = i;
			ft_comb(board, argv, pos + 1, solve);
		}
	}
	return (0);
}
