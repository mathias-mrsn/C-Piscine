/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:51:33 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/21 15:11:27 by brmasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

unsigned long	ft_size_file(char *path)
{
	int		fd;
	char	buffer[4096];
	long	size;
	int		i;

	i = 1;
	size = 0;
	fd = open(path, 0);
	if (fd == -1)
	{
		return (0);
	}
	while (i > 0)
	{
		i = read(fd, &buffer, 4096);
		size += i;
	}
	close(fd);
	return (size);
}

char	*ft_read_file(char *path)
{
	const unsigned long	size = ft_size_file(path);
	char				*str;
	size_t				i;
	int					fd;
	int					ret;

	i = 0;
	str = malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		free(str);
		return (NULL);
	}
	ret = read(fd, str, size);
	str[ret] = '\0';
	close(fd);
	return (str);
}

int	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	ft_read_header(char *str, t_map	*map)
{
	int	res;
	int	i;
	int	start;

	start = 0;
	res = 0;
	i = 0;
	while (str[start] && str[start] != '\n')
		start++;
	while (str[i] >= '0' && str[i] <= '9' && i < start - 3)
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	map->empty = str[i++];
	if (str[i] != str[i - 1] && is_printable(str[i]))
		map->obstacle = str[i++];
	if (str[i] != str[i - 1] && str[i] != str[i - 2] && is_printable(str[i]))
		map->full = str[i++];
	if (str[i++] != '\n' || !map->empty || !map->full || !map->obstacle)
		return (0);
	else
		map->s_col = res;
	return (i);
}
