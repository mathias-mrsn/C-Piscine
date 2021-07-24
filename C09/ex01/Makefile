# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mamaurai <mamaurai@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/08 11:12:23 by mamaurai          #+#    #+#              #
#    Updated: 2021/07/08 12:00:13 by mamaurai         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
INCS	=	includes
SRCS	=	srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c \
			srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS	=	${SRCS:.c=.o}
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
LIBC	=	ar rc
LIBR	=	ranlib
RM		=	rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

libft.a:	${OBJS}
			${LIBC} ${NAME} ${OBJS}
			${LIBR} ${NAME}

all:		libft.a

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

