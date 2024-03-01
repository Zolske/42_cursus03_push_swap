NAME	= push_swap
SRC		= push_swap.c node.c error_check.c goal.c helper.c co_rotate.c \
		  co_rotate_rev.c co_swap.c co_push.c update_cost_instruc.c \
		  help_cost_instruc.c update_target.c update.c move.c sort.c
CC		= cc
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