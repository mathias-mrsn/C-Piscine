/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:09:17 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/11 10:09:18 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_puterror(char *str)
{
	while (*str)
		write(2, &*str++, 1);
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

int	ft_can_be_open(char *path)
{
	int	fd;
	int	res;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		res = 0;
	else
		res = 1;
	close (fd);
	return (res);
}
