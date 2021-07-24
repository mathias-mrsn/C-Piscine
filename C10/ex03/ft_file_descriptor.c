/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_descriptor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:09:57 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/13 11:22:15 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_bad_file_descriptor(int argc, char **argv, t_option *option)
{
	int	fd;
	int	i;

	i = argc - 1;
	while (i >= option->first_file)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd <= 0)
		{
			ft_puterror(basename(argv[0]));
			ft_puterror(": ");
			ft_puterror(argv[i]);
			ft_puterror(": Bad file descriptor\n");
			close(fd);
			return ;
		}
		close(fd);
		i--;
	}
}
