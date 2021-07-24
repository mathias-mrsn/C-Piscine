/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abfall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:53:25 by abfall            #+#    #+#             */
/*   Updated: 2021/07/18 19:53:26 by abfall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
	if (!is_unprintable(c) || c == ' ')
		new[i++] = c;
	else
		new[i++] = ' ';
	new[i] = '\0';
	free((*dest));
	(*dest) = new;
}

int	ft_check_argv(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_numeric(str[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strdup(char *src)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	res = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!res)
		return (NULL);
	while (is_space(src[i]))
		i++;
	while (src[i])
	{
		res[j] = src[i];
		i++;
		j++;
	}
	while (is_space(res[--j]))
		res[j] = '\0';
	res[i] = '\0';
	return (res);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
