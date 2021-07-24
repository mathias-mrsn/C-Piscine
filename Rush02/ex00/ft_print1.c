/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abfall <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 18:49:53 by abfall            #+#    #+#             */
/*   Updated: 2021/07/18 19:53:02 by abfall           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	ft_printnumber(char c, t_dict *lst, char c2, int *ptr_i)
{
	int		i;

	i = 0;
	if (c2 == '1' && (c2 != c || c2 == c))
		i++;
	while (lst)
	{
		if (c2 == 0 && c == lst->nb[i] && lst->nb[i + 1] == '\0'
			&& i == 0 && c != '0')
		{
			if ((*ptr_i)++ > 0)
				write(1, " ", 1);
			ft_putstr(lst->str);
			return ;
		}
		else if (c2 == lst->nb[0] && c == lst->nb[i] && lst->nb[i + 1] == '\0')
		{
			if ((*ptr_i)++ > 0)
				write(1, " ", 1);
			ft_putstr(lst->str);
			return ;
		}
		lst = lst->next;
	}
}

void	ft_printnumber2(t_dict *lst, int i, int *ptr_i)
{
	while (lst)
	{
		if (i == lst->size)
		{
			if ((*ptr_i)++ > 0)
				write(1, " ", 1);
			ft_putstr(lst->str);
			return ;
		}
		lst = lst->next;
	}
}

void	ft_printnumber3(char c, t_dict *lst, int *ptr_i)
{
	while (lst)
	{
		if (c == lst->nb[0] && lst->nb[1] == '0'
			&& lst->nb[2] == '\0' && c != '0')
		{
			if ((*ptr_i)++ > 0)
				write(1, " ", 1);
			ft_putstr(lst->str);
			return ;
		}
		lst = lst->next;
	}
}

int	ft_iszero(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}
