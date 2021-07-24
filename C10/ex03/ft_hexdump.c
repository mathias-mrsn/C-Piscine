/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:10:11 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/13 11:21:10 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hexdump(t_option *option)
{
	unsigned char	buffer;

	while ((read(option->fd, &buffer, 1)))
	{
		ft_strncat(option->to_print, buffer, option);
		option->size++;
		if (option->size == 16)
			ft_print_hub(option);
	}
}

void	ft_stdin(t_option *option)
{
	unsigned char	buffer;

	while ((read(STDIN_FILENO, &buffer, 1)))
	{
		ft_strncat(option->to_print, buffer, option);
		option->size++;
		if (option->size == 16)
			ft_print_hub(option);
	}
	if (option->size > 0)
	{
		ft_print_hub(option);
	}
	if (option->files_len)
	{
		if (option->first_file == 1)
			ft_putaddr_c(option->files_len);
		else
			ft_putaddr(option->files_len);
		write(1, "\n", 1);
	}
}

int	ft_check_file_error(int argc, char **argv, t_option *option)
{
	int	i;
	int	fd;
	int	file;

	file = 0;
	i = option->first_file;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd > 0)
			file++;
		close(fd);
		i++;
	}
	return (file);
}

int	main(int argc, char **argv)
{
	t_option	option;

	if (!ft_check_params(argc, argv, &option))
		return (0);
	init_option(&option, argc);
	if (argc == 1 || (argc == 2 && option.first_file == 2))
		ft_stdin(&option);
	ft_hub(&option, argv, argc);
	if (ft_check_file_error(argc, argv, &option) == 0)
		ft_bad_file_descriptor(argc, argv, &option);
}
