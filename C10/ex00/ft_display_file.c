/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:08:53 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/12 11:02:53 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	ft_error(int i)
{
	if (i == 0)
		write(2, "File name missing.\n", 19);
	if (i == 1)
		write(2, "Cannot read file.\n", 18);
	if (i == 2)
		write(2, "Too many arguments.\n", 20);
	return (0);
}

int	ft_display_file(char *path)
{
	int		fd;
	char	buffer;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (ft_error(1));
	while (read(fd, &buffer, 1) > 0)
		write(1, &buffer, 1);
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_error(0);
	else if (argc > 2)
		ft_error(2);
	else
		ft_display_file(argv[1]);
}
