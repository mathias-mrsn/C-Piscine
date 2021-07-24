/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:15:08 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/01 18:49:15 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int		i;
	int		j;

	i = 0;
	while (dest[i])
		i++;
	j = -1;
	while (src[++j] && nb-- > 0)
		dest[i + j] = src[j];
	dest[i + j] = '\0';
	return (dest);
}
