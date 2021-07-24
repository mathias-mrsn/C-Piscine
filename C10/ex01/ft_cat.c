/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:09:09 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/12 09:25:44 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <libgen.h>
#include <string.h>

void	ft_puterr(char *str)
{
	while (*str)
		write(2, &*str++, 1);
}

int	ft_error(char *basename, char *prog)
{
	ft_puterr(basename);
	ft_puterr(": ");
	ft_puterr(prog);
	ft_puterr(": ");
	ft_puterr(strerror(errno));
	ft_puterr("\n");
	return (0);
}

int	ft_display_file(char *path, char *basename, char *prog)
{
	int		fd;
	char	buffer;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
	{
		ft_error(basename, prog);
		close (fd);
		return (0);
	}
	while (read(fd, &buffer, 1) > 0)
		write(1, &buffer, 1);
	close(fd);
	return (1);
}

int	ft_stdin(void)
{
	char	buffer;

	while (read(STDIN_FILENO, &buffer, 1) > 0)
		write(1, &buffer, 1);
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 1)
		return (1);
	if (argc < 2)
		ft_stdin();
	while (++i < argc)
	{
		ft_display_file(argv[i], basename(argv[0]), argv[i]);
	}
	return (1);
}
