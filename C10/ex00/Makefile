CC = gcc
NAME = ft_display_file
FILE= ft_display_file.c
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
