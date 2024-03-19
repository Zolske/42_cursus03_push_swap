NAME	= pipex
HEADER	= pipex.h libft.h
SRC		= init.c helper.c path.c free.c error.c pipping.c\
		  # print.c # only for testing, file removed
MANDA	= pipex.c
BONUS	= pipex_bonus.c
LIBFT	= libft/libft.a
CC		= cc
FLAGS	= -Werror -Wextra -Wall -g
vpath libft.h libft

all: NAME

NAME: $(HEADER) $(SRC) $(SRC:.c=.o) $(MANDA) $(MANDA:.c=.o) ${LIBFT}
	rm -rf $(NAME_B:.c=.o)
	$(CC) $(FLAGS) $(SRC:.c=.o) $(MANDA:.c=.o) -L./libft -lft -o $(NAME)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) -c $(FLAG) $< -o $@

bonus: $(HEADER) $(SRC) $(SRC:.c=.o) $(BONUS) $(BONUS:.c=.o) ${LIBFT}
	rm -rf $(NAME:.c=.o)
	$(CC) $(FLAGS) $(SRC:.c=.o) $(BONUS:.c=.o) -L./libft -lft -o $(NAME)

clean:
	rm -rf *.o
	make clean -C libft

fclean:
	rm -rf $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
