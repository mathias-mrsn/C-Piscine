/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:53:30 by abfall            #+#    #+#             */
/*   Updated: 2021/07/18 20:20:10 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

t_dict	*ft_create_elem(char **nb, char **str, int i, t_dict **dict)
{
	t_dict	*res;

	res = malloc(sizeof(t_dict) * 1);
	if (!res)
		return (NULL);
	res->nb = ft_strdup((*nb));
	res->str = ft_strdup((*str));
	res->size = i;
	res->next = (*dict);
	(*dict) = res;
	(*nb)[0] = '\0';
	(*str)[0] = '\0';
	return (res);
}

void	ft_strcat_num(char **dest, char c)
{
	int		i;
	char	*new;

	i = 0;
	while ((*dest)[i] && is_numeric((*dest)[i]))
		i++;
	new = malloc(sizeof(char) * (i + 2));
	i = -1;
	while ((*dest)[++i] && is_numeric((*dest)[i]))
		new[i] = (*dest)[i];
	if (is_numeric(c))
		new[i] = c;
	new[i + 1] = '\0';
	free((*dest));
	(*dest) = new;
}

int	ft_start_at(char *str)
{
	int	i;

	i = -1;
	while (str[++i] && str[i] == '0' && str[i + 1] != '\0')
	{
	}
	return (i);
}

int	ft_check_dup(t_dict *dict)
{
	t_dict	*tmp;
	t_dict	*ref;

	ref = dict;
	while (ref)
	{
		tmp = ref->next;
		{
			while (tmp)
			{
				if (!ft_strcmp(tmp->nb, ref->nb))
					return (0);
				tmp = tmp->next;
			}
		}
		ref = ref->next;
	}
	return (1);
}

int	ft_check_size(char *str, t_dict	*dict)
{
	t_dict	*tmp;
	int		max;
	int		len;

	max = 0;
	tmp = dict;
	while (tmp)
	{
		if (max < tmp->size)
			max = tmp->size;
		tmp = tmp->next;
	}
	len = ft_strlen(str);
	if (len <= max + 2)
		return (1);
	return (0);
}
