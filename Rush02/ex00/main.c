/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:53:38 by abfall            #+#    #+#             */
/*   Updated: 2021/07/18 20:32:26 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_process(char *path, char *arg)
{
	t_dict	*dict;
	char	*dict_file;
	int		l;

	dict_file = ft_read(path);
	if (!dict_file)
		return (ft_strerror(dict_file));
	if (!ft_check_argv(arg))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	if (!ft_parsing(&dict, dict_file))
		return (ft_parserror(1, &dict));
	l = ft_start_at(arg);
	if (!dict || !ft_check_dup(dict))
		return (ft_parserror(1, &dict));
	if (!ft_check_size(arg, dict))
		return (ft_parserror(2, &dict));
	ft_print(ft_convert(arg + l), ft_strlen(arg - l), dict);
	ft_parserror(0, &dict);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*dict_file;
	t_dict	*dict;

	dict = 0;
	dict_file = 0;
	if (argc == 1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	else if (argc == 2)
		ft_process("numbers.dict", argv[1]);
	else if (argc == 3)
		ft_process(argv[1], argv[2]);
	return (0);
}
