/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:38:58 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/11 12:38:59 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**board;
	int		solve;

	solve = 0;
	if (argc != 2 || ft_counter(argv[1]) != 1)
		ft_error();
	else
	{
		board = ft_init_tab();
		if (!board)
			ft_error();
		else
		{
			ft_comb(board, argv, 0, &solve);
			if (!solve)
				ft_error();
			ft_delete_board(board);
		}
	}
	return (1);
}
