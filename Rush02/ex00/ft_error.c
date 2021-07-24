/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:52:46 by abfall            #+#    #+#             */
/*   Updated: 2021/07/18 20:25:45 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_strerror(char *str)
{
	if (str)
		free(str);
	write(2, "Dict Error\n", 11);
	return (1);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_parserror(int i, t_dict **dict)
{
	t_dict	*prev;
	t_dict	*next;
	t_dict	*curr;

	prev = 0;
	next = (*dict);
	while (next)
	{
		if (prev == NULL)
			*dict = next->next;
		else
			prev->next = next->next;
		curr = next;
		next = next->next;
		free(curr->str);
		free(curr->nb);
		free(curr);
	}
	if (i == 1)
		write(2, "Dict Error\n", 11);
	if (i == 2)
		write(2, "Error\n", 6);
	return (1);
}
