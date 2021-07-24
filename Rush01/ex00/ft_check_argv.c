/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:38:28 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/11 12:38:29 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_counter(char *str)
{
	int	i;
	int	numbers;
	int	whites;

	whites = 0;
	numbers = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] > '0' && str[i] < '5')
			numbers++;
		else if (i > 0 && str[i] == ' ' && (str[i - 1] < '5'
				&& str[i - 1] > '0') && (str[i + 1] < '5' && str[i + 1] > '0'))
			whites++;
		else
			return (0);
	}
	if (numbers == 16 && whites == 15)
		return (1);
	return (0);
}
