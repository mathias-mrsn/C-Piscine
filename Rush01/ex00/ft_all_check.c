/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:38:14 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/11 12:38:16 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_up_to_down(char **board, char *argv, int arg)
{
	int	x;
	int	y;
	int	tmp;
	int	res;

	x = -1;
	while (++x < 4)
	{
		res = 0;
		y = -1;
		tmp = 0;
		while (++y < 4)
		{
			if (tmp < board[x][y])
			{
				tmp = board[x][y];
				res++;
			}
		}
		if (res != argv[arg] - 48)
			return (0);
		arg += 2;
	}
	return (1);
}

int	ft_down_to_up(char **board, char *argv, int arg)
{
	int	x;
	int	y;
	int	tmp;
	int	res;

	x = -1;
	while (++x < 4)
	{
		res = 0;
		y = 4;
		tmp = 0;
		while (--y > -1)
		{
			if (tmp < board[x][y])
			{
				tmp = board[x][y];
				res++;
			}
		}
		if (res != argv[arg] - 48)
			return (0);
		arg += 2;
	}
	return (1);
}

int	ft_left_to_right(char **board, char *argv, int arg)
{
	int	x;
	int	y;
	int	tmp;
	int	res;

	y = -1;
	while (++y < 4)
	{
		res = 0;
		x = -1;
		tmp = 0;
		while (++x < 4)
		{
			if (tmp < board[x][y])
			{
				tmp = board[x][y];
				res++;
			}
		}
		if (res != argv[arg] - 48)
			return (0);
		arg += 2;
	}
	return (1);
}

int	ft_right_to_left(char **board, char *argv, int arg)
{
	int	x;
	int	y;
	int	tmp;
	int	res;

	y = -1;
	while (++y < 4)
	{
		res = 0;
		x = 4;
		tmp = 0;
		while (--x > -1)
		{
			if (tmp < board[x][y])
			{
				tmp = board[x][y];
				res++;
			}
		}
		if (res != argv[arg] - 48)
			return (0);
		arg += 2;
	}
	return (1);
}

int	ft_checkchar(char **board, char **argv)
{
	if (ft_up_to_down(board, argv[1], 0) && ft_down_to_up(board, argv[1], 8)
		&& ft_left_to_right(board, argv[1], 16)
		&& ft_right_to_left(board, argv[1], 24))
		return (1);
	else
		return (0);
}
