# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/11 10:10:44 by mamaurai          #+#    #+#              #
#    Updated: 2021/07/11 10:10:45 by mamaurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = ft_cat
FILE=ft_cat.c
OBJ=$(FILE:.c=.o)
FLAGS= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
		$(CC) -c $(FLAGS) $(FILE)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)
