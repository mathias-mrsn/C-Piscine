/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:10:23 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/12 11:46:46 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	init_option(t_option *option, int argc)
{
	option->files_len = 0;
	option->size = 0;
	option->argc = (unsigned int)argc - 2;
	option->buffer_size = 16;
	option->star = 0;
	if (option->first_file != 1)
		option->first_file = 2;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned char	*ft_strncat(unsigned char *dest,
unsigned char src, t_option *option)
{
	unsigned int		i;

	i = option->size;
	dest[i] = src;
	dest[i + 1] = '\0';
	return (dest);
}

unsigned int	ft_strlcpy(t_option *option)
{
	unsigned int	i;

	i = 0;
	while (i < option->size)
	{
		option->save[i] = option->to_print[i];
		i++;
	}
	return (i);
}

void	ft_puterror(char *str)
{
	while (*str)
		write(2, &*str++, 1);
}
