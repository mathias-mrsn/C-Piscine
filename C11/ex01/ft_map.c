/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:32:15 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/13 17:39:54 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*res;
	int	i;

	res = (int *)malloc(sizeof(int) * length + 1);
	if (!res || length < 1)
		return (0);
	i = -1;
	while (++i < length)
		res[i] = f(tab[i]);
	return (res);
}
