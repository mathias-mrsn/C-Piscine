/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:09:40 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/12 08:04:17 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, &*str++, 1);
}

long	ft_atoi(char *str)
{
	int		i;
	long	res;

	res = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (res);
}

long	ft_check_option(char *option, char *val)
{
	long	res;

	if (option[0] != '-' || option[1] != 'c' || option[2] != '\0')
	{
		return (0);
	}
	res = ft_atoi(val);
	return (res);
}

void	ft_print_line_name(char *str, int i, int first)
{
	if (i > 3 && first)
		ft_putstr("\n");
	ft_putstr("==> ");
	ft_putstr(str);
	ft_putstr(" <==\n");
}
