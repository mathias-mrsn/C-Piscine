/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:09:39 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/13 19:11:06 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char *))
{
	int	i;
	int	res;

	res = 0;
	i = -1;
	while (++i < length)
	{
		if (f(tab[i]) != 0)
			res++;
	}
	return (res);
}
