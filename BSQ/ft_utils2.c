/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmasser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:11:35 by brmasser          #+#    #+#             */
/*   Updated: 2021/07/21 15:11:36 by brmasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	is_map(char c, t_map *map)
{
	if (c == map->empty || c == map->obstacle || c == '\0')
		return (1);
	return (0);
}

int	ft_len(char *str, char *charset)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] && !is_charset(str[i], charset))
			++len;
		while (str[i] && !is_charset(str[i], charset))
			++i;
	}
	return (len);
}

int	ft_word_len(char *str, char *charset)
{
	int	len;
	int	i;

	len = 0;
	i = -1;
	while (str[++i] && !is_charset(str[i], charset))
		++len;
	return (len);
}

unsigned int	ft_strlcpy(int *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i] - 48;
		++i;
	}
	dest[i] = -1;
	return (len);
}

int	ft_split(char *str, t_map *map)
{
	int		len;
	int		i;
	int		j;

	map->map = (int **)malloc(sizeof(int *) * (map->s_col + 1));
	if (!map->map)
		return (0);
	i = -1;
	j = 0;
	while (str[++i] && j < map->s_col)
	{
		if (str[i] == '\n')
			i++;
		len = ft_word_len(str + i, "\n");
		map->map[j] = (int *)malloc(sizeof(int) * (len + 1));
		if (!map->map[j])
			return (0);
		ft_strlcpy(map->map[j++], str + i, len + 1);
		i += len;
	}
	map->s_line = len;
	return (1);
}
