/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:51:29 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/21 15:11:24 by brmasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_check_map(char *str, t_map *map, int	first, int	curr)
{
	int	prev;
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] && is_map(str[i], map))
			curr++;
		else if (str[i] && str[i] == '\n' && is_map(str[i + 1], map)
			&& is_map(str[i - 1], map) && (prev == curr || first == 0))
		{
			prev = curr;
			curr = 0;
			first++;
		}
		else
			return (0);
	}
	if (map->s_col == first)
		return (1);
	return (0);
}

int	ft_error(int i, t_map *map, char *str)
{
	write(2, "map error\n", 11);
	ft_free(i, map, str);
	return (1);
}

void	ft_free(int	i, t_map *map, char *str)
{
	int	len;

	len = -1;
	if (i >= 1)
		free(str);
	if (i == 2)
	{
		while (++len < map->s_col)
			free(map->map[len]);
		free(map->map);
	}
}
