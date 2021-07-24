/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:09:35 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/12 08:04:04 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>
# include <stdlib.h>

void			ft_puterror(char *str);
int				ft_error(char *basename, char *prog);
int				ft_can_be_open(char *path);
int				ft_connection(char *str);
long			ft_size_file(char *path, char *basename, char *prog);
int				ft_display_file(char *path, long size, long option);
void			ft_putstr(char *str);
long			ft_atoi(char *str);
long			ft_check_option(char *option, char *val);
void			ft_print_line_name(char *str, int i, int first);
int				ft_display_file(char *path, long size, long option);
unsigned int	ft_strlcpy(unsigned char *dest,
					unsigned char *src, unsigned int size);
long			ft_size_file(char *path, char *basename, char *prog);
int				ft_connection(char *str);
void			ft_stdin(long option, int i);

#endif
