/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abfall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:51:25 by abfall            #+#    #+#             */
/*   Updated: 2021/07/18 19:53:08 by abfall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	ft_print_first(char **str, int *i, int *ptr_i, t_dict *lst)
{
	int		g;

	g = ft_strlen(str[*i]);
	if (g == 1 && str[*i][0] != '0')
	{
		ft_printnumber(str[*i][0], lst, 0, ptr_i);
	}
	else
	{
		if (str[*i][0] == '1' && str[*i][0] != '0')
			ft_printnumber(str[*i][1], lst, str[*i][0], ptr_i);
		else if (str[*i][0] != '0')
		{
			ft_printnumber3(str[*i][0], lst, ptr_i);
			ft_printnumber(str[*i][1], lst, 0, ptr_i);
		}
	}
}

int	ft_print_all(char **str, int *i, int *j, t_dict *lst)
{
	int		ptr_i;

	if (*i != 0)
		ptr_i = 1;
	else
		ptr_i = 0;
	while (str[*i][*j])
	{
		if (*j != 1 && str[*i][*j - 1] != '1' && str[*i][*j] != '0')
			ft_printnumber(str[*i][*j], lst, 0, &ptr_i);
		if (*j == 0 && str[*i][*j] != '0')
			ft_printnumber2(lst, 3, &ptr_i);
		if (str[*i][*j] == '1' && *j == 1 && str[*i][*j] != '0')
			ft_printnumber(str[*i][*j + 1], lst, str[*i][*j], &ptr_i);
		else if (*j == 1)
			ft_printnumber3(str[*i][*j], lst, &ptr_i);
		(*j)++;
	}
	return (ptr_i);
}

int	ft_print_thousand(char **str, int *i, int *l, t_dict *lst)
{
	int		ptr_i;

	ptr_i = 1;
	if (str[(*i) + 1] != NULL && !ft_iszero(str[*i]))
	{
		if (*l >= 4)
		{
			ft_printnumber2(lst, *l, &ptr_i);
			*l = (*l) - 3;
		}
	}
	return (ptr_i);
}

int	ft_print_zero(char **str, int *i, int *ptr_i, t_dict *lst)
{
	if (str[0][0] == '0' && str[1] == NULL
		&& (ft_iszero(str[*i]) || ft_strlen(str[0]) == 1))
	{
		ft_printnumber('0', lst, str[*i][0], ptr_i);
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}

void	ft_print(char **str, int len, t_dict *lst)
{
	int		i;
	int		j;
	int		l;
	int		ptr_i;

	i = 0;
	l = ((len - 1) / 3) * 3 + 1;
	ptr_i = 0;
	if (ft_print_zero(str, &i, &ptr_i, lst))
		return ;
	if (ft_strlen(str[0]) != 3 && !ft_iszero(str[0]))
	{
		ft_print_first(str, &i, &ptr_i, lst);
		ptr_i = ft_print_thousand(str, &i, &l, lst);
		i++;
	}
	while (str[i])
	{
		j = 0;
		ptr_i = ft_print_all(str, &i, &j, lst);
		ptr_i = ft_print_thousand(str, &i, &l, lst);
		i++;
	}
	ft_free_tab(str);
	write(1, "\n", 1);
}
