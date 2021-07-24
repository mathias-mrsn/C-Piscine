/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:09:52 by mamaurai          #+#    #+#             */
/*   Updated: 2021/07/12 17:00:22 by mamaurai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <libgen.h>
# include <string.h>
# include <stdlib.h>

typedef struct s_option
{
	unsigned long	files_len;
	unsigned int	size;
	unsigned char	to_print[17];
	unsigned char	save[17];
	unsigned int	argc;
	unsigned int	buffer_size;
	int				fd;
	int				star;
	int				first_file;
}					t_option;

void			ft_bad_file_descriptor(int argc, char **argv, t_option *option);
void			ft_puterror(char *str);
unsigned int	ft_strlcpy(t_option *option);
unsigned char	*ft_strncat(unsigned char *dest,
					unsigned char src, t_option *option);
int				ft_strlen(char *str);
void			init_option(t_option *option, int argc);
int				ft_error(char *basename, char *prog);
int				ft_check_params(int argc, char **argv, t_option *option);
int				ft_strcmp(unsigned char *s1,
					unsigned char *s2, t_option *option);
void			ft_hub(t_option *option, char **argv, int argc);
void			ft_print_hub(t_option *option);
int				ft_check_file_error(int argc, char **argv, t_option *option);
void			ft_stdin(t_option *option);
void			ft_hexdump(t_option *option);
void			ft_putchar(char c);
void			ft_fill_white_space(t_option *option);
void			ft_putaddr(unsigned long size);
void			ft_print_line(t_option *option);
void			ft_printhex(t_option *option);
void			ft_putstr(char *str);
void			ft_c(t_option *option);
void			ft_putaddr_c(unsigned long size);
void			ft_hex_c(t_option *option);
void			ft_fill_white_space_c(t_option *option);
void			ft_without_c(t_option *option);

#endif
