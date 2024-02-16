NAME	= push_swap
SRC		= push_swap.c command.c arcive.c check.c free.c goal.c helper.c list.c print.c
CC		= gcc	
FLAGS	= -Werror -Wextra -Wall -g

all: NAME

NAME: push_swap.h $(SRC) $(SRC:.c=.o)
	$(CC) $(FLAGS) $(SRC:.c=.o) -o $(NAME)

%.o: %.c
	$(CC) -c $(FLAG) $< -o $@

clean:
	rm -rf *.o

fclean:
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re