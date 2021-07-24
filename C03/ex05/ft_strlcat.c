/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:15:25 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/07 15:07:39 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	l;
	unsigned int	i;

	l = 0;
	while (dest[l] && l < size)
		l++;
	i = 0;
	while (src[i] && size && l + i < size - 1)
	{
		dest[l + i] = src[i];
		i++;
	}
	if (l < size)
		dest[l + i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (l + i);
}
