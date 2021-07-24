# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abfall <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/18 19:52:23 by abfall            #+#    #+#              #
#    Updated: 2021/07/18 19:52:27 by abfall           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = rush-02
FILE= ft_convert.c ft_error.c ft_parsing.c ft_print1.c ft_print2.c ft_read.c ft_utils.c ft_utils2.c ft_utils3.c main.c
OBJ=$(FILE:.c=.o)
FLAGS= -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OBJ)
		$(CC) -c $(FLAGS) $(FILE)
		$(CC) $(FLAGS) -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re: 		fclean all
