/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 14:51:21 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/21 15:11:06 by brmasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

void	ft_strcat(char **dest, char c)
{
	int		i;
	char	*new;

	i = 0;
	while ((*dest)[i])
		i++;
	new = malloc(sizeof(char) * (i + 2));
	i = -1;
	while ((*dest)[++i])
		new[i] = (*dest)[i];
	new[i++] = c;
	new[i] = '\0';
	free((*dest));
	(*dest) = new;
}

char	*ft_read_stdin(void)
{
	char	*str;
	char	buffer;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (free(str), NULL);
	while (read(STDIN_FILENO, &buffer, 1) > 0)
		ft_strcat(&str, buffer);
	return (str);
}

int	ft_stdin(void)
{
	char	*read;
	t_map	map;
	int		start;

	ft_init_map(&map);
	read = ft_read_stdin();
	if (!read)
		return (ft_error(0, &map, read));
	start = ft_read_header(read, &map);
	if (!start || !ft_check_map(read + start, &map, 0, 0))
		return (ft_error(1, &map, read));
	ft_translate_board(&map, &read);
	if (!ft_split(read + start, &map))
		return (ft_error(2, &map, read));
	ft_algoryth(&map);
	ft_free(2, &map, read);
	return (0);
}

int	ft_process(char *arg)
{
	char	*read;
	t_map	map;
	int		start;

	ft_init_map(&map);
	read = ft_read_file(arg);
	if (!read)
		return (ft_error(0, &map, read));
	start = ft_read_header(read, &map);
	if (!start || !ft_check_map(read + start, &map, 0, 0))
		return (ft_error(1, &map, read));
	ft_translate_board(&map, &read);
	if (!ft_split(read + start, &map))
		return (ft_error(2, &map, read));
	ft_algoryth(&map);
	ft_free(2, &map, read);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;

	i = 0;
	if (argc == 1)
		return (ft_stdin());
	while (++i < argc)
	{
		ft_process(argv[i]);
		if (i < argc - 1)
			write(1, "\n", 1);
	}
	return (0);
}
