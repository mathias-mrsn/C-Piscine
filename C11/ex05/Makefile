# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaurai <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/11 14:54:46 by mamaurai          #+#    #+#              #
#    Updated: 2021/07/11 14:54:49 by mamaurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = do-op
FILE=do_op.c
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

