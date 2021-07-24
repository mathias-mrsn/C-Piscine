/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmasser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:11:10 by brmasser          #+#    #+#             */
/*   Updated: 2021/07/21 15:11:10 by brmasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_translate_board(t_map *map, char **str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == map->empty)
			(*str)[i] = '1';
		else if ((*str)[i] == map->obstacle)
			(*str)[i] = '0';
		i++;
	}
}

int	ft_min(int a, int b, int c)
{
	if (a <= b && a <= c)
		return (a + 1);
	if (b <= a && b <= c)
		return (b + 1);
	if (c <= a && c <= b)
		return (c + 1);
	return (1);
}

void	ft_algoryth(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->s_line * map->s_col)
	{
		if (map->map[i % map->s_col][i / map->s_col] > 0 &&
		i % map->s_col > 0 && i / map->s_col > 0)
			map->map[i % map->s_col][i / map->s_col]
				= ft_min(map->map[i % map->s_col - 1][i / map->s_col],
					map->map[i % map->s_col - 1][i / map->s_col - 1],
					map->map[i % map->s_col][i / map->s_col - 1]);
		i++;
	}
	ft_get_solve(map);
	ft_print_solve(map);
}

void	ft_get_solve(t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->s_col)
	{
		i = -1;
		while (map->map[j][++i] != -1)
		{
			if (map->map[j][i] > map->solve_size)
			{
				map->solve_y = i;
				map->solve_x = j;
				map->solve_size = map->map[j][i];
			}
		}
	}
}

void	ft_print_solve(t_map *map)
{
	int	i;
	int	j;

	j = -1;
	while (++j < map->s_col)
	{
		i = -1;
		while (map->map[j][++i] != -1)
		{
			if ((j <= map->solve_x && j > map->solve_x - map->solve_size)
				&& (i <= map->solve_y && i > map->solve_y - map->solve_size))
				ft_putchar(map->full);
			else if (map->map[j][i] == 0)
				ft_putchar(map->obstacle);
			else
				ft_putchar(map->empty);
		}
		write(1, "\n", 1);
	}
}
