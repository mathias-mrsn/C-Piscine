/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 19:53:59 by abfall            #+#    #+#             */
/*   Updated: 2021/07/18 20:13:47 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_dict
{
	char			*nb;
	char			*str;
	int				size;
	struct s_dict	*next;
}	t_dict;

long	ft_size_file(char *path);
char	*ft_read(char *path);
int		is_space(char c);
int		is_correct(char *str);
int		is_numeric(char c);
void	ft_strcat_num(char **dest, char c);
t_dict	*ft_create_elem(char **nb, char **str, int i, t_dict **dict);
int		is_unprintable(char c);
int		ft_parsing(t_dict **dict, char *str);
int		ft_strlen(char *str);
void	ft_strcat(char **dest, char c);
char	*ft_strdup(char *src);
char	*ft_fill(char *str, int *i);
char	*ft_fill_first(char *str, int f, int *i);
char	**ft_convert(char *str);
void	ft_putstr(char *str);
void	ft_print(char **str, int len, t_dict *lst);
int		ft_strcmp(char *s1, char *s2);
int		ft_check_argv(char *str);
int		ft_strerror(char *str);
int		ft_parserror(int i, t_dict **dict);
void	ft_free_tab(char **tab);
int		ft_check_dup(t_dict *dict);
int		ft_start_at(char *str);
void	ft_printnumber(char c, t_dict *lst, char c2, int *ptr_i);
void	ft_printnumber2(t_dict *lst, int i, int *ptr_i);
void	ft_printnumber3(char c, t_dict *lst, int *ptr_i);
int		ft_iszero(char *str);
void	ft_print_first(char **str, int *i, int *ptr_i, t_dict *lst);
int		ft_print_all(char **str, int *i, int *j, t_dict *lst);
int		ft_print_thousand(char **str, int *i, int *l, t_dict *lst);
int		ft_print_zero(char **str, int *i, int *ptr_i, t_dict *lst);
int		ft_process(char *path, char *arg);
int		ft_check_size(char *str, t_dict	*dict);

#endif
