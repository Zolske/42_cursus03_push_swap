NAME	= pipex
HEAD	= pipex.h
SRC		= pipex.c helper.c e_msg.c

CC		= cc
FLAGS	= -Werror -Wextra -Wall -g

all: NAME

NAME: $(HEAD) $(SRC) $(SRC:.c=.o)
	$(CC) $(FLAGS) $(SRC:.c=.o) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAG) $< -o $@

clean:
	rm -rf *.o

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re