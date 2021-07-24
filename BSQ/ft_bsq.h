/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brmasser <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:11:19 by brmasser          #+#    #+#             */
/*   Updated: 2021/07/22 08:58:41 by brmasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BSQ_H
# define FT_BSQ_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_map
{
	int		**map;
	char	empty;
	char	full;
	char	obstacle;
	int		s_line;
	int		s_col;

	int		solve_x;
	int		solve_y;
	int		solve_size;
}				t_map;

unsigned long	ft_size_file(char *path);
char			*ft_read_file(char *path);
void			ft_init_map(t_map *map);
void			ft_putchar(char c);
int				ft_atoi(char *str);
int				ft_strlen(char *str);
int				is_charset(char c, char *charset);
int				ft_read_header(char *str, t_map	*map);
int				is_map(char c, t_map *map);
void			ft_translate_board(t_map *map, char **str);
void			ft_algoryth(t_map *map);
void			ft_get_solve(t_map *map);
void			ft_print_solve(t_map *map);
int				ft_check_map(char *str, t_map *map, int	first, int curr);
int				ft_split(char *str, t_map *map);
int				ft_error(int i, t_map *map, char *str);
void			ft_free(int	i, t_map *map, char *str);

#endif
