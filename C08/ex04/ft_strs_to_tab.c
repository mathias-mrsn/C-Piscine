/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:37:05 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/06 17:37:07 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (dest == 0)
		return (NULL);
	i = -1;
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int size, char **tab)
{
	t_stock_str	*t;
	int			i;

	if (size < 0)
		return (NULL);
	t = malloc((size + 1) * sizeof(t_stock_str));
	if (!t)
		return (NULL);
	i = -1;
	while (++i < size)
	{
		t[i].size = ft_strlen(tab[i]);
		t[i].str = tab[i];
		t[i].copy = ft_strdup(tab[i]);
	}
	t[i].str = 0;
	return (t);
}
