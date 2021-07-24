# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/11 10:10:56 by mamaurai          #+#    #+#              #
#    Updated: 2021/07/12 16:56:15 by mamaurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_hexdump 
FILE= ft_hexdump.c ft_utils.c ft_hub.c ft_hexa_with_c.c ft_file_descriptor.c ft_hexa_without_c.c
OBJ=$(FILE:.c=.o)
FLAGS= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
		$(CC) -c $(FLAGS) $(FILE)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)	

re: 		fclean all
