# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brmasser <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/21 15:11:46 by brmasser          #+#    #+#              #
#    Updated: 2021/07/21 15:11:48 by brmasser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = bsq
FILE= bsq.c ft_algo.c ft_error.c ft_read.c ft_utils.c ft_utils2.c
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

.PHONY : all clean fclean re
