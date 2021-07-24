/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 08:38:10 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/06 08:38:11 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = -1;
	while (charset[++i])
		if (charset[i] == c)
			return (1);
	return (0);
}

int	ft_len(char *str, char *charset)
{
	int	i;
	int	len;

	len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] && !is_charset(str[i], charset))
			++len;
		while (str[i] && !is_charset(str[i], charset))
			++i;
	}
	return (len);
}

int	ft_word_len(char *str, char *charset)
{
	int	len;
	int	i;

	len = 0;
	i = -1;
	while (str[++i] && !is_charset(str[i], charset))
		++len;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	while (src[len])
		++len;
	if (size == 0)
		return (len);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		len;
	int		i;
	int		j;

	strs = (char **)malloc(sizeof(char *) * (ft_len(str, charset) + 1));
	if (!strs)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j < ft_len(str, charset))
	{
		while (str[i] && is_charset(str[i], charset))
			++i;
		len = ft_word_len(str + i, charset);
		strs[j] = (char *)malloc(sizeof(char) * len + 1);
		if (!strs[j])
			return (NULL);
		ft_strlcpy(strs[j++], str + i, len + 1);
		i += len;
	}
	strs[j] = NULL;
	return (strs);
}
