/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:13:57 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/05 16:13:59 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*t;
	int	i;

	if (min >= max)
		return (NULL);
	max -= min;
	t = malloc(max * sizeof(int));
	if (!t)
		return (NULL);
	i = -1;
	while (++i < max)
		t[i] = min + i;
	return (t);
}
