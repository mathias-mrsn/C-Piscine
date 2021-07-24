/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:09:27 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/12 08:05:55 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

int	ft_illegal(char *str)
{
	ft_puterror("ft_tail: illegal offset -- ");
	ft_puterror(str);
	ft_puterror("\n");
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	long	option;
	long	size;
	int		first;

	i = 2;
	first = 0;
	if (argc < 3 || !ft_check_option(argv[1], argv[2]))
		return (1);
	option = ft_check_option(argv[1], argv[2]);
	if (option == 0)
		return (1);
	if (option == -1)
		return (ft_illegal(argv[2]));
	if (argc == 3)
		ft_stdin(option, 0);
	while (++i < argc)
	{
		if (ft_can_be_open(argv[i]) && argc > 4)
			ft_print_line_name(argv[i], i, first++);
		size = ft_size_file(argv[i], basename(argv[0]), argv[i]);
		if (size - option > 0 || option >= size)
			ft_display_file(argv[i], size, option);
	}
	return (0);
}
