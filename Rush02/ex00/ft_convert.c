/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abfall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:52:37 by abfall            #+#    #+#             */
/*   Updated: 2021/07/18 19:52:39 by abfall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*ft_fill(char *str, int *i)
{
	char	*tab;
	int		j;

	j = 0;
	tab = malloc(sizeof(char) * 4);
	if (!tab)
		return (NULL);
	while (j < 3)
	{
		tab[j] = str[*i];
		j++;
		(*i)++;
	}
	tab[j] = '\0';
	return (tab);
}

char	*ft_fill_first(char *str, int f, int *i)
{
	char	*tab;

	tab = malloc(sizeof(char) * (f + 1));
	if (!tab)
		return (NULL);
	while (*i < f)
	{
		tab[*i] = str[*i];
		(*i)++;
	}
	tab[*i] = '\0';
	return (tab);
}

char	**ft_convert(char *str)
{
	int		i;
	int		j;
	int		g;
	char	**tab;

	j = 0;
	i = 0;
	g = ft_strlen(str) / 3;
	if (ft_strlen(str) % 3 != 0)
		g++;
	tab = malloc(sizeof(char *) * (g + 1));
	if (!tab)
		return (NULL);
	if (ft_strlen(str) % 3 != 0)
	{
		tab[0] = ft_fill_first(str, ft_strlen(str) % 3, &i);
		j++;
	}
	while (str[i])
	{
		tab[j] = ft_fill(str, &i);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
