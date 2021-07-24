/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:38:44 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/11 16:51:36 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	**ft_init_tab(void)
{
	int		i;
	int		t;
	char	**tab;

	tab = malloc(sizeof(char *) * 4);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < 4)
	{
		tab[i] = malloc(sizeof(char) * 4);
		if (!tab[i])
			return (NULL);
		t = 0;
		while (t < 4)
			tab[i][t++] = 0;
		i++;
	}
	return (tab);
}
