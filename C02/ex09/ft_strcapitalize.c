/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 08:06:37 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/01 12:53:23 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char c)
{
	if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
			|| (c >= '0' && c <= '9')))
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	*s;

	s = str;
	i = 0;
	while (s[i])
	{
		while (s[i] && !ft_str_is_alpha(s[i]))
			i++;
		if (s[i] && s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
		i += 1;
		while (s[i] && ft_str_is_alpha(s[i]))
		{	
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] += 32;
			i++;
		}
	}
	return (str);
}
