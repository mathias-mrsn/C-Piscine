/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:10:16 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/13 08:51:00 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_print_hub(t_option *option)
{
	size_t	i;

	i = 0;
	option->files_len += option->size;
	if (!option->star && ft_strcmp(option->to_print, option->save, option) == 0)
	{
		write(1, "*\n", 2);
		option->star = 1;
	}
	if (ft_strcmp(option->to_print, option->save, option) != 0)
	{
		option->star = 0;
		ft_strlcpy(option);
		if (option->first_file == 2)
			ft_c(option);
		else
			ft_without_c(option);
	}
	option->size = 0;
	while (i < 16)
		option->to_print[i++] = '\0';
}

void	ft_hub(t_option *option, char **argv, int argc)
{
	int	i;

	i = option->first_file - 1;
	while (argc > ++i)
	{
		option->argc -= 1;
		option->fd = open(argv[i], O_RDONLY);
		if (option->fd == -1)
			ft_error(basename(argv[0]), argv[i]);
		else
			ft_hexdump(option);
	}
	if (ft_check_file_error(argc, argv, option))
	{
		if (option->size > 0)
			ft_print_hub(option);
		if (option->files_len)
		{
			if (option->first_file == 2)
				ft_putaddr(option->files_len);
			else
				ft_putaddr_c(option->files_len);
			write(1, "\n", 1);
		}
	}
}

int	ft_strcmp(unsigned char *s1, unsigned char *s2, t_option *option)
{
	unsigned int	len;

	len = -1;
	while (++len < option->size && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_check_params(int argc, char **argv, t_option *option)
{
	if (argc == 1)
		option->first_file = 1;
	if (argc == 2 && (argv[1][0] == '-'
		|| argv[1][1] == 'C' || argv[1][2] == '\0'))
		option->first_file = 2;
	if (argc >= 2 && (argv[1][0] != '-'
		|| argv[1][1] != 'C' || argv[1][2] != '\0'))
		option->first_file = 1;
	return (1);
}

int	ft_error(char *basename, char *prog)
{
	ft_puterror(basename);
	ft_puterror(": ");
	ft_puterror(prog);
	ft_puterror(": ");
	ft_puterror(strerror(errno));
	ft_puterror("\n");
	return (0);
}
