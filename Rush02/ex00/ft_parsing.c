/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:52:52 by abfall            #+#    #+#             */
/*   Updated: 2021/07/18 20:18:27 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	ft_loop(char *str, char *nb, char *string, t_dict **dict)
{
	size_t	i;

	i = -1;
	while (str[++i])
	{
		while (is_space(str[i]))
			i++;
		while (str[i] && (is_numeric(str[i])))
			ft_strcat_num(&nb, str[i++]);
		while (is_space(str[i]))
			i++;
		if (str[i++] != ':')
			break ;
		while (is_space(str[i]))
			i++;
		while (str[i] && str[i] != '\n')
			ft_strcat(&string, str[i++]);
		if (nb && string)
			ft_create_elem(&nb, &string, ft_strlen(nb), dict);
		else
			break ;
	}
	free(nb);
	free(string);
}

int	ft_parsing(t_dict **dict, char *str)
{
	size_t	i;
	char	*nb;
	char	*string;

	i = 0;
	nb = malloc(sizeof(char) * 1);
	if (!nb)
		i = 1;
	string = malloc(sizeof(char) * 1);
	if (!nb)
		i = 1;
	if (i == 0)
		ft_loop(str, nb, string, dict);
	if (i != 0)
	{
		free(str);
		return (0);
	}
	free(str);
	return (1);
}
