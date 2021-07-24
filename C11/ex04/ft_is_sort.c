/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 14:32:32 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/11 18:37:50 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort_c(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = -1;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
	}
	return (1);
}

int	ft_is_sort_d(int *tab, int length, int(*f)(int, int))
{
	int	i;

	i = -1;
	while (++i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	if (ft_is_sort_c(tab, length, f) || ft_is_sort_d(tab, length, f))
		return (1);
	else
		return (0);
}
