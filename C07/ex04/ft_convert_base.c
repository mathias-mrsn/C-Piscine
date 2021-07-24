/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 16:14:17 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/05 16:14:19 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (!*base || base[1] == '\0')
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
	}
	return (i);
}

int	ft_nb_in_base(char *base, char c)
{
	int	i;

	i = -1;
	while (base[++i])
	{
		if (base[i] == c)
			return (i);
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	neg;
	int	res;

	res = 0;
	neg = 1;
	i = 0;
	if (!ft_check_base(base))
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (ft_nb_in_base(base, str[i]) != -1)
	{
		res = res * ft_check_base(base) + (ft_nb_in_base(base, str[i]));
		i++;
	}
	res *= neg;
	return (res);
}

int	ft_size(int nbr, char *base)
{
	int	i;

	i = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		i++;
	}
	while (nbr / ft_check_base(base) != 0)
	{
		i++;
		nbr /= ft_check_base(base);
	}
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		res_int;
	char	*res_char;
	int		len;

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	res_int = ft_atoi_base(nbr, base_from);
	res_char = (char *)malloc(sizeof(char) * ft_size(res_int, base_to) + 1);
	if (!res_char)
		return (NULL);
	len = ft_size(res_int, base_to);
	if (res_int < 0)
	{
		res_int *= -1;
		res_char[0] = '-';
	}
	while (res_int / ft_check_base(base_to))
	{
		res_char[--len] = base_to[res_int % ft_check_base(base_to)];
		res_int /= ft_check_base(base_to);
	}
	res_char[--len] = base_to[res_int % ft_check_base(base_to)];
	res_char[ft_size(ft_atoi_base(nbr, base_from), base_to)] = '\0';
	return (res_char);
}
