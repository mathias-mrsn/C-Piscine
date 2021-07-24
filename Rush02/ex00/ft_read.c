/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:53:12 by abfall            #+#    #+#             */
/*   Updated: 2021/07/18 20:28:09 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

long	ft_size_file(char *path)
{
	int		fd;
	char	buffer;
	long	size;

	size = 0;
	fd = open(path, 0);
	if (fd == -1)
	{
		return (0);
	}
	while (read(fd, &buffer, 1) > 0)
		size++;
	close(fd);
	return (size);
}

char	*ft_read(char *path)
{
	char	*str;
	size_t	i;
	int		fd;

	i = 0;
	str = malloc(sizeof(char) * ft_size_file(path) + 1);
	if (!str)
		return (NULL);
	fd = open(path, O_RDWR);
	if (fd == -1)
		return (NULL);
	while (read(fd, &str[i], 1) > 0)
		i++;
	close(fd);
	return (str);
}
