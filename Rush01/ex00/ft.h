/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 12:38:09 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/11 12:38:10 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <stdlib.h>
# include <unistd.h>

int		ft_counter(char *str);
int		ft_checkchar(char **board, char **argv);
int		ft_right_to_left(char **board, char *argv, int arg);
int		ft_left_to_right(char **board, char *argv, int arg);
int		ft_down_to_up(char **board, char *argv, int arg);
int		ft_up_to_down(char **board, char *argv, int arg);
char	**ft_init_tab(void);
int		ft_comb(char **board, char **argv, int pos, int *solve);
void	ft_delete_board(char **tab);
void	ft_print_board(char **tab);
void	ft_error(void);

#endif
