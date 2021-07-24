/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:09:22 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/11 10:09:23 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_display_file(char *path, long size, long option)
{
	int		fd;
	char	buffer;
	long	len;

	len = -1;
	fd = open(path, 0);
	if (fd == -1)
	{
		return (0);
	}
	while (++len < size - option)
		read(fd, &buffer, 1);
	while (read(fd, &buffer, 1) > 0)
		write(1, &buffer, 1);
	close(fd);
	return (1);
}

unsigned int	ft_strlcpy(unsigned char *dest,
	unsigned char *src, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

long	ft_size_file(char *path, char *basename, char *prog)
{
	int		fd;
	char	buffer;
	long	size;

	size = 0;
	fd = open(path, 0);
	if (fd == -1)
	{
		return (ft_error(basename, prog));
	}
	while (read(fd, &buffer, 1) > 0)
		size++;
	close(fd);
	return (size);
}

int	ft_connection(char *str)
{
	int	fd;

	fd = open(str, 0);
	if (fd <= -1)
		return (-1);
	else
		return (fd);
}

void	ft_stdin(long option, int i)
{
	unsigned char	*buffer;
	unsigned char	one_char;
	int				index;
	int				len;

	len = 0;
	index = 0;
	buffer = (unsigned char *)malloc(sizeof(unsigned char) * option + 2);
	if (!buffer)
		return ;
	while ((read(STDIN_FILENO, &one_char, 1)))
	{
		buffer[index] = one_char;
		index++;
		len++;
		if (index == option)
			index = 0;
	}
	i = index;
	while (i < option && len > option)
		write(1, &buffer[i++], 1);
	i = 0;
	while (i < index)
		write(1, &buffer[i++], 1);
	return ;
}
